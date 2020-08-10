#ifndef VEHICLE_H_
#define VEHICLE_H_

#include <string>

class vehicle {
public:
    vehicle(const std::string& vehicle_name="") {
        name = vehicle_name;
    }

    void SetSpeed(const double& new_speed) {
        speed = new_speed;
    }

    double const GetSpeed() {
        return speed;
    }

    double const GetPosition() {
        return position;
    }

    void SetPosition(const double& new_position) {
        position = new_position;
    }

private:
    double speed;
    double position;
    std::string name;
};

#endif // VEHICLE_H_
