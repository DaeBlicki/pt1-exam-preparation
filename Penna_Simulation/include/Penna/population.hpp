/* ==============================================================
 * Programming Techniques for Scientific Simulations I  
 * Header file defining population for penna simulation
 * 
 * VERSION 1.00 (C) Copyright Free to use
 * ==============================================================*/

#ifndef POPULATION_H
#define POPULATION_H

#include "animal.hpp"
#include <list>
#include <unordered_set>

// namespace Penna
namespace Penna{

class Population{    

protected:
    std::list<Penna::Animal> population_;  /* List of all the individuals in a population */
    size_t size_;                   /* Current number of the population */
    size_t maximal_size_;           /* Maximal number of the population */
private:
    void checkInitialization() const;     /* throw error if the Population is not initialized yet! */

public:
    Population();   /* Default Constructor */
    ~Population();  /* Destructor */
    Population( const Penna::Population& );   /* Copy Constructor */

    std::list<Penna::Animal> population() const;      /* getter for population_ */
    size_t size() const ;                       /* getter for size_ */
    size_t maxSize() const;                     /* getter for maxSize_ */

    /*
     * getVelhustFactor() - Calculate and return the vehulst factor
     * PRE: -
     * POST: return vehulst factor 
     */
    double getVelhustFactor() const;

    /*
     * countBadPerAnimal() - Count and return the number of bad mutation per animal
     * PRE: initialized population
     * POST: return number of the average bad mutation per animal
     */
    double countBadPerAnimal() const;

    /*
     * timeStep() - simulate one year for the population
     * PRE: -
     * POST: the population is one year older
     */
    void timeStep();

    /*
     * start(staringSize, maximalSize) - the population start with the given 
     * PRE: population size cannot be restarted and staringSize < maximalSize
     * POST: population start with given size and randomely initialized animals and 
     */
    void start( const size_t , const size_t);

    /*
     * survived() - return if the population survived
     * PRE: population has been started
     * POST: return if population has been distinct
     */
    bool survived();

};

} // end namespace Penna



#endif /* POPULATION_H */
