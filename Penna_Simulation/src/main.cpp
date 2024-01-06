/* ===================================================================
 * Programming Techniques for Scientific Simulations I  
 * package  :   Penna
 * function :   entry point of the simulation
 * created  :   18/12/2023
 * author   :   DaeBlicki
 * 
 * updated  :   xx/xx/xx
 * VERSION 1.00 (C) Copyright Free to use
 * ===================================================================*/

#include <iostream>
#include <fstream>
#include "../include/simulation.hpp"

int main()
{
    std::cout << "WELCOME TO THE PENNA SIMULATION! \n";
    Simulation mySimulation = Simulation();
    mySimulation.init();
    mySimulation.simulate_with_visuals();
    mySimulation.saveResult();
    return 0;
}