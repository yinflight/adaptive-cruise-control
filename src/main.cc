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

    const int distance = abs(lead.GetPosition()-ego.GetPosition());
    
    ACC acc(SETSPEED, SETDISTANCE); // initialize with the set values

    // set PID params through ACC
    acc.SetPID(1,1,1);

    // iterate through clk
    for(int i=0; i<SIMDURATION; i++) {

        // checks distance between ego and lead
        // decides whether to keep at ego speed or adjust to keep min distance
        acc.ApplyControl(lead.GetPosition(), ego.GetPosition(), ego.GetSpeed());

        // update vehicle states
        ego.UpdateState(acc.GetAcceleration()); // updates from ACC based on applied control
        lead.UpdateState(int(2*sin(i)+2)); // updates from waveform

        std::cout << acc.GetError() << "," << acc.GetErrorSum() << "," << lead.GetSpeed() << "," << ego.GetSpeed() << "," << lead.GetAcceleration() << "," << ego.GetAcceleration() << "," << distance << std::endl;

    }
}
