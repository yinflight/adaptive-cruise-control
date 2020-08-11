#ifndef ACC_H_
#define ACC_H_

Class ACC {
public:
    ACC(double, double);

    void SetPID(double, double, double);

    void Evaluate(double, double, double, double);

    double GetAcceleration();

    double GetError();

private:
    double set_speed;
    double set_distance;
    double P;
    double I;
    double D;
    double lead_distance;
    double ego_distance;
    double actual_speed;
    double gas;
    double brake;
    double setpoint;
    double acceleration;
    double error;
};

#endif // ACC_H_
