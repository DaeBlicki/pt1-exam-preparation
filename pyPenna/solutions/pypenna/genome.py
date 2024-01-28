#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Programming Techniques for Scientific Simulations, ETH Zurich

# For Python 2.x compatibility.
from __future__ import division, print_function

import copy
import random
import numpy as np


# Inherit from object to make Genome a new-style class (only required in Python 2.x).
class Genome(object):
    gene_size = 64 # Class variable shared by all instances.

    def __init__(self, genome=None):
        if genome is None:
            # np.array with dtype=bool is a "bitset".
            self.genes = np.zeros(self.__class__.gene_size, dtype=bool)
        else:
            # Instance variable unique to each instance.
            self.genes = copy.deepcopy(genome.genes)

    def mutate(self):
        """
        Mutates the Genome in-place.
        """
        for _ in range(self.__class__.mutation_rate):
            self._flip(random.randint(0, self.__class__.gene_size - 1))

    def _flip(self, idx):
        """
        Flips a single gene.
        """
        self.genes[idx] = not self.genes[idx]

    def num_bad(self, age):
        """
        Returns the number of bad genes up to a certain age.
        """
        return sum(self.genes[:age])
