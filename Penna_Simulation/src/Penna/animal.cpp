/* ===================================================================
 * Programming Techniques for Scientific Simulations I  
 * package  :   Penna
 * function :   represent an animal for penna simulation
 * created  :   18/12/2023
 * author   :   DaeBlicki
 * 
 * updated  :   xx/xx/xx
 * VERSION 1.00 (C) Copyright Free to use
 * ===================================================================*/

#include "../../include/Penna/animal.hpp"
#include <stdexcept>

namespace Penna{

/* Definitions of static members */
unsigned int Animal::deletion_threshhold_;   /* maximal number of deletion of animal */
age_t Animal::reproduction_age_;             /* minimal age for reproduction of animal */
double Animal::propability_to_get_pregnant_; /* percentage to get pregnant */

Animal::Animal() : gen_(Penna::Genome())
{
    age_ = 0;
    pregnant_ = false;
}

Animal::~Animal()
{
}

Animal::Animal( const Animal& parent) : gen_(parent.gen_)
{
    age_ = parent.age_;
    pregnant_ = parent.pregnant_;
}

Animal::Animal( const Genome& gen, const age_t age, const bool pregnancy) : gen_(gen)
{
    age_ = age;
    pregnant_ = pregnancy;
}

bool Animal::operator<( const Animal& compared )
{
    return (age_ < compared.age());
}

bool Animal::operator==( const Animal& compared )
{
    return (age_ == compared.age());
}

bool Animal::operator>( const Animal& compared )
{
    return (age_ < compared.age());
}

age_t Animal::age() const
{
    return age_;
}

bool Animal::isPregnant() const
{
    return pregnant_;
}

Genome Animal::genome() const
{
    return gen_;
}

Animal Animal::giveBirth()
{
    if(pregnant_ != true){
        throw std::runtime_error("Animal must be pregnant to giving birth");
    }
    pregnant_ = false;
    age_t baby_age = 0;
    Genome baby_genome = Genome(gen_);
    baby_genome.mutate();
    return Animal(baby_genome, baby_age, false);
}

void Animal::reproduction()
{
    // try to reproduce, only if is old enough and NOT pregnant ;)
    if(age_ >= reproduction_age_ && !pregnant_){
        double pregnancy_luck = pt1::Random_Number_Generator::generate() % 100;
        pregnancy_luck = pregnancy_luck/ 100;
        if(propability_to_get_pregnant_ > pregnancy_luck){
            pregnant_ = true;
        }
    }
}

void Animal::growth()
{
    if(age_ == maximal_age_){
        throw std::runtime_error("Animal should never exceed the maximal age! \n");
    }
    age_++;
}


bool Animal::survive( const double verhulst)
{
    /* death by mutation */
    if(gen_.countBad(age_) > deletion_threshhold_){
        return false;
    }
    /* death by verhulst */
    double chance_to_die = pt1::Random_Number_Generator::generate() % 100;
    chance_to_die = chance_to_die/100;
    if(verhulst < chance_to_die){
        return false;
    }
    /* if maxiaml age arrived, is it time to go :(.. */
    if(age_ == maximal_age_){
        return false;
    }
    return true;
}

void Animal::init( const unsigned int deletion_treshhold, const age_t reproduction_age, const double probability_to_get_pregnant)
{
    deletion_threshhold_ = deletion_treshhold;
    if(reproduction_age >= maximal_age_){
       throw std::runtime_error("Reproduction Age exceed Maximal Age, which is absolute nonesense! \n");
    }
    reproduction_age_ = reproduction_age;
    if(probability_to_get_pregnant < 0 || probability_to_get_pregnant > 1){
       throw std::runtime_error("Probability to get pregnant chance is not in range [0,1]! \n");
    }
    propability_to_get_pregnant_ = probability_to_get_pregnant;
}

std::tuple<unsigned int, age_t, double> Animal::getInitialization()
{
    return std::tuple<unsigned, age_t, double>(deletion_threshhold_, reproduction_age_, propability_to_get_pregnant_);
}


age_t Animal::maximalAge()
{
    return Animal::maximal_age_;
}


} // end namespace penna