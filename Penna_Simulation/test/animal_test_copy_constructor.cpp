/* ===================================================================
 * Programming Techniques for Scientific Simulations I  
 * package  :   penna
 * function :   test if copied animal is identical
 * created  :   05/01/2024
 * author   :   DaeBlicki
 * 
 * updated  :   xx/xx/xx
 * VERSION 1.00 (C) Copyright Free to use
 * ===================================================================*/

#include "../include/Penna/animal.hpp"
#include "../include/pt1/Random.hpp"
#include <stdexcept>

void TEST_ANIMAL_COPY_CONSTRUCTOR()
{
    Penna::Animal parent_animal = Penna::Animal();
    Penna::Animal child_animal = Penna::Animal(parent_animal);
    const age_t maximalAge = Penna::Animal::maximalAge();
    for(age_t age = 0; age < maximalAge; age++){
        if(parent_animal.genome().countBad(age) != parent_animal.genome().countBad(age)){
            throw std::logic_error("TEST ANIMAL COPY CONSTRUCTOR FAILED: Not identical genome! \n");
        }
    }
    if(parent_animal.age() != child_animal.age()){
        throw std::logic_error("TEST ANIMAL COPY CONSTRUCTOR FAILED: Not identical genome! \n");
    }
    if(parent_animal.isPregnant() != child_animal.isPregnant()){
        throw std::logic_error("TEST ANIMAL COPY CONSTRUCTOR FAILED: Not identical pregnancy! \n");
    }
}

int main(){
    TEST_ANIMAL_COPY_CONSTRUCTOR();
    return 0;
}
