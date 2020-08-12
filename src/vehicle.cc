#include "vehicle.h"
#include <string>
#include <math.h>

// construct and set vehicle name
Vehicle::Vehicle(const std::string& name, const double position0, const double speed0) {
    this->name=name;
    position=position0;
    speed=speed0;
} 

/*
// sets initial position in global reference frame
void Vehicle::SetInitialPosition(double position0) {
    position=position0;
}

// sets initial speed
void Vehicle::SetInitialSpeed(double speed0) {
    speed=speed0;
}

*/
// get vehicle position in global reference frame
double Vehicle::GetPosition() {
    return position;
}

// synchronizes vehicle sim clock with actual sim clock
void Vehicle::UpdateState(double acceleration) {
    this->acceleration=acceleration;

    speed+= 1 * acceleration; // increments by tick duration * acceleration

    position+=(speed*1 + 0.5 * acceleration * pow(1,2));
    // use the given speed value to compute a distance traveled value
    // distance+=speed*1; // applies speed value for 1 second
    // find speed from acceleration

}

// get vehicle speed
double Vehicle::GetSpeed() {
    return speed;
}

// get vehicle acceleration
double Vehicle::GetAcceleration() {
    return acceleration;
}
