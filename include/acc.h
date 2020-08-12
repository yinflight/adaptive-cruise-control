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

    const double g=9.81;
    const double mass=1200.0;
    const double rho=1.225;
    const double rolling_res=0.01;
    const double aero_cd=0.3;
    const double force_brake_peak=mass*3.0;
    const double gas_peak_linear_slope=3.33;
    const double brake_peak_linear_slope=0.2;

    double force_gas;
    double force_peak;
    double force_brake;
    double force_resistance;
    double force;
};

#endif // ACC_H_
