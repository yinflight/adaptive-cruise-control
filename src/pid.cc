#include "pid.h"
#include <iostream>

// constructor
PID::PID() {
    P=0;
    I=0;
    D=0;

    error_sum=0;
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

// computing errors
double PID::Compute(double actual, double setpoint) {
    double output;
    double p_output;
    double i_output;
    double d_output;

    this->setpoint=setpoint;

    double error=setpoint-actual; // error
    this->error=error;

    error_sum+=error;

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

    last_output=output;
    return output;
}

double PID::GetError() {
    return error;
}
