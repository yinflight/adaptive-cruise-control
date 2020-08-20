#include <iostream>
#include <math.h>
#include <cstdlib>

#include "vehicle.h"
#include "acc.h"

#define SETSPEED    30  // setpoint ego speed in m/s
#define SETDISTANCE 10  // minimum distance in m
#define SIMDURATION 120  // simulation duration in s
#define SCALE       1   // scale factor for lead acceleration sine wave
#define SHIFT       0   // shift factor for lead acceleration sine wave
#define CYCLES      5

int main(int argc, char* argv[]) {

    // initialize vehicles
    Vehicle lead("lead", 10, 30, 0);
    Vehicle ego("ego", 0, 30, 0);

    
    ACC acc(SETSPEED, SETDISTANCE); // initialize with the set values

    // set PID params through ACC
    // 0.15, 0.1, 0.0
    acc.SetPID(1,0.0,0.0);

    acc.SetBounds(-20, 20);

    // iterate through clk
    for(int i=0; i<SIMDURATION; i++) {


        lead.UpdateState(SCALE*sin(M_PI*CYCLES*i/SIMDURATION)+SHIFT); // updates from waveform

        // checks distance between ego and lead
        // decides whether to keep at ego speed or adjust to keep min distance
        acc.ApplyControl(lead.GetPosition(), ego.GetPosition(), ego.GetSpeed());

        // update vehicle states
        ego.UpdateState(acc.GetAcceleration()); // updates from ACC based on applied control

//        std::cout << lead.GetSpeed() << "," << ego.GetSpeed() << "," << lead.GetAcceleration() << "," << ego.GetAcceleration() << "," << distance << std::endl;


//        std::cout << "after state update" << std::endl;
 //       std::cout << "ego.GetSpeed(): " << ego.GetSpeed() << " lead.GetSpeed(): " << lead.GetSpeed() << std::endl;

        std::cout << acc.GetError() << "," << acc.GetErrorSum() << "," << lead.GetSpeed() << "," << ego.GetSpeed() << "," << lead.GetAcceleration() << "," << ego.GetAcceleration() << "," << lead.GetPosition() << "," << ego.GetPosition() << std::endl;

    }
}
