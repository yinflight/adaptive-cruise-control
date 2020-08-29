#ifndef ACC_H_
#define ACC_H_

class ACC {
public:
    ACC(double, double);

    void SetPID(double, double, double);

    double ApplyControl(double, double, double);

    double GetError();

    double GetErrorSum();
    
    void SetBounds(double, double);

private:
    double set_velocity;
    double set_distance;
    double P;
    double I;
    double D;
    double lead_distance;
    double ego_distance;
    double actual_velocity;
    double setpoint;
    double error;
    double error_sum;
    double control;
    double minimum;
    double maximum;
};

#endif // ACC_H_
