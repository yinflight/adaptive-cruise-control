#ifndef VEHICLE_H_
#define VEHICLE_H_

#include <string>

class Vehicle {
public:
    Vehicle(const std::string&, const double&, const double&);

    double GetPosition();

    void UpdateState(const double&);

    void UpdateStateManual(double);

    double GetVelocity();

    double GetAcceleration();

    void SetBounds(int, int);

    bool CheckBounds(const double&);

private:
    std::string name;

    double position0;     // initial position (m)
    double velocity0;     // initial velocity (m/s)
    double position; 
    double velocity;
    double acceleration;        // m/s^2
    double control;             // value output from the controller

    int minimum;
    int maximum;

    // vehicle parameters
    const double mass = 1200;   // vehicle mass, (kg)
    const double Cd = 0.3;      // coefficient of drag
    const double rho = 1.225;   // air density (kg/m^3)
    const double A = 2.2;       // frontal vehicle area (m^2)
    const double g = 9.81;      // gravitational acceleration (m/s^2)
    const double Crr = 0.01;    // rolling resistance coefficient 

};

#endif // VEHICLE_H_
