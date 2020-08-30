#include <iostream>
#include <math.h>
#include <cstdlib>

#include "vehicle.h"
#include "acc.h"

#define SETVELOCITY 30      // setpoint ego speed in m/s
#define SETDISTANCE 10      // minimum distance in m
#define AMPLITUDE   2       // lead acceleration amplitude
#define CYCLES      5       // lead acceleration cycles
#define EGOINITPOS  10      // initial ego position
#define LEADINITPOS 50      // initial lead position
#define EGOINITVEL  20      // initial ego velocity
#define LEADINITVEL 20      // initial lead velocity

int main(int argc, char* argv[]) {

    int SIMDURATION;
    sscanf(std::getenv("DUR"), "%d", &SIMDURATION);

    // initialize vehicles with name, initial position, velocity
    Vehicle lead("lead", LEADINITPOS, LEADINITVEL);
    Vehicle ego("ego", EGOINITPOS, EGOINITVEL);

    // initialize the ACC with setpoints
    ACC acc(SETVELOCITY, SETDISTANCE);

    // set PID params through ACC
    acc.SetPID(80,10,10);

    // acceleration bounds
    ego.SetBounds(-3, 3);

    // iterate through clk
    for(int i=0; i<SIMDURATION; i++) {

        /* lead: set acc through sin(x), compute vel, compute dist
         * ego: set acc through ACC, compute vel, compute dist
         */

        double j = i/5.0;

        // update the lead vehicle acceleration through waveform
        lead.UpdateStateManual(AMPLITUDE*sin(M_PI*CYCLES*i/SIMDURATION));

        // decides whether to keep at ego speed or adjust to keep min distance
        // update vehicle states
        ego.UpdateState(acc.ApplyControl(lead.GetPosition(), ego.GetPosition(), ego.GetVelocity()));
;

        std::cout << acc.GetError() << "," << acc.GetErrorSum() << "," << lead.GetVelocity() << "," << ego.GetVelocity() << "," << lead.GetAcceleration() << "," << ego.GetAcceleration() << "," << lead.GetPosition() << "," << ego.GetPosition() << "," << lead.GetPosition() - ego.GetPosition() << std::endl;

    }
}
