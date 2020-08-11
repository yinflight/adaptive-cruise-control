#include <iostream>
#include <cstdlib>
#include "acc.h"
#include "pid.h"
#include "vehicle.h"

controller PID();
vehicle Vehicle();

ACC::ACC(double set_speed, double set_distance) { 
    this->set_speed=set_speed;
    this->set_distance=set_distance;
}

void ACC::SetPID(double P, double I, double D) {
    controller.SetPID(P,I,D);
}

void ACC::Evaluate(double lead_distance, double ego_distance, double actual_speed) {
    if(abs(lead_distance-ego_distance) > set_distance) {
        // minimum distance is not violated
        setpoint = set_speed;
        // calculate control value
        control << PID::Compute(actual_speed, setpoint); 
        if(actual_speed>set_speed) {
            // slow down a bit
            brake = -control;
            gas = 0;
        } else {
            // speed up a bit
            gas = control;
            brake = 0;
        }
    } else {
        // minimum distance is violated
        setpoint = abs(set_speed-actual_speed);
        // trigger PID to act around new setpoint
        control << controller.Compute(actual_speed, setpoint);

        brake = -control;
        gas = 0;
}

double ACC::GetAcceleration() {
    acceleration << vehicle.Dynamics(actual_speed, gas, brake);
    return acceleration;
}

double ACC:GetError() {
    error << controller.GetError();
    return error;
}

/*double ACC:GetDistance() {
    double distance=abs(lead_distance-ego_distance);
    return distance;
}*/
