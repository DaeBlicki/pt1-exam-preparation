#include "../include/Penna/animal.hpp"
#include "../include/pt1/Random.hpp"
#include <stdexcept>

/* 
 * TEST_ANIMAL_COPY_CONSTRUCTOR() - Test the copy constructor of genome
 * Parent and Child genome should be identical
 */
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
