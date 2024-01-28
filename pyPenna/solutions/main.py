#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Programming Techniques for Scientific Simulations, ETH Zurich

# For Python 2.x compatibility.
from __future__ import division, print_function

import random

from pypenna import Population, Fishing


def run(pop, time, of):
    while pop.time < time:
        pop.step()
        print(pop.time)
        of.write('{0.time}\t{0.N}\n'.format(pop))


def main(N, M1, p1, M2, p2):
    random.seed(0)

    pop = Population(
        mutation_rate=1,
        bad_threshold=3,
        repr_age=7,
        N_max=200000,
        N_0=20000,
    )

    with open('population.dat', 'w') as of:
        of.write('# time\tN\n')
        run(pop, M1, of)
        pop.fishing = Fishing(probability=p1)
        run(pop, M2, of)
        pop.fishing = Fishing(probability=p2)
        run(pop, N, of)


if __name__ == "__main__":
    main(N=1600, M1=1000, p1=0.17, M2=1200, p2=0.22)
