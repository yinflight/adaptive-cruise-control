#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

#include "vehicle.h"
#include "pid.h"
#include "acc.h"

 

int main(int argc, char* argv[]) {

    auto lead = new vehicle("lead");
    auto ego = new vehicle("ego");
    auto controller = new PID();

    // setpoints
    int set_speed = 30; // kmh
    int set_distance = 10; // m

    // set PID params
    controller->SetPID(1,1,1);

    // set vehicle params
    lead->SetSpeed(0);
    ego->SetSpeed(0);
    controller->SetSetpoint(set_speed);

    int sim_duration = 60; // duration in seconds
    
    ACC acc(set_speed, set_distance); // initialize with the set values
    


    for(int i=0; i<sim_duration; i++) {
        // check distance between ego and lead
        // evaluate whether it is greater than or less than set_distance 
        // if dist > set_distance -> keep at ego speed
        // if dist < set_distance -> slow down to hit set_distance and set new speed
        // speed is setpoint. if lead is too slow, temp set lower cruise
        // once cruise can be reached, apply PID to speed up
        // evaluate PID dynamically
        // int setpoint = cruise - speed;
        // control = PID(setpoint)
        // if control < 0: brakes, else: gas


    }


}
