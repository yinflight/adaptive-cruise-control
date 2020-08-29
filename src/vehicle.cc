#include "vehicle.h"
#include <iostream>
#include <string>
#include <math.h>

// construct and set vehicle name
Vehicle::Vehicle(const std::string& name, const double& position0, const double& velocity0) : name(name), position(position0), velocity(velocity0) {
//    std::cout << "[veh]: " << name << ", init vel: " << velocity << ", init pos: " << position << std::endl;
} 

// get vehicle position in global reference frame
double Vehicle::GetPosition() {
    return position;
}

// updates the vehicle acceleration, velocity, position with control input
void Vehicle::UpdateState(const double& control) {
    this->control=control;

    // control is either brake force or gas force
    // F = ma rearranged with Fcontrol, Fdrag, Ffriction
    acceleration = 1/mass * (control - 0.5*rho*pow(velocity,2)*A*Cd - Crr*mass*g);

    // check if acceleration bounds are violated
    if(!CheckBounds(acceleration)) {
        if(acceleration>=0) {
            acceleration = maximum;
//            std::cout << "bounds violated - max at " << acceleration << std::endl;
        } else {
            acceleration = minimum;
//            std::cout << "bounds violated - min at " << acceleration << std::endl;
        }
    }

    // v = v + a * dt
    velocity += acceleration * 1;

    // p = p + v * dt
    position += velocity * 1;

//    std::cout << "[veh]: " << name << ", acc: " << acceleration << ", vel: " << velocity << ", pos: " << position << std::endl;
}

// manually sets acceleration
void Vehicle::UpdateStateManual(double acceleration) {
    this->acceleration=acceleration;

    velocity += acceleration * 1;
    position += velocity * 1;

//    std::cout << "[veh]: " << name << ", acc: " << acceleration << ", vel: " << velocity << ", pos: " << position << std::endl;

}

// get vehicle velocity 
double Vehicle::GetVelocity() {
    return velocity;
}

// get vehicle acceleration
double Vehicle::GetAcceleration() {
    return acceleration;
}

void Vehicle::SetBounds(int minimum, int maximum) {
    this->minimum=minimum;
    this->maximum=maximum;
}

bool Vehicle::CheckBounds(const double& acceleration) {
    if(maximum > acceleration && minimum < acceleration) {
        return true;
    } else {
        return false;
    }
}
