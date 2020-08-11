"""
plots the error accumulation, lead vs ego speed, lead vs ego acceleration, and distance between vehicle variation all against time (duration of simulation). reads from stdin via ./ACC | python3 main.py
"""

import sys
import numpy as np
from plot import Plot


if __name__ == "__main__":

    DURATION=60
    STEP=1
    stdin_arr = []
    error = []
    lead_v = []
    ego_v = []
    lead_a = []
    ego_a = []
    dist = []

    t = np.linspace(0, DURATION, STEP) 

    for line in sys.stdin:
        # stdin: error, lead speed,e go speed, lead acceleration, ego acceleration, distance

        # split the input by ,
        stdin_arr = line.split(",")
        
        # idx 0 is error (what even is error? accumulated?)
        error.append(stdin_arr[0])

        # idx 1 is lead speed
        lead_v.append(stdin_arr[1])

        #idx 2 is ego speed
        ego_v.append(stdin_arr[2])

        # idx 3 is lead acceleration
        lead_a.append(stdin_arr[3])

        # idx 4 is ego acceleration
        ego_a.append(stdin_arr[4])

        # idx 5 is distance between vehicles
        dist.append(stdin_arr[5])


