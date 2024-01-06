/* ===================================================================
 * Programming Techniques for Scientific Simulations I  
 * package  :   penna
 * function :   test the basic animal initialization
 * created  :   05/01/2024
 * author   :   DaeBlicki
 * 
 * updated  :   xx/xx/xx
 * VERSION 1.00 (C) Copyright Free to use
 * ===================================================================*/

#include "../include/Penna/animal.hpp"
#include "../include/pt1/Random.hpp"
#include <stdexcept>

void TEST_ANIMAL_BASIC_INITIALIZATION()
{
    const age_t maximalAge = Penna::Animal::maximalAge();
    constexpr double epsilon = 1e-6;
    try{
        // check if reproduction age is maximalAge or bigger
        Penna::Animal::init(5, maximalAge, 0.5);
        throw std::logic_error("TEST_ANIMAL_BASIC_INITIALIZATION FAILED!: Reproduction Age! \n");
    } catch(std::runtime_error& err){}
    try{
        // check if chance to get pregnant is negativ
        Penna::Animal::init(5, 1, 0 - epsilon);
        throw std::logic_error("TEST_ANIMAL_BASIC_INITIALIZATION FAILED!: Chance < 0.00 %! \n");
    } catch(std::runtime_error& err){}
    try{
        // check if chance to get pregnant is bigger than 1
        Penna::Animal::init(5, 1, 1 + epsilon);
        throw std::logic_error("TEST_ANIMAL_BASIC_INITIALIZATION FAILED!: Chance > 100 %! \n");
    } catch(std::runtime_error& err){}
}

int main(){
    TEST_ANIMAL_BASIC_INITIALIZATION();
    return 0;
}