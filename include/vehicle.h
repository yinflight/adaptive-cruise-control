#ifndef VEHICLE_H_
#define VEHICLE_H_

#include <string>


class vehicle {
public:
    void SetSpeed(const double& new_speed) {
        speed = new_speed;
    }

    double const GetSpeed() {
        return speed;
    }

    void StepSim(double dt);

    double const GetPosition() {
        return position;
    }

    void SetPosition(const double& new_position) {
        position = new_position;
    }

private:
    double speed;
    double position;
};

#endif // VEHICLE_H_
