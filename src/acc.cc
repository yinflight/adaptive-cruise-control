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
    // set PID controller values
    controller.SetPID(P,I,D);
}

double ACC::ApplyControl(double lead_distance, double ego_distance, double actual_speed) {
    // computes control values and decides whether to apply gas or brakes
    this->actual_speed=actual_speed;

    if(abs(lead_distance-ego_distance) >= set_distance) {
        // minimum distance is not violated
        setpoint = set_speed;
        
        // calculate control value
        control = controller.Compute(actual_speed, setpoint); 

    } else {
        // minimum distance is violated
        // apply brakes proportional to how much dist was violated
        control = - abs(set_distance - (lead_distance-ego_distance));
    } 

    return control;

//    if(control>=0) {
//        gas=control;
//        brake=0;
//    } else {
//        gas=0;
//        brake=-control;
//    }
}

//double ACC::GetAcceleration() {
//    // converts control value to acceleration for the vehicle
//
//    // a(t) = control / mass * e ^ (-1 * b / mass)
//
//
//
//
//
//    force_brake = brake * force_brake_peak * brake_peak_linear_slope;
//
//    if(actual_speed<speed_base) {
//        force_gas = gas * force_peak * gas_peak_linear_slope;
//
//    } else {
//        force_gas = gas * power_peak/actual_speed * gas_peak_linear_slope;
//    }
//
//    force = force_gas + force_brake + force_resistance;
//    acceleration = force / mass;
//
//    return acceleration;
//}


double ACC::GetError() {
    error = controller.GetError();
    return error;
}

double ACC::GetErrorSum() {
    error_sum+=controller.GetError();
//    error_sum = controller.GetErrorSum();
    return error_sum;
}

void ACC::SetBounds(double minimum, double maximum) {
    controller.SetOutputLimits(minimum, maximum);
}
