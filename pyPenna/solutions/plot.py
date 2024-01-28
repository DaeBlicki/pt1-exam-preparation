#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Programming Techniques for Scientific Simulations, ETH Zurich

import numpy as np
import matplotlib.pyplot as plt

pop = np.loadtxt('population.dat')

plt.figure()
plt.plot(pop[:, 0], pop[:, 1], 'x')
plt.yscale('log')
plt.xlabel('year')
plt.ylabel('population size')
plt.savefig('population.pdf', bbox_inches='tight')

plt.show()
