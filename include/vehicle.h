#ifndef VEHICLE_H_
#define VEHICLE_H_

#include <string>

class Vehicle {
public:
    Vehicle(const std::string);

    void SetInitialPosition(const double);

    void SetInitialSpeed(const double);

    double Dynamics(double, double, double);

    double GetPosition();

    void SetPosition();

    double GetSpeed();

    double GetAcceleration();

    void SetAcceleration(double);

private:
    std::string name;
    const double position0;
    const double speed0;
    double position;
    double speed;
    double acceleration;
    double gas;
    double brake;
    double actual_speed;
};

#endif // VEHICLE_H_
