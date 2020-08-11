#include "vehicle.h"
#include <string>

// init and set vehicle name
Vehicle::Vehicle(const std::string& name="") {
    this->name=name;
} 

// sets initial position in global reference frame
void Vehicle::SetInitialPosition(const double position0) {
    position=position0;
}

// sets initial speed
void Vehicle::SetInitialSpeed(const double speed0) {
    speed=speed0;
}

// computes acceleration from ACC values
double Vehicle::Dynamics(double actual_speed, double gas, double brake) {
    const double g=9.81;
    const double mass=1200.0;

    // determine acceleration from speed, gas, brake, and vehicle dynamics

}

// get vehicle position in global reference frame
double Vehicle::GetPosition() {
    return position;
}

// synchronizes vehicle sim clock with actual sim clock
void Vehicle::SetPosition() {
    // use the given speed value to compute a distance traveled value
    // distance+=speed*1; // applies speed value for 1 second

}

// get vehicle speed
double Vehicle::GetSpeed() {
    return speed;
}

// get vehicle acceleration
double Vehicle::GetAcceleration() {
    return acceleration;
}

// set vehicle acceleration 
void Vehicle::SetAcceleration(double acceleration) {
    this->acceleration=acceleration;
}
