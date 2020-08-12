#ifndef VEHICLE_H_
#define VEHICLE_H_

#include <string>

class Vehicle {
public:
    Vehicle(const std::string&, const double, const double);

    double GetPosition();

    void UpdateState(double);

    double GetSpeed();

    double GetAcceleration();

private:
    std::string name;
    double position0;
    double speed0;
    double position;
    double speed;
    double acceleration;
    double gas;
    double brake;
    double actual_speed;
};

#endif // VEHICLE_H_
