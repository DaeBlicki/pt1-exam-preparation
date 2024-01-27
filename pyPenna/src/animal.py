# ============================================================
# Programming Techniques for Scientific Simulations I
# package   : pyPenna
# function  : represent animal class for pyPenna
# created   : 27/01/24
# author    : DaeBlicki
#
# VERSION 1.00 (C) Copyright Free
# ============================================================

import numpy as numpy
import random
from .genome import Genome

class Animal():
    """Represent an animal in pyPenna."""
    mutation_tolerance = 5          # maximal number of mutations [1, 63]
    reproduction_age = 12           # minimal age to reproduce [0, 63]
    chance_to_get_pregnant = 0.5    # chance to get pregnant [0, 1]
    maximal_age = 63                # maximal age for an animal

    def __init__(self, genome=None, age=0, pregnant=False):
        """Initialize animal object."""
        self.gen = Genome(genome)
        self.age = age
        self.pregnant = pregnant

    def init(self, mutation_tolerance, reproduction_age, 
             chance_to_get_pregnant):
        """Initialize member parameter shared by all animals.

        :param mutaton_tolerance     : integer in range [0, 63]
        :param reproduction_age      : integer in range [0, 63]
        :param chance_to_get_pregant : double in range [0, 1]
        """
        self.__class__.mutation_tolerance = mutation_tolerance
        self.__class__.reproduction_age = reproduction_age
        self.__class__.chance_to_get_pregnant = chance_to_get_pregnant

    def giveBirth(self):
        """Giving birth and return an animal baby with mutated genes
        
        :rtype : Animal
        :return: Newborn animal with mutated genes from mother
        """
        # animal can only give birth if it pregnant
        if self.pregnant:
            self.pregnant = False
            baby_genome = self.gen
            baby_genome.mutate
            return Animal(baby_genome)
        
    def reproduction(self):
        """Animal is trying to impregnate himself assexually

        :rtype : void
        :return: self has chance to get pregnant
        """
        # only check unpregnant and adult animals
        if(not self.pregnant and self.age >= self.__class__.reproduction_age):
            chance = random.random()
            if chance > self.chance_to_get_pregnant:
                self.pregnant = True
    
    def growth(self):
        """Animal is getting older
        
        :rtype : void
        :return: self is one year older
        """
        self.age += 1

    def survive(self, verhulst):
        """Animal is trying to survive the environment and mutations

        :param verhulst: environmental factor, double in range (0, 1]
        :rtype : bool
        :return: True, if the animal survived
        """
        # check biological factors
        if self.gen.countBad() > self.__class__.mutation_tolerance:
            return False
        # check age factor
        if self.age > self.__class__.maximal_age:
            return False
        # check environmental factor
        chance_to_die = random.random()
        if verhulst < chance_to_die:
            return False
        # Animal survived!
        return True


