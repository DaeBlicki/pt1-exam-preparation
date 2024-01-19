/* ===================================================================
 * Programming Techniques for Scientific Simulations I  
 * package  :   Simpson Library
 * function :   Test the simpson integration for 2-dimension
 * created  :   19/01/2024
 * author   :   DaeBlicki
 * 
 * updated  :   xx/xx/xx
 * VERSION 1.00 (C) Copyright Free to use
 * ===================================================================*/

#include "../include/Simpson/simpson.hpp"
#include <cmath>
#include <iostream>


#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

constexpr double epsilon = 1e-5;

TEST_SUITE("2D-Integration"){
    TEST_CASE("Integration on unit disk"){
        auto f = [](const double x, const double y) -> double{
            if(x*x + y*y <= 1.){
                return 1.;
            }
            return 0.;
        };
        CHECK(std::abs(Simpson::integrate2d(f, -1, 1, -1, 1, 50) - M_PI) < epsilon);
    }
    TEST_CASE("Integration on density function"){
        CHECK(true);
        auto f = [](const double x, const double y) -> double{
            constexpr double R = 1.7606;
            const double disc = x*x + y*y;
            if(disc <= R){
                return std::exp(-disc);
            }
            return 0.;
        };
        std::cout   << "The result of the Simpson Integration : "
                    << Simpson::integrate2d(f, -1, 1, -1, 1, 50) << "\n";
    }
}