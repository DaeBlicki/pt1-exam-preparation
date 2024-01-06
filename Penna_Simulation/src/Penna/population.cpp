/* ===================================================================
 * Programming Techniques for Scientific Simulations I  
 * package  :   Penna
 * function :   represent the population of animals
 * created  :   18/12/2023
 * author   :   DaeBlicki
 * 
 * updated  :   xx/xx/xx
 * VERSION 1.00 (C) Copyright Free to use
 * ===================================================================*/

#include "../../include/Penna/population.hpp"
#include <stdexcept>

namespace Penna{

Population::Population()
{
    population_ = std::list<Penna::Animal>();
    maximal_size_ = 0;
    size_ = 0;
}

Population::~Population()
{
}

Population::Population( const Population& parent)
{
    population_ = parent.population_;
    size_ = parent.size_;
    maximal_size_ = parent.maximal_size_;
}

void Population::checkInitialization() const
{
    if(maximal_size_ == 0){
        throw std::runtime_error("Population is not initialized yet! \n");
    }
}


std::list<Penna::Animal> Population::population() const
{
    return population_;
}

size_t Population::size() const
{
    return size_;
}

size_t Population::maxSize() const
{
    return maximal_size_;
}  


double Population::getVelhustFactor() const
{   
    checkInitialization();
    const double velhustFactor = 1 - (size_ / maximal_size_);
    return velhustFactor;
}

void Population::timeStep()
{
    checkInitialization();
    std::list<Penna::Animal> new_borned_generation;
    for(auto it = population_.begin(); it != population_.end(); it++){
        Penna::Animal &current = *it;
        if(current.survive(this->getVelhustFactor()) == false){
            population_.erase(it++);
            size_--;
        }
        /* Animal survive and can now enjoy daily life! */
        else
        {
            /* Pregnant Animals are giving birth in spring! */
            if(current.isPregnant()){
                new_borned_generation.insert(new_borned_generation.end(), current.giveBirth()); //< Baby is now part of population
                size_++;
            }
            current.reproduction(); //< individual 
            current.growth();       //< individual older at the end of the year
        }
    }
    /* insert baby generation in the current population*/
    population_.merge(new_borned_generation);
}

void Population::start( const size_t startingSize , const size_t maximalSize) 
{
    if(startingSize == 0){
        throw std::runtime_error("Invalid Argument: population cannot start with zero animals! \n");
    }
    if(startingSize >= maximalSize){
        throw std::runtime_error("Starting size exceed maximal size in the initialization! \n");
    }
    if(size_ != 0 && maximal_size_ != 0){
        throw std::runtime_error("Population cannot be restarted! \n");
    }
    maximal_size_ = maximalSize;
    size_ = startingSize;
    /* Start population with newborn animals with starting size */
    for(unsigned int i = 0; i < startingSize; i++){
        // std::list<Penna::Animal>(startingSize, Penna::Animal()) does not make indiviual Animals
        population_.insert(population_.end(), Penna::Animal());
    }
}

double Population::countBadPerAnimal() const
{
    checkInitialization();
    if(size_ == 0){
        return 0;
    }
    unsigned int badMutation = 0;
    const age_t maximal_age = Penna::Animal::maximalAge();
    for(auto it = population_.begin(); it != population_.end(); it++){
        const Penna::Animal &current = *it;
        const age_t age_of_animal = current.age();
        badMutation += current.genome().countBad(maximal_age - 1);
    }
    return (badMutation / size_);
}


bool Population::survived()
{
    checkInitialization();
    if(size_ > 0){
        return true;
    }
    return false;
}


} // end namespace Penna