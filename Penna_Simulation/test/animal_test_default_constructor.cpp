#include "../include/Penna/animal.hpp"
#include <stdexcept>

/*
 * TEST_ANIMAL_DEFAULT_CONSTRUCTOR - Test the Default Constructor for Animal
 * Every constructed Animal should be random and not the same!
 * start with age = 0, unpregnant, alive
 */

void TEST_ANIMAL_DEFAULT_CONSTRUCTOR()
{
    pt1::Random_Number_Generator::seed(42);
    Penna::Animal animal_one = Penna::Animal();
    if(animal_one.age() != 0){
        throw std::logic_error("TEST ANIMAL DEFAULT CONSTRUCTOR FAILED! : Wrong Age! \n");
    }
    if(animal_one.isPregnant() == true){
        throw std::logic_error("TEST ANIMAL DEFAULT CONSTRUCTOR FAILED! : Pregnant Baby?! \n");
    }
    Penna::Animal animal_two = Penna::Animal();
    age_t maximal_Age = Penna::Animal::maximalAge();
    if(animal_one.genome().countBad(5) == animal_two.genome().countBad(5)){
        throw std::logic_error("TEST ANIMAL DEFAULT CONSTRUCTOR FAILED! : Identical genome");
    }
}

int main(){
    TEST_ANIMAL_DEFAULT_CONSTRUCTOR();
    return 0;
}