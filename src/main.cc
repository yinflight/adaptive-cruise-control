#include <iostream>
#include <math.h>
#include <cstdlib>

#include "vehicle.h"
#include "acc.h"

#define SETSPEED    30                  // setpoint ego speed in m/s
#define SETDISTANCE 10                  // minimum distance in m
#define AMPLITUDE   2 
#define CYCLES      5
#define EGOINITPOS  10
#define LEADINITPOS 50
#define EGOINITVEL  20
#define LEADINITVEL 20

int main(int argc, char* argv[]) {

    int SIMDURATION;
    sscanf(std::getenv("DUR"), "%d", &SIMDURATION);

    // initialize vehicles with name, initial position, speed
    Vehicle lead("lead", LEADINITPOS, LEADINITVEL);
    Vehicle ego("ego", EGOINITPOS, EGOINITVEL);

    // initialize the ACC with set values    
    ACC acc(SETSPEED, SETDISTANCE);

    // set PID params through ACC
    acc.SetPID(5,2,3);

    // acceleration bounds for ACC response
    acc.SetBounds(-3, 3);

    // iterate through clk
    for(int i=0; i<SIMDURATION; i++) {

        /* lead: set acc through sin(x), compute vel, compute dist
         * ego: set acc through ACC, compute vel, compute dist
         */

        // update the lead vehicle acceleration through waveform
        lead.UpdateAcceleration(AMPLITUDE*sin(M_PI*CYCLES*i/SIMDURATION), i);

        // decides whether to keep at ego speed or adjust to keep min distance
        // update vehicle states
        ego.UpdateState(acc.ApplyControl(lead.GetPosition(), ego.GetPosition(), ego.GetSpeed()), i);
;


        std::cout << acc.GetError() << "," << acc.GetErrorSum() << "," << lead.GetSpeed() << "," << ego.GetSpeed() << "," << lead.GetAcceleration() << "," << ego.GetAcceleration() << "," << lead.GetPosition() << "," << ego.GetPosition() << "," << abs(lead.GetPosition() - ego.GetPosition()) << std::endl;

    }
}
