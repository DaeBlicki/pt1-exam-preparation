# ============================================================
# Programming Techniques for Scientific Simulations I
# package   : pyPenna
# function  : represent genome as bitstrings of {0, 1}
# created   : 27/01/24
# author    : DaeBlicki
#
# VERSION 1.00 (C) Copyright Free
# ============================================================

import copy
import numpy as np
import random

class Genome():
    """Represent sequence of good and bad mutations."""
    genome_size = 64    # All genome share the same size
    mutation_rate = 5   # All genome share the same mutation rate

    def __init__(self, genome=None):
        """Initialize genome object."""
        values = [0, 1]
        if genome is None:
            # genes: contains information for mutation at which age 
            self.genes = np.random.choice([0, 1], size=self.__class__.genome_size)
        else:
            self.genes = np.copy(genome.genes)

    def genome_size(self):
        """getter for genome size"""
        return self.__class__.genome_size
    
    def mutationRate(self):
        """getter for mutation rate"""
        return self.__class__.mutation_rate
    
    def mutationRate(self, newRate):
        """setter for mutation rate"""
        self.__class__.mutation_rate = newRate
    
    def mutate(self):
        """Genes will randomely flip good and bad genes depend on mutation rate.
        
        : rtype: void
        : return: genes will flip #mutation-rate numbers of genes
        """
        mutated_genes = np.random.random((0, self.__class__.genome_size - 1))
        for i in range(self.mutation_rate):
            self.genes[i] = not self.genes[i]
    
    def countBad(self, age):
        """return the number of bad mutations at given age.
        
        : param age: integer in range (0, 63)
        : rtype:  integer in range (0, 63) 
        : return: number of bad mutations at given age
        """
        counting_bad = 0
        for i in range(age):
            counting_bad += self.genes[i]
        return counting_bad