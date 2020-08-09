# Adaptive Cruise Control with PID control
 
Adaptive cruise control (ACC) is a control system that modifies the speed of the ego vehicle in response to conditions on the road. The ACC operates in two modes: speed control and spacing control. The control goal varies depending on which mode is set. The inter-vehicle distance is maintained with a constant value. The goal of the system is to maintain the desired distance without causing a collision, keeping the maximum acceleration and minimum deceleration within specified limits (to guarantee safety etc).

lead vehicle:
* (input) acceleration <= sinusoidal for test purposes
* (input) initial lead vehicle position and velocity <= user set
* (output) actual lead vehicle position and velocity => summing point => ACC

ego vehicle:
* (input) acceleration from ACC <= ACC
* (input) initial ego vehicle position and velocity <= user set
* (output) actual ego vehicle position and velocity => summing point => ACC


ACC: 
* (input) driver set velocity <= user set
* (input) time gap <= user set
* (input) relative distance and velocity (between ego actual and lead actual) <= summing point (external from sensor)
* (input) longitudinal velocity <= ego velocity actual
* (output) longitudinal acceleration => ego vehicle acceleration



## requirements


## usage

to build

`./run.sh --build`

to run

`./run.sh`

## links
* L. Bageshwar, L. Garrard and R. Rajamani "Model predictive control of transitional maneuvers for adaptive cruise control vehicles", IEEE Trans. Veh. Technol., vol. 53, no. 5, pp.1573 -1585 2004
* https://github.com/ajinkya-khade/ACC_Vehicle_MPC/blob/master/ECE.726.-.Project.Report.-.Redacted.pdf
* https://stanford.edu/class/ee364b/lectures/mpc_slides.pdf
