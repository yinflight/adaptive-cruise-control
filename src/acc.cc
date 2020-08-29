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
    // set PID controller values
    controller.SetPID(P,I,D);
}

double ACC::ApplyControl(double lead_distance, double ego_distance, double actual_velocity) {
    // computes control values and decides whether to apply gas or brakes
    this->actual_velocity=actual_velocity;

    if(abs(lead_distance-ego_distance) >= set_distance) {
        // minimum distance is not violated
        setpoint = set_velocity;

        // calculate control value
        control = controller.Compute(actual_velocity, setpoint); 

//        std::cout << "!!not violated setpoint: " << setpoint << ", control: " << control << std::endl;

    } else {
        // minimum distance is violated
        // apply brakes proportional to how much dist was violated
//        control = - abs(set_distance - (lead_distance-ego_distance));

        control = controller.Compute(lead_distance-ego_distance, set_distance);

//        std::cout << "!!violated control: " << control << std::endl;
    } 
    return control;
}

double ACC::GetError() {
    error = controller.GetError();
    return error;
}

double ACC::GetErrorSum() {
    error_sum+=controller.GetError();
//    error_sum = controller.GetErrorSum();
    return error_sum;
}
