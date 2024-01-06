/* ===================================================================
 * Programming Techniques for Scientific Simulations I  
 * package  :   pt1_Library
 * function :   test random number generator
 * created  :   18/12/2023
 * author   :   DaeBlicki
 * 
 * updated  :   xx/xx/xx
 * VERSION 1.00 (C) Copyright Free to use
 * ===================================================================*/

#include "../include/Random.hpp"
#include <iostream>
#include <stdexcept>

// RNG Initialization Test
void TEST_RANDOM_INITIALIZATION()
{
    const uint64_t exp_max = (UINT16_C(1) << 31) - 1;
    const uint32_t first = pt1::Random_Number_Generator::generate();
    const uint32_t second = pt1::Random_Number_Generator::generate();
    const uint64_t max = pt1::Random_Number_Generator::max();
    pt1::Random_Number_Generator::seed(42);
    const uint32_t first_after_seed = pt1::Random_Number_Generator::generate();

    if(first == second){
        throw std::logic_error("RANDOM TEST FAILED: First and second should be distinct! \n");
    }
    if(max != exp_max){
        std::cerr << max << std::endl;
        std::cerr << exp_max - 1<< std::endl;
        throw std::logic_error("RANDOM TEST FAILED: RNG::max()! \n");
    }
    if(first != first_after_seed){
        throw std::logic_error("RANDOM TEST FAILED: RNG::seed()! \n");
    }
    std::cout << "RANDOM TEST PASSED! \n";
}

int main(){
    TEST_RANDOM_INITIALIZATION();
    return 0;
}