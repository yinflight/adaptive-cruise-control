#include <iostream>
#include <vector>

#include "vehicle.h"
#include "pid.h"
#include "acc.h"


int main(int argc, char* argv[]) {

    // initialize vehicles
    lead vehicle("lead");
    ego vehicle("ego");

//    auto lead = new vehicle("lead"); // init lead vehicle
//    auto ego = new vehicle("ego"); // init ego vehicle

    // intialize setpoiubts
    int set_speed = 30; // kmh, try to not vary from this
    int set_distance = 10; // m, min distance between ego and lead

    // set vehicle initial conditions
    lead.SetInitialSpeed(30); // kmh
    lead.SetInitialPosition(15); // m from origin

    ego.SetInitialSpeed(20); // kmh
    ego.SetInitialPosition(0); // m from origin

    int sim_duration = 60; // duration in seconds
    
    ACC acc(set_speed, set_distance); // initialize with the set values

    // set PID params through ACC
    acc.SetPID(1,1,1);

    // empty vector for sinusoidal waveform
    vector<int> sinusoid;
    
    // iterate through clk
    for(int i=0; i<sim_duration; i++) {

        // generate sinusoidal wave for lead acceleration
        sinusoid.push_back(int(20*sin(i)));

        // checks distance between ego and lead
        // decides whether to keep at ego speed or adjust to keep min distance
        acc.Evaluate(lead.GetPosition, ego.GetPosition, ego.GetSpeed);

        // update vehicle states
        // ego.SetAcceleration(acc.GetAcceleration); // updates from ACC
        // lead.SetAcceleration(sinusoid[i]); // updates from waveform
        // ego.SetPosition(); // update position with global clock
        // lead.SetPosition(); // update position with global clock

        // std::cout << acc.GetError() << "," << lead.GetSpeed() << "," << ego.GetSpeed() << "," << lead.GetAcceleration() << "," << ego.GetAcceleration() << "," << abs(elead.GetPosition-ego.GetPosition) << std::endl;

    }
}
