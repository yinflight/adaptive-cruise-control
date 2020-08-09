#include <iostream>
#include <thread>
#include <chrono>

#include "vehicle.h"
#include "pid_controller.h"


/* 
 * run PID controller each tick
 * sim sleep for a tick
 * run sim -> vehicle type, pid controller type void Sim(vehicle* lead, vehicle* ego, pid* controller);
 * main -> duration to run sim, init vehicles, set speeds, set pid values, run threads, output values, destruct
 *
 *
 *
 *
 *
 *
 *
 *
 */ 

int sim_dur; // duration of simulation in milliseconds
double vehicle_dist; // distance between vehicles
bool active; // wether sim is active or not
double tick = 0.001;
double sim_tick = 0.01;

void SimSleep(double seconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds((int)(1000*seconds)));
}


void RunController(pid* contoller) {
    // run controller for duration of sim
    while (active) {
        controller->PIDTick(tick);
        SimSleep(tick);
    }
}

void RunSim(vehicle* lead_vehicle, vehicle* ego_vehicle, pid* controller) {


}
