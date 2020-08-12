#include <iostream>
#include <math.h>
#include <cstdlib>

#include "vehicle.h"
#include "acc.h"

#define SETSPEED    30  // setpoint ego speed in m/s
#define SETDISTANCE 10  // minimum distance in m
#define SIMDURATION 60  // simulation duration in s


int main(int argc, char* argv[]) {

    // initialize vehicles
    Vehicle lead("lead", 30, 15);
    Vehicle ego("ego", 20, 0);

//    auto lead = new vehicle("lead"); // init lead vehicle
//    auto ego = new vehicle("ego"); // init ego vehicle

    // intialize setpoiubts
//    int set_speed = 30; // kmh, try to not vary from this
 //   int set_distance = 10; // m, min distance between ego and lead

    // set vehicle initial conditions
//    lead.SetInitialSpeed(30); // kmh
 //   lead.SetInitialPosition(15); // m from origin

//    ego.SetInitialSpeed(20); // kmh
//    ego.SetInitialPosition(0); // m from origin


    const int distance = abs(lead.GetPosition()-ego.GetPosition());
    
    ACC acc(SETSPEED, SETDISTANCE); // initialize with the set values

    // set PID params through ACC
    acc.SetPID(1,1,1);

    // empty vector for sinusoidal waveform
//    vector<int> sinusoid;
    
    // iterate through clk
    for(int i=0; i<SIMDURATION; i++) {

        // checks distance between ego and lead
        // decides whether to keep at ego speed or adjust to keep min distance
        acc.ApplyControl(lead.GetPosition(), ego.GetPosition(), ego.GetSpeed());

        // update vehicle states
        ego.UpdateState(acc.GetAcceleration()); // updates from ACC based on applied control
        lead.UpdateState(int(20*sin(i))); // updates from waveform

        std::cout << acc.GetError() << "," << acc.GetErrorSum() << "," << lead.GetSpeed() << "," << ego.GetSpeed() << "," << lead.GetAcceleration() << "," << ego.GetAcceleration() << "," << distance << std::endl;


    }
}
