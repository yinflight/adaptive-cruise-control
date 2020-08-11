# Adaptive Cruise Control with PID control
 
Adaptive cruise control (ACC) is a control system that modifies the speed of the ego vehicle in response to conditions on the road. The ACC operates in two modes: speed control and spacing control. The control goal varies depending on which mode is set. The inter-vehicle distance is maintained with a constant value. The goal of the system is to maintain the desired distance without causing a collision, keeping the maximum acceleration and minimum deceleration within specified limits (to guarantee safety etc).

## file structure

```
.
├── CMakeLists.txt
├── README.md
├── include
│   ├── acc.h
│   ├── pid.h
│   └── vehicle.h
├── plots               -> directory where the plots will be saved to
├── run.sh              -> script to run, build, or both
├── src
│   ├── acc.cc          -> adaptive cruise control: chooses when to adjust speed, applies PID control
│   ├── main.cc         -> runs simulator and the adaptive cruise control for a vehicle
│   ├── pid.cc          -> PID controller
│   └── vehicle.cc      -> vehicle dynamics and parameters
└── tests
    ├── main.py         -> plots the data read from stdout from the executable
    └── plot.py         -> plot handler
```


## vehicle
`vehicle.h` sets the vehicle parameters such as speed, acceleration, and physical properties.

`ego->SetAcceleration(ACC->GetAcceleration[i]);` sets input acceleration from ACC response at a given tick.

`lead->SetAcceleration(sinusoid[i]);` sets input acceleration from a sinusoidal waveform at a given tick.

lead vehicle:
* (input) acceleration <= sinusoidal for test purposes
* (input) initial lead vehicle position and velocity <= user set
* (output) actual lead vehicle position and velocity => summing point => ACC

ego vehicle:
* (input) acceleration from ACC <= ACC computes from actual speed
* (input) initial ego vehicle position and velocity <= user set
* (output) actual ego vehicle position and velocity => summing point => ACC

## PID
`pid.h` sets the PID controller parameters and computes the response to set speed around speed setpoint.

`controller->SetPID(1,1,1);` sets proportional, integral, and derivative values to all unity, respectively. They can be set individually.

This is handled by the ACC.

## ACC
`acc.h` controls the ego acceleration, keeping the speed around the setpoint with the PID controller whilst maintaining minimum distance. This minimum distance is a constant value that must not be violated. If it is, then the ego vehicle must set a new speed setpoint at minimum distance range. The brake would be applied each tick until safe distance is reached. 

ACC: 
* (input) driver set velocity <= user set
* (input) relative distance and velocity (between ego actual and lead actual) <= summing point (external from sensor)
* (input) longitudinal velocity <= ego velocity actual
* (output) longitudinal acceleration => ego vehicle acceleration


## requirements

Eigen

numpy
matplotlib

## usage

to build

`./run.sh --build`

to run

`./run.sh --run`

to both

`./run.sh`

This will run the simulator for the ego and lead vehicle with adaptive cruise control applied for the former. A sinusoidal acceleration is applied to the lead vehicle to elicit a response from the ego vehicle. The output is piped to a python file for processing and plotting. These files will be saved in the plots directory.


## links
* L. Bageshwar, L. Garrard and R. Rajamani "Model predictive control of transitional maneuvers for adaptive cruise control vehicles", IEEE Trans. Veh. Technol., vol. 53, no. 5, pp.1573 -1585 2004
* https://github.com/ajinkya-khade/ACC_Vehicle_MPC/blob/master/ECE.726.-.Project.Report.-.Redacted.pdf
* https://stanford.edu/class/ee364b/lectures/mpc_slides.pdf
