#ifndef VEHICLE_H_
#define VEHICLE_H_

#include <string>

class Vehicle {
public:
    Vehicle(const std::string&, const double, const double);

    double GetPosition();

    void UpdateState(double, int);

    double GetSpeed();

    double GetAcceleration();

private:
    std::string name;
    double position0; // m
    double speed0; // m/s
    double position; 
    double speed;
    double acceleration;  // m/s^2
    double control;
    int clk;
    const double mass = 1200; // kg
    const double b = 26; // Ns/m
};

#endif // VEHICLE_H_
