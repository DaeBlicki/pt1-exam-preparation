#include "../include/Penna/population.hpp"
#include <stdexcept>

/* 
 * TEST_POPULATION_FUNCTIONALITY() - Test the member functions of population class
 * Parent and Child genome should be identical
 */
void TEST_POPULATION_FUNCTIONALITY()
{
    pt1::Random_Number_Generator::seed(42);
    Penna::Population test_population = Penna::Population();
    /* check initialization part */
    try{
        test_population.survived();
        throw std::logic_error("TEST POPULATION::SURVIVED() FAILED: Initialization! \n");
    } catch(std::runtime_error& err){}
    try{
        test_population.timeStep();
        throw std::logic_error("TEST POPULATION::TIMESTEP() FAILED: Initialization! \n");
    } catch(std::runtime_error& err){}
    try{
        test_population.getVelhustFactor();
        throw std::logic_error("TEST POPULATION::VERLHUST() FAILED: Initialization! \n");
    } catch(std::runtime_error& err){}
    /* check Population::start()*/
    try{
        test_population.start(0, 100);
        throw std::logic_error("TEST POPULATION::START() FAILED: Start with zero animals! \n");
    } catch(std::runtime_error& err){}
    try{
        test_population.start(100, 100);
        throw std::logic_error("TEST POPULATION::START() FAILED: Start with maximal size! \n");
    } catch(std::runtime_error& err){}
    try{
        test_population.start(120, 100);
        throw std::logic_error("TEST POPULATION::START() FAILED: Start with overpopulation! \n");
    } catch(std::runtime_error& err){}
    try{
        test_population.start(100, 0);
        throw std::logic_error("TEST POPULATION::START() FAILED: Maximal cannot be zero! \n");
    } catch(std::runtime_error& err){}
    /* Check correct functionality after initialization */
    const unsigned int size = 5;
    const unsigned int maxSize = 50000;
    const double velhust = 1.0 - (size/ maxSize);   //< should be 0.9999
    const age_t maximalAge = Penna::Animal::maximalAge();
    test_population.start(size, maxSize);
    if(test_population.getVelhustFactor() != velhust){
        throw std::logic_error("TEST POPULATION::GETVELHUSTFACTOR() FAILED: Wrong Value! \n");
    }
    if(test_population.size() != size){
        throw std::logic_error("TEST POPULATION::SIZE() FAILED: Wrong Value! \n");
    }
    if(test_population.maxSize() != maxSize){
        throw std::logic_error("TEST POPULATION::MAXSIZE() FAILED: Wrong Value! \n");
    }
    if(test_population.population().size() != size){
        throw std::logic_error("TEST POPULATION::POPULATION() FAILED! \n");
    }
    /* check population::timeStep() method */
    Penna::Animal::init(maximalAge-1, 0, 1.0);      //< always get pregnant and mutation tolerance (survive rate is 0.9999)
    test_population.timeStep();                     //< make everyone pregnant!
    if(size != test_population.size()){
        throw std::logic_error("UNLUCKY RANDOM NUMBER GENERATOR! \n");
    }
    for(Penna::Animal& current: test_population.population()){
        if(current.isPregnant() == false){
            throw std::logic_error("TEST POPULATION::TIMESTEP() FAILED: CANNOT GET PREGNANT! \n");
        }
    }
    Penna::Animal::init(maximalAge-1, maximalAge-1, 0.0);   //< make impossible to get pregnant
    test_population.timeStep();                             //< every pregnant Animal will giving birth
    const unsigned int current_size = test_population.size();
    const unsigned int calculated_size = 2*size;
    const unsigned int epsilon = 2; //< In case of Bad RNG, one Animal can die before birth
    if(current_size < calculated_size - epsilon || current_size > calculated_size + epsilon){
        /* check upper and lower bound of the population size */
        throw std::logic_error("TEST POPULATION::TIMESTEP() FAILED: Giving Birth! \n");
    }
    Penna::Animal::init(0, maximalAge- 1, 0);  //< impossible to get pregnant, vulnerable to mutations!
    for(age_t i = 0; i < maximalAge; i++){
        test_population.timeStep();
    }
    if(test_population.survived()){
        throw std::logic_error("TEST POPULATION::TIMESTEP() FAILED: Impossible to survive! \n");
    }
}

int main(){
    TEST_POPULATION_FUNCTIONALITY();
    return 0;
}
