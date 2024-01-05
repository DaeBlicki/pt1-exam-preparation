#include "../include/Penna/population.hpp"
#include <stdexcept>

/*
 * TEST_ANIMAL_POPULATION_CONSTRUCTOR - Test the Default Constructor for Animal
 * Uninitialized population has size_ == 0 and max_size_ == 0 
 */

void TEST_POPULATION_DEFAULT_CONSTRUCTOR()
{
    pt1::Random_Number_Generator::seed(42);
    Penna::Population test_population = Penna::Population();
    if(test_population.size() != 0){
        throw std::logic_error("TEST POPULATION DEFAULT CONSTRUCTOR FAILED! : Size! \n");
    }
    if(test_population.maxSize() != 0){
        throw std::logic_error("TEST POPULATION DEFAULT CONSTRUCTOR FAILED! : Maximal Size! \n");
    }
    if(!test_population.population().empty()){
        throw std::logic_error("TEST POPULATION DEFAULT CONSTRUCTOR FAILED! : List is not empty! \n");
    }
}

int main(){
    TEST_POPULATION_DEFAULT_CONSTRUCTOR();
    return 0;
}