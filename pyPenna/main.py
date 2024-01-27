# ============================================================
# Programming Techniques for Scientific Simulations I
# package   : pyPenna
# function  : entry point of pyPenna Simulation
# created   : 27/01/24
# author    : DaeBlicki
#
# VERSION 1.00 (C) Copyright Free
# ============================================================

import numpy as np
import matplotlib.pyplot as plt 
from src import Genome, Animal, Population, Simulation

def main():
    # enter initializing members for pyPenna classes
    seed = input("Enter seed for python random number generator!")
    seed = int(seed)
    mutation_rate = input("Enter mutation rate for genome")
    mutation_rate = int(mutation_rate)
    mutation_tolerance = input("Enter mutation tolerance for animals")
    mutation_tolerance = int(mutation_tolerance)
    start = input("Enter starting size of population")
    start = int(start)
    capacity = input("Enter capacity of the population")
    capacity = int(capacity)
    # simulate pyPenna
    Simulator = Simulation(mutation_rate, mutation_tolerance, start, capacity)
    Simulator.simulate()