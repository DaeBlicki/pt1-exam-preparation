/* ===================================================================
 * Programming Techniques for Scientific Simulations I  
 * package  :   Simpson Library
 * function :   Print out the sine integration without test of validity
 * created  :   12/01/2024
 * author   :   DaeBlicki
 * 
 * updated  :   xx/xx/xx
 * VERSION 1.00 (C) Copyright Free to use
 * ===================================================================*/

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "../include/Simpson/simpson.hpp"
#include <vector>
#include <iomanip>
#include <iostream>

/* ================================================
 * TEST INTEGRATE SINE FUNCTION BY PRINTING RESULT
 * ================================================*/

TEST_CASE("Simpson Hard Code Sine Function!"){
    const unsigned int N = (1 << 10);  // maximal bins
    const std::vector<double> b_values({
        M_PI,           // pi
        M_PI + M_PI/6,  // pi + 1/6 pi
        M_PI + M_PI_4,  // pi + 1/4 pi
        M_PI + M_PI/3,  // pi + 1/3 pi
        M_PI + M_PI_2,  // pi + 1/2 pi
    });

    const std::vector<std::string> b_values_string({
        "pi",
        "pi + 1/6 pi",
        "pi + 1/4 pi",
        "pi + 1/3 pi",
        "pi + 1/2 pi",
    });

    // integration of sine(x) in (pi/2, b) = cosine(pi/2) - cosine(b) = -cosine(b)
    std::vector<double> expected;
    const unsigned b_size = b_values.size();
    for(unsigned int i = 0; i < b_size; i++){
        expected.push_back(-std::cos(b_values.at(i)));
    }

    // Integration table header
    const std::string line = "--------------------------------------------------";
    for(unsigned int i = 0; i < b_size; i++){
        const double exp = expected.at(i);
        const double b_value = b_values.at(i);
        // Integration Header
        std::cout   << "Integration of sine(x) in interval (pi/2," << b_values_string.at(i) << ")"
                    << "\n" << line << "\n";
        std::cout   << std::setw(5)  << "N" << std::setw(15) << "expected"
                << std::setw(15) << "simpson" << std::setw(15) << "error" << "\n"
                << line << "\n";
        for(unsigned int n = 2; n <= N; n = (n << 1)){
            const double simpson_value = Simpson::integrate_sine(M_PI_2, b_value, n);
            std::cout   << std::setw(5) << n << std::setw(15) << exp << std::setw(15) 
                        << simpson_value << std::setw(15) << std::abs(exp - simpson_value) << "\n";
        }
        std::cout << line << "\n \n";
    }
    CHECK(true);
}