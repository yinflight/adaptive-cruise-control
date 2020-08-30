"""
plots the error accumulation, lead vs ego speed, lead vs ego acceleration, and distance between vehicle variation all against time (duration of simulation). reads from stdin via ./ACC | python3 main.py
"""

import sys
import numpy as np
import matplotlib.pyplot as plt
import os

if __name__ == "__main__":

    DURATION=int(os.environ["DUR"])
    STEP=1
    T = np.linspace(1, DURATION, STEP*DURATION)

    SETPOINT=[30]*DURATION

    stdin_arr = []
    error = []
    error_sum = []
    lead_v = []
    ego_v = []
    lead_a = []
    ego_a = []
    dist1 = []
    dist2 = []
    dist = []

    for line in sys.stdin:
        # stdin: error, lead speed,e go speed, lead acceleration, ego acceleration, distance

        # split the input by ,
        stdin_arr = line.split(",")

        error.append(float(stdin_arr[0]))

        error_sum.append(float(stdin_arr[1]))

        lead_v.append(float(stdin_arr[2]))

        ego_v.append(float(stdin_arr[3]))

        lead_a.append(float(stdin_arr[4]))

        ego_a.append(float(stdin_arr[5]))

        dist1.append(float(stdin_arr[6]))

        dist2.append(float(stdin_arr[7]))

        dist.append(float(stdin_arr[8].strip("\n")))

    # error
    fig, ax = plt.subplots(2, 1, sharex=True, constrained_layout=True)
    ax[0].plot(T, error)
    ax[0].set_title("PID error")
    ax[0].set_ylabel("error")

    ax[1].plot(T, error_sum)
    ax[1].set_title("PID error accumulation")
    ax[1].set_xlabel("time ($s$)")
    ax[1].set_ylabel("error accumulation")

    plt.savefig("plots/error.png")
    plt.clf()

    # velocity and acceleration
    fig, ax = plt.subplots(2, 1, sharex=True, constrained_layout=True)
    ax[0].plot(T, lead_v)
    ax[0].plot(T, ego_v)
    ax[0].plot(T, SETPOINT) 
    ax[0].set_ylabel("vehicle velocity ($m/s$)")
    ax[0].set_title("Velocity responses")
    ax[0].legend(["lead vehicle", "ego vehicle", "cruise setpoint (30 $m/s$)"])

    ax[1].plot(T, lead_a)
    ax[1].plot(T, ego_a)
    ax[1].set_xlabel("time ($s$)")
    ax[1].set_ylabel("vehicle acceleration ($m/s^2$)")
    ax[1].set_title("Acceleration responses")
    ax[1].legend(["lead vehicle", "ego vehicle"])

    plt.savefig("plots/vel-acc-responses.png")
    plt.clf()


    # distance
    fig, ax = plt.subplots(2, 1, sharex=True, constrained_layout=True)
    ax[0].plot(T, dist1)
    ax[0].plot(T, dist2)
    ax[0].set_ylabel("distance ($m$)")
    ax[0].set_title("Distance traveled from the origin")
    ax[0].legend(["lead vehicle", "ego vehicle"])

    DISTANCE=[10]*DURATION
    ax[1].plot(T, dist)
    ax[1].plot(T, DISTANCE)
    ax[1].set_xlabel("time ($s$)")
    ax[1].set_ylabel("distance between vehicles (m)")
    ax[1].set_title("Distance between lead and ego vehicles")
    ax[1].legend(["relative distance","distance setpoint (10 $m$)"])
    plt.savefig("plots/distance.png")

