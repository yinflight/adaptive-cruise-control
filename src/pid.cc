#include "pid.h"

// constructor
PID::PID(double P, double I, double D) { }

// initialize PID values
void PID::init() {
    P=0;
    I=0;
    D=0;

    max_error=0;
    error_sum=0;
    max_output=0;
    min_output=0;
    setpoint=0;
    last_actual=0;
    last_output=0;
    first_run=true;
}

// set proportional value
void PID::SetP(double P) {
    this->P=P;
}

// set integral value
void PID::SetI(double I) {
    this->I=I;
}

// set derivative value
void PID::SetD(double D) {
    this->D=D;
}

// set all 3 values
void PID::SetPID(double P, double I, double D) {
    this->P=P;
    this->I=I;
    this->D=D;
}

// set setpoint value
void PID::SetSetpoint(double setpoint) {
    this->setpoint=setpoint;
}

// set limits for output
void PID::SetOutputLimits(double minimum, double maximum) {
    max_output=maximum;
    min_output=minimum;
} 

// computing errors
double PID::Compute(double actual, double setpoint) {
    double output;
    double p_output;
    double i_output;
    double d_output;

    this->setpoint=setpoint;

    double error=setpoint-actual; // error

    // proportional error
    p_output=P*error; // P * current error

    if(first_run) {
        last_actual=actual;
        last_output=p_output;
        first_run=false;
    }

    // integral error
    i_output=I*error_sum; // I * total error (error integral)

    // derivative error
    d_output=-D*(actual-last_actual); // D * change in error
    last_actual=actual;

    // total output value
    output=p_output+i_output+d_output;

    // error sum computing
    if(min_output!=max_output && !CheckBounds(output, min_output, max_output)) {
        error_sum=error;;
    } else {
        error_sum+=error;
    }

    last_output=output;
    return output;
}

// compute with no arguments
double PID::Compute() {
    return Compute(last_actual, setpoint);
}

// compute with only actual
double PID::Compute(double actual) {
    return Compute(actual, setpoint);
}

// check the value is within provided bouds
bool PID::CheckBounds(double value, double min_val, double max_val) {
    return (min_val<value) && (value<max_val);
}

// check all values are positive
void PID::CheckSigns() {
    if(P<0) P*=-1;
    if(I<0) I*=-1;
    if(D<0) D*=-1;
}
