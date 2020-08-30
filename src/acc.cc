#include <iostream>
#include <cstdlib>
#include <math.h>
#include "acc.h"
#include "pid.h"
#include "vehicle.h"

PID controller;
Vehicle Vehicle();

ACC::ACC(double set_velocity, double set_distance) { 
    this->set_velocity=set_velocity;
    this->set_distance=set_distance;
}

void ACC::SetPID(double P, double I, double D) {
    controller.SetPID(P,I,D);
}

double ACC::ApplyControl(double lead_distance, double ego_distance, double actual_velocity) {
    // computes control values and decides whether to apply gas or brakes
    this->actual_velocity=actual_velocity;

    if(lead_distance-ego_distance >= set_distance) {
        // minimum distance is not violated
        setpoint = set_velocity;

        control = controller.Compute(actual_velocity, setpoint); 

    } else {
        // minimum distance is violated
        if(lead_distance-ego_distance <= 4){
            // collided with the lead car
            control = -controller.Compute(0, set_distance);
        } else {
            // no collision
            control = -controller.Compute(lead_distance-ego_distance, set_distance);
        }
    } 
    return control;
}

double ACC::GetError() {
    error = controller.GetError();
    return error;
}

double ACC::GetErrorSum() {
    error_sum+=controller.GetError();
    return error_sum;
}
