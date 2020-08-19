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
//    std::cout << "lead distance: " << lead_distance << ", " << "ego distance: " << ego_distance << std::endl;
 //   std::cout << "abs distance: " << abs(lead_distance-ego_distance) << std::endl;
  //  std::cout << "---------------" << std::endl;

    this->actual_speed=actual_speed;

    if(abs(lead_distance-ego_distance) > set_distance) {
        // minimum distance is not violated

//        std::cout << "dist not violated" << std::endl;
        setpoint = set_speed;
        
        // calculate control value
        control = controller.Compute(actual_speed, setpoint); 

    } else {
//        std::cout << "dist violated" << std::endl;
        // minimum distance is violated
        setpoint = abs(set_speed-actual_speed);
        // trigger PID to act around new setpoint
        control = controller.Compute(actual_speed, setpoint);

       

      //  brake = -control;
       // gas = 0;
    } 

//    control = control*0.1;
//    if(control>10) {
 //       control=control*0.1;
//    } else if(control<-10) {
//        control=control*0.1;
 //   }

    if(control>=0) {
        gas=control;
        brake=0;
    } else {
        gas=0;
        brake=-control;
    }

//    std::cout << "setpoint: " << setpoint << ", actual speed: " << actual_speed << ", control -> " << control << std::endl;
 //   std::cout << "gas: " << gas << ", " << "brake: " << brake << std::endl;


}

double ACC::GetAcceleration() {

    force_brake = brake * force_brake_peak * brake_peak_linear_slope;

    if(actual_speed<speed_base) {
        force_gas = gas * force_peak * gas_peak_linear_slope;

    } else {
        force_gas = gas * power_peak/actual_speed * gas_peak_linear_slope;
    }

    force = force_gas + force_brake + force_resistance;
    acceleration = force / mass;
   // std::cout << "acceleration: " << acceleration << std::endl;
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

void ACC::SetBounds(double minimum, double maximum) {
    controller.SetOutputLimits(minimum, maximum);
}
