#ifndef PID_H_
#define PID_H_

class PID {
public:
    PID();
    void SetP(double); // set P value
    void SetI(double); // set I value
    void SetD(double); // set D value
    void SetPID(double, double, double); // set all 3
    void SetSetpoint(double);
    void SetOutputLimits(double, double);
    double Compute(); // compute error term
    double Compute(double);
    double Compute(double, double);
    double GetError();
    double GetErrorSum();
   
private:
    bool CheckBounds(double, double, double);
    double P;
    double I;
    double D;

    double max_error;
    double error_sum;
    double error;

    double max_output;
    double min_output;

    double setpoint;

    double last_actual; // last actual output
    double last_output; // last output

    bool first_run; // whether its first run

};

#endif // PID_H_
