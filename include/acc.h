#ifndef ACC_H_
#define ACC_H_

class ACC {
public:
    ACC(double, double);

    void SetPID(double, double, double);

    void ApplyControl(double, double, double);

    double GetAcceleration();

    double GetError();

    double GetErrorSum();

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
    double error_sum;
    double control;

    const double mass=1200.0;
    const double force_peak=mass*3.0;
    const double force_brake_peak=-mass*5.0;
    const double gas_peak_linear_slope=3.33;
    const double brake_peak_linear_slope=0.1;
    const double power_peak=100000;
    const double speed_base=power_peak/force_peak;

    double force_gas;
    double force_brake;
    double force_resistance;
    double force;
};

#endif // ACC_H_
