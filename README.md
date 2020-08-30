# Adaptive Cruise Control with PID control
 
Adaptive cruise control (ACC) is a control system that modifies the speed of the ego vehicle in response to conditions on the road. The ACC operates in two modes: speed control and spacing control. The control goal varies depending on which mode is set. The inter-vehicle distance is maintained with a constant value. The goal of the system is to maintain the desired distance without causing a collision, keeping the maximum acceleration and minimum deceleration within specified limits (to guarantee safety etc).

I have a more thorough explanation of the model, controller, and the code as a whole on my blog post here. But here are the results with P=80, I=10, D=10.


<p align="center"><img src="https://raw.githubusercontent.com/onlycase/adaptive-cruise-control/master/plots/vel-acc-responses.png"/></p>

The lead vehicle acceleration is driven by a sinusoid, which in turn drives the velocity. The ego vehicle oscillates somewhat but converges on the cruise setpoint although it is quite slow.

<p align="center"><img src="https://raw.githubusercontent.com/onlycase/adaptive-cruise-control/master/plots/distance.png"/></p>

Observing the distance traveled from the origin, the area between the curves at any instantaneous point signifies their distance. At the points where the curves seem to touch, the distance was nearly violated and the adaptive cruise controller responded. The second plot oscillates as the lead vehicle tends to do so.

<p align="center"><img src="https://raw.githubusercontent.com/onlycase/adaptive-cruise-control/master/plots/error.png"/></p>

The error values drive the PID output. Ideally the error converges to zero and the error accumulation should reduce in growth over time, as observed.


## file structure

```
.
├── CMakeLists.txt
├── README.md
├── include
│   ├── acc.h       -> computes control response from PID controller
│   ├── pid.h       -> PID controller
│   └── vehicle.h   -> applies control reponse with vehicle dynamics
├── plots           -> directory where plots are generated
├── run.sh          -> main script to run with args
├── src
│   ├── acc.cc
│   ├── main.cc
│   ├── pid.cc
│   └── vehicle.cc
└── tests
    └── main.py     -> plotting tools (with matplotlib)
```

## how it works

The lead vehicle acceleration is computed from a sinusoid, and the velocity and position are computed with Vehicle::UpdateStateManual().

The ego vehicle acceleration is computed taking the velocity and control output into consideration. The control output acts to either maintain the velocity setpoint or distance setpoint. If the distance > set distance, velocity setpoint is maintained. If distance is violated, the controller immediately acts to remedy the situation and decelerate until distance is no longer violated. From this acceleration, the velocity and position are computed with Vehicle::UpdateState(). Acceleration bounds are checked to ensure the rapid deceleration is not too high.

At the moment, the response isn't quite correct. The PID values need to be tuned more.


## requirements

Eigen

numpy
matplotlib

## usage

The simulation duration must be set as an environment variable as its used within the C++ source code and the python plotting scripts. To export a duration of 30s,

```
export DUR=400
```

to build

`./run.sh -t build`

to run

`./run.sh -t run`

to both

`./run.sh -t all`

Tested on macOS 10.15

## to do
* checks if environment variable is not present
* checks if other values arent set

## links
* L. Bageshwar, L. Garrard and R. Rajamani "Model predictive control of transitional maneuvers for adaptive cruise control vehicles", IEEE Trans. Veh. Technol., vol. 53, no. 5, pp.1573 -1585 2004
* https://github.com/ajinkya-khade/ACC_Vehicle_MPC/blob/master/ECE.726.-.Project.Report.-.Redacted.pdf
* https://stanford.edu/class/ee364b/lectures/mpc_slides.pdf
* https://asawicki.info/Mirror/Car%20Physics%20for%20Games/Car%20Physics%20for%20Games.html


## user feedback

(back when the velocity response was insanely high)

"I used my error-ridden TomCo Brand cruise control and reached Mach 1.5 on my way to the market, which is 5 mins away bc I drive everywhere. Life is great!"
