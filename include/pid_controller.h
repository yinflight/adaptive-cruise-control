#ifndef PID_CONTROLLER_
#define PID_CONTROLLER_

class PIDController {
public:
    PIDController(double, double, double);
    void SetP(double);
    void SetI(double);
    void SetD(double);
    void SetPID(double, double, double);
    void SetSetpoint(double);
    void reset();
    double Compute(double, double);
    double Compute(double);
    double Compute();

private:
    double bound(double, double, double)
    void CheckSigns();
    void init();

    double P;
    double I;
    double D;

    double max_error;
    double error_sum;

    double setpoint;
    double last_actual;

    bool first_run;
    double last_output;
}

#endif // PID_CONTROLLER_
