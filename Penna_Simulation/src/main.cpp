/*
 * main() - Entry point of the Penna_Simulation executable
 */

#include <iostream>
#include <fstream>
#include "../include/Penna/simulation.hpp"

int main()
{
    std::cout << "WELCOME TO THE PENNA SIMULATION! \n";
    Penna::Simulation mySimulation = Penna::Simulation();
    mySimulation.init();
    mySimulation.simulate_with_visuals();
    mySimulation.saveResult();
    return 0;
}