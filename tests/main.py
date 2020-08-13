"""
plots the error accumulation, lead vs ego speed, lead vs ego acceleration, and distance between vehicle variation all against time (duration of simulation). reads from stdin via ./ACC | python3 main.py
"""

import sys
import numpy as np
import matplotlib.pyplot as plt

if __name__ == "__main__":

    DURATION=60
    STEP=1
    T = np.linspace(1, DURATION, STEP*DURATION)

    SETPOINT=[30]*DURATION
    DISTANCE=[10]*DURATION

    stdin_arr = []
    error = []
    error_sum = []
    lead_v = []
    ego_v = []
    lead_a = []
    ego_a = []
    dist = []

    for line in sys.stdin:
        # stdin: error, lead speed,e go speed, lead acceleration, ego acceleration, distance

        # split the input by ,
        stdin_arr = line.split(",")
        # idx 0 is error
        error.append(stdin_arr[0])

        #idx 1 is error sum
        error_sum.append(int(float(stdin_arr[1])))

        # idx 1 is lead speed
        lead_v.append(int(float(stdin_arr[2])))

        #idx 2 is ego speed
        ego_v.append(int(float(stdin_arr[3])))

        # idx 3 is lead acceleration
        lead_a.append(int(float(stdin_arr[4])))

        # idx 4 is ego acceleration
        ego_a.append(int(float(stdin_arr[5])))

        # idx 5 is distance between vehicles

        dist.append(int(float(stdin_arr[6].strip("\n"))))

    # error
    
    plt.plot(T, error)
    plt.xlabel("time (s)")
    plt.ylabel("error")
    plt.title("PID error over time")
    plt.savefig("plots/error.png")
    plt.clf()

    
    # error sum
    plt.plot(T, error_sum)
    plt.xlabel("time (s)")
    plt.ylabel("error accumulation")
    plt.title("Total PID error over time")
    plt.savefig("plots/total_error.png")
    plt.clf()


    # velocity
    plt.plot(T, lead_v)
    plt.plot(T, ego_v)
    plt.plot(T, SETPOINT) 
    plt.xlabel("time (s)")
    plt.ylabel("vehicle velocity (m/s)")
    plt.title("Lead and ego vehicle velocity responses")
    plt.legend(["lead vehicle", "ego vehicle", "cruise setpoint"])
    plt.savefig("plots/velocity.png")
    plt.clf()

    
    # acceleration
    plt.plot(T, lead_a)
    plt.plot(T, ego_a)
    plt.xlabel("time (s)")
    plt.ylabel("vehicle acceleration (m/s^2)")
    plt.title("Lead and ego vehicle acceleration responses")
    plt.legend(["lead vehicle", "ego vehicle"])
    plt.savefig("plots/acceleration.png")
    plt.clf()


    # distance
    plt.plot(T, dist)
    plt.plot(T, DISTANCE)
    plt.xlabel("time (s)")
    plt.ylabel("distance (m)")
    plt.title("Distance between lead and ego vehicle over time")
    plt.legend(["actual distance","minimum distance"])
    plt.savefig("plots/distance.png")

