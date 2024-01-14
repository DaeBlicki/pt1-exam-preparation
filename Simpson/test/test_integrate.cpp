/* ===================================================================
 * Programming Techniques for Scientific Simulations I  
 * package  :   Simpson Library
 * function :   Test the simpson integration with polynomials
 * created  :   13/01/2024
 * author   :   DaeBlicki
 * 
 * updated  :   xx/xx/xx
 * VERSION 1.00 (C) Copyright Free to use
 * ===================================================================*/

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../include/simpson.hpp"
#include "polynomial.hpp"

constexpr double epsilon = 1e-9;

/* ===========================================
 * SIMPSON INTEGRATION WITH FUNTION CLASSES
 * ===========================================*/
TEST_SUITE("Simpson Integration with Function Classes"){
      TEST_CASE("Constant"){
            Constant monomonial(1. );
            Constant float_case(1./3);
            const double x1 = 0.; const double x2 = 1.;
            for(unsigned int n = 1; n <= 10; n++){
                  CHECK(monomonial(1.) == 1.);
                  CHECK(Simpson::integrate(monomonial, x1, x2, n) == 1.);
                  /*
                  CHECK(std::abs(Simpson::integrate(monomonial, x1, x2, n) - integrateConstant(1., x1, x2)) < epsilon);
                  CHECK(std::abs(Simpson::integrate(float_case, x1, x2, n) - integrateConstant(1./3, x1, x2)) < epsilon);
                  */
            }
      }
}
