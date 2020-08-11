import matplotlib.pyplot as plt


class Plot():
    def __init__(self):
        self.fig, self.ax = plt.subplots()
        self.axis("equal")

    def clear(self):
        clf()
        # is this the proper way to clear the plots?


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

        # add axis titles, legend

