/* ===================================================================
 * Programming Techniques for Scientific Simulations I  
 * package  :   pt1 Library
 * function :   Tests for the random number generator
 * created  :   16/01/2024
 * author   :   DaeBlicki
 * 
 * VERSION 1.00 (C) Copyright Free to use
 * ===================================================================*/

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "../include/Random.hpp"
#include <unistd.h>

TEST_SUITE("Random number generator"){
    const uint64_t exp_max = (UINT16_C(1) << 31) - 1;
    const uint32_t first = pt1::Random_Number_Generator::generate();
    const uint32_t second = pt1::Random_Number_Generator::generate();
    TEST_CASE("Check randomness"){
        CHECK(first != second);
    }
    TEST_CASE("Check seed"){
        pt1::Random_Number_Generator::seed(42);
        CHECK(first == pt1::Random_Number_Generator::generate());
    }
    TEST_CASE("Check max"){
        CHECK(exp_max == pt1::Random_Number_Generator::max());
    }
    TEST_CASE("Coin tossing"){
        constexpr double epsilon = 1e-3;
        const unsigned int it = 1000000;
        double sum = 0.;
        for(unsigned int i = 0; i < it; i++){
            sum += pt1::Random_Number_Generator::coin();
        }
        double mean = sum / it;
        CHECK(std::abs(mean - 0.5) < epsilon);
    }

}