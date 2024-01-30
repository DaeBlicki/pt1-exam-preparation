# ==========================================================
# Programming Techniques for Scientific Simulation I
# package   : Lotka Volterra ODE
# function  : Solve and Plotting simple Lotka Volterra ODE
# created   : 29/01/24
# author    : DaeBlicki
#
# VERSION 1.00 (C) Copyright free to use
# ==========================================================

import numpy as np
import matplotlib.pyplot as plt
from scipy import integrate

# initial conditions and parameter
u0 = 20     # prey (deer)
v0 = 10     # predator (wolfs)
y0 = [u0, v0]                    

# problem parameters
alpha = 1. 
beta = 0.2
delta = 1.
gamma = 0.1
parameters = [alpha, beta, delta, gamma]

def derivate(Y, t, alpha, beta, delta, gamma):
    """derivate function for lotka-volterra ode.
    
    :param Y: array of the indivual numbers [u, v]
    :param parameters: array contains [alpha, beta, delta, gamma]
    :rtype : array of float
    :return: dY = [du, dv]
    """
    # initial number of individuals
    u = Y[0]    # predator
    v = Y[1]    # prey
    # list of ode parameters
    alpha = parameters[0]
    beta = parameters[1]
    delta = parameters[2]
    gamma = parameters[3]
    # definition of lotka-volterra derivate
    du = u*(alpha - beta*v)
    dv = v*(gamma*u - delta)
    return [du, dv]

# solve with odeint
t = np.linspace(0, 50, num=1000)    # time
res = integrate.odeint(derivate, y0, t, args=(alpha, beta, delta, gamma))
x,y = res.T

# plot time vs indivuals
plt.figure()
plt.grid()
plt.title("odeint method")
plt.plot(t, x, 'xb', label = 'Deer')
plt.plot(t, y, '+r', label = "Wolves")
plt.xlabel('Time t, [days]')
plt.ylabel('Population')
plt.legend()
plt.show()

# plot deer vs wolves
plt.figure()
IC = np.linspace(1.0, 6.0, 21) # initial conditions for deer population (prey)
for deer in IC:
    X0 = [deer, 1.0]
    Xs = integrate.odeint(derivate, X0, t, args = (alpha, beta, delta, gamma))
    plt.plot(Xs[:,0], Xs[:,1], "-", label = "$x_0 =$"+str(X0[0]))
plt.xlabel("Deer")
plt.ylabel("Wolves")
plt.legend()
plt.title("Deer vs Wolves")
plt.show()