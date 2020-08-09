#include "pid_controller.h"
#include "utils.h"

// constructor
PIDController::PIDController(double p, double i, double d) {
    init();
    P=p;
    I=i;
    D=d;
}

void PIDController::init() {
    P=0;
    I=0;
    D=0;

    error_sum=0;
    setpoint=0;
    last_actual=0;
    first_run=true;
    last_output=0;
}

// set proportional value
void PIDController::SetP(double p) {
    P=p;
}

// set integral value
void PIDController::SetI(double i) {
    I=i;
}

// set derivative value
void PIDController::SetD(double d) {
    D=d;
}

// set all 3 values
void PIDController::SetPID(double p, double i, double d) {
    P=p;
    I=i;
    D=d;
    F=f;
}


void PIDController::SetSetpoint(double setpoint) {
    this->setpoint=setpoint;
}

double PIDController::Compute(double actual, double setpoint) {
    double output;
    double p_output;
    double i_output;
    double d_output;

    this->setpoint=setpoint;

    double error=setpoint-actual;

    p_output=P*error;

    if(first_run) {
        last_actual=actual;
        last_output=p_output;
        first_run=false;
    }

    d_output=-D*(actual-last_actual);
    last_actual=actual;

    i_output=I*error_sum;

    output=p_output+i_output+d_output;

    error_sum+=error;

    last_output=output;
    return output;
}

double PIDController::Compute() {
    return Compute(last_actual, setpoint);
}

double PIDController::Compute(double actual) {
    return Compute(actual, setpoint);
}
