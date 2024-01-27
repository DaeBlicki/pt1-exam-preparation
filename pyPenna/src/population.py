# ============================================================
# Programming Techniques for Scientific Simulations I
# package   : pyPenna
# function  : represent a populations of animals
# created   : 27/01/24
# author    : DaeBlicki
#
# VERSION 1.00 (C) Copyright Free
# ============================================================

import numpy as np
import random
from .animal import Animal

class Population():
    """Represent a population of animals in pyPenna."""
    def __init__(self, population=None, size=0, capacity=0):
        """Initialize a population object"""
        self.population = np.empty()
        assert(capacity >= size)
        # initialize population list
        for i in range(size):
            np.insert(self.population, 0, Animal())

    def getVelhust(self):
        """Calculate and return verhulst factor.
        
        :rtype : double
        :return: velhust fact (1. - size/capacity)
        """
        return 1. - (self.size / self.capacity)
    
    def survived(self):
        """Return the survive status of the population

        :rtype : bool
        :return: the survive status
        """
        if self.size == 0:
            return True
        return False
    
    def timeStep(self):
        """Simulate one year for the population

        :rtype : void
        :return: Popoulation has grown one year
        """
        new_Generation = np.empty()
        for animal in self.population:
            # animal have to survive before enjoying life
            if not animal.survive(self.getVelhust()):
                np.delete(self.population, animal)
                self.size -= 1
            else:
                # pregnant individuals giving birth
                if(animal.pregnant):
                    np.insert(new_Generation, 0, animal.giveBirth())
                    size += 1
                animal.reproduction()   # animals getting pregnant
                animal.growth()         # animals getting older
        np.concatenate(self.population, new_Generation, 0)