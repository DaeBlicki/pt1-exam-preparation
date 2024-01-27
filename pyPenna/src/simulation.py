# ============================================================
# Programming Techniques for Scientific Simulations I
# package   : pyPenna
# function  : main simulation of pyPenna
# created   : 27/01/24
# author    : DaeBlicki
#
# VERSION 1.00 (C) Copyright Free
# ============================================================

import numpy as np
import matplotlib.pyplot as plt 
from .population import Population
from .animal import Animal
from .genome import Genome

class Simulation():
    """Represent main simulation class for pyPenna"""

    def ___init___(self, mutation_rate=0, mutation_tolerance=5, 
                   start=0, capacity=0):
        """Create simulation object"""
        assert(capacity >= start)
        assert(mutation_rate >= 0 and mutation_rate <= 63)
        assert(mutation_tolerance >= 0 and mutation_tolerance <= 63)
        self.years = 0
        self.population = Population(self.population, start, capacity)

    def simulate(self):
        # initialize animal and genome class
        Genome.__class__.mutation_rate = self.mututation_rate
        Animal.__class__.mutation_tolerance = self.mutation_tolerance
        # create matplotlib arrays
        time = np.empty()
        individuals = np.empty()
        # simulate with 500 years and print out the result
        while self.population.survived() or self.population > 500:
            np.insert(time, self.years, self.years)
            np.insert(individuals, self.years, self.population.size)
            self.population.timeStep()
        # plot result with matplotlib
        fig = plt.figure()
        ax = fig.add_subplot(111)
        ax.plot(time, individuals, color='lightblue', linewidth=3)
        ax.set_autoscale_on(True)
        ax.set_xlabel("Time [years]")
        ax.set_ylabel("Size")
        plt.savefig('result.png')
        plt.show()

