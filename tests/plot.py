"""
plots the error accumulation, lead vs ego speed, lead vs ego acceleration, and distance between vehicle variation all against time (duration of simulation). reads from stdin via ./ACC | python plot.py
"""

import sys
import numpy as np
import matplotlib.pyplot as plt

stdin_arr = []
error = []
lead_v = []
ego_v = []
lead_a = []
ego_a = []
dist = []

DURATION=60
STEP=1

t = np.linspace(0, DURATION, STEP) 

class Plot():
    def __init__(self):
        self.fig, self.ax = plt.subplots()
        self.axis("equal")

    def clear(self):
        clf()

    def one():
        """
        plot one series
        """
        pass

    def two():
        """
        plot two series
        """
        pass





    def plot(data, xaxis, yaxis, title, legend):
        """
        plots the data.
        Args:
            data, list of data
            xaxis, title of x axis
            yaxis, title of y axis
            title, title of plot
            legend, list of legend items
        """

        plt.subplots.plot(xaxis, yaxis)


        # to clear for the next call
        clf()


if __name__ == "__main__":
    for line in sys.stdin:
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


        plot(t, 

