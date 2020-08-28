#include "vehicle.h"
#include <iostream>
#include <string>
#include <math.h>

// construct and set vehicle name
Vehicle::Vehicle(const std::string& name, const double position0, const double speed0) {
    this->name=name;
    position=position0;
    speed=speed0;
} 

// get vehicle position in global reference frame
double Vehicle::GetPosition() {
    return position;
}

// synchronizes vehicle sim clock with actual sim clock
void Vehicle::UpdateState(double control, int clk) {

    // a(t) = u / m * e ^ (-t * b / m)
    // v(t) = u / b * (1 - e ^ (-t * b / m)
    
    acceleration = control / mass * exp(-clk * b / mass);
    speed = control / b * (1 - exp(-clk * b / mass));

//    speed+= 1 * acceleration;

    // integrates speed over 1 tick
//    position+= 1 * speed;
    position = clk * speed;
}

// get vehicle speed
double Vehicle::GetSpeed() {
    return speed;
}

// get vehicle acceleration
double Vehicle::GetAcceleration() {
    return acceleration;
}
