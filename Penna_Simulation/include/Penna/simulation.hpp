#ifndef SIMULATION_H
#define SIMULATION_H

#include "population.hpp"
#include "animal.hpp"
#include "../pt1/Random.hpp"

namespace Penna{

class Simulation
{
private:
    Penna::Population population_;
    age_t years_;
    unsigned int Random_Number_Generator_Seed_;
    unsigned int Mutation_Rate_Parameter_;
    unsigned int Starting_Size_;
    unsigned int Maximal_Size_;

public:
    Simulation();   /* Default Constructor */

    /*
     * init() - initialize the Simulation
     * PRE: Enter all the Simulation parameter
     * @ RNG::seed_
     * @ Genome::mutationRate_
     * @ Species (predefined or selfmade, with animal static members)
     * @ Population::start()
     * POST: Simulation is initialized
     */
    void init();

    /*
     * simulate() - simulate the penna simulation and return the distinction year
     * PRE: Simulation is initialized
     * POST: Population is distinct and result is given in output file
     */
    void simulate();

    /*
     * simulate_with_visuals() - simulate the penna simulation and show graphical result
     * PRE: Simulation is initialized
     * POST: Population is distinct and each timestep is visually presented
     */
    void simulate_with_visuals();

    /*
     * saveResult() - write the members to a .txt file, part of simulate() function
     * PRE: Population is distinct
     * POST: .txt file is written
     */
    void saveResult();

};

} // end namespace Penna


#endif /* STIMULATION_H     */