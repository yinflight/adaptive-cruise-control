#include <iostream>
#include <cstdlib>
#include <math.h>
#include "acc.h"
#include "pid.h"
#include "vehicle.h"

PID controller;
Vehicle Vehicle();

ACC::ACC(double set_speed, double set_distance) { 
    this->set_speed=set_speed;
    this->set_distance=set_distance;
}

void ACC::SetPID(double P, double I, double D) {
    controller.SetPID(P,I,D);
}

void ACC::ApplyControl(double lead_distance, double ego_distance, double actual_speed) {
    if(abs(lead_distance-ego_distance) > set_distance) {
        // minimum distance is not violated
        setpoint = set_speed;
        // calculate control value
        control = controller.Compute(actual_speed, setpoint); 
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
        control = controller.Compute(actual_speed, setpoint);

        brake = -control;
        gas = 0;
    }
}

double ACC::GetAcceleration() {

    force_gas = gas * force_peak * gas_peak_linear_slope;

    force_brake = brake * force_brake_peak * brake_peak_linear_slope;

    force_resistance = -(rolling_res * mass * g + 1/2 * pow(actual_speed,2) * aero_cd*rho);

    force = force_gas + force_brake + force_resistance;
    acceleration = force / mass;
    return acceleration;
}


double ACC::GetError() {
    error = controller.GetError();
    return error;
}

double ACC::GetErrorSum() {
    error_sum = controller.GetErrorSum();
    return error_sum;
}
