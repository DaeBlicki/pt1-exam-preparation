/* ===================================================================
 * Programming Techniques for Scientific Simulations I  
 * package  :   penna
 * function :   test the advanced animal initialization
 * created  :   05/01/2024
 * author   :   DaeBlicki
 * 
 * updated  :   xx/xx/xx
 * VERSION 1.00 (C) Copyright Free to use
 * ===================================================================*/

#include "../include/Penna/animal.hpp"
#include "../include/pt1/Random.hpp"
#include <stdexcept>
#include <error.h>
#include <iostream>

void TEST_ANIMAL_ADVANCED_INITIALIZATION()
{
    /* Create mother and the new born child */
    pt1::Random_Number_Generator::seed(42);
    const age_t maximalAge = Penna::Animal::maximalAge();
    const unsigned int mutation_rate = 5;
    Penna::Animal mother = Penna::Animal();

    /* Initialize animals with 100% pregancy rate with age 5 */
    constexpr double epsilon = 1e-6;
    const age_t reproductionAge = 5;
    Penna::Animal::init(mutation_rate, reproductionAge, 1.0);

    /* Speed growth mother to age = 4 and try to reproduce before puperty :) */
    for(unsigned int i = 0; i < reproductionAge-1; i++){
        mother.growth();
        mother.reproduction();
    }
    if(mother.isPregnant() == true){
        throw std::logic_error("TEST_ANIMAL_ADVANCED_INITIALIZATION FAILED!: To young to be pregnant! \n");
    }

    /* Speed growth mother to age = 5 and actually get pregnant */
    mother.growth();
    mother.reproduction();
    if(mother.isPregnant() == false){
        throw std::logic_error("TEST_ANIMAL_ADVANCED_INITIALIZATION FAILED!: should 100% be pregnant! \n");
    }

    /* Pregnancy test after giving birth */    
    Penna::Animal child = mother.giveBirth();
    if(mother.isPregnant() == true){
        throw std::logic_error("TEST_ANIMAL_ADVANCED_INITIALIZATION FAILED!: mother just gave birth! \n");
    }

    /* Baby health check :) */
    unsigned int mother_bad_count = mother.genome().countBad(maximalAge - 1);
    unsigned int child_bad_count = child.genome().countBad(maximalAge - 1);
    unsigned int upper_range = mother_bad_count + mutation_rate;
    unsigned int lower_range = mother_bad_count - mutation_rate;
    if(child_bad_count < lower_range || child_bad_count > upper_range){
        throw std::logic_error("TEST_ANIMAL_ADVANCED_INITIALIZATION FAILED!: child genome mutation! \n");
    }

    /* Mother want to reproduce, which should be impossible */
    Penna::Animal::init(mutation_rate, reproductionAge, 0); // set pregnancy rate to 0
    const unsigned int iteration = 100;
    for(unsigned int i = 0; i < iteration; i++){
        mother.reproduction();
    }
    if(mother.isPregnant() == true){
        throw std::logic_error("TEST_ANIMAL_ADVANCED_INITIALIZATION FAILED!: too strong willpower to get pregnant with ZERO chance! \n");
    }
}

int main(){
    TEST_ANIMAL_ADVANCED_INITIALIZATION();
    return 0;
}