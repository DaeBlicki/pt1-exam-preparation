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

#include "../include/simpson.hpp"
#include "../include/polynomial.hpp"
#include <iostream>


#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

constexpr double epsilon = 1e-15;

/* =======================================================
 * TEST THE GENERIC IMPLEMENTATIONS OF INTEGRATE FUNCTION
 * ========================================================*/
TEST_SUITE("Simpson Integration with Generic Function"){
      const double x1 = 0.;   const double x2 = 1.;
      const double a = 1.;    const double b = 1.;
      const double c = 1.;    const double d = 1.;
      /* ======================================
       * INTEGRATION WITH FUNCTION CLASS
       * ======================================*/
      TEST_CASE("Function class"){
            for(unsigned int n = 1; n <= 10; n++){
                  CHECK(std::abs(Simpson::integrate(Constant(a), x1, x2, n) 
                                    - integrateConstant(a, x1, x2)) < epsilon);
                  CHECK(std::abs(Simpson::integrate(Linear(a, b), x1, x2, n) 
                                    - integrateLinear(a, b, x1, x2)) < epsilon);
                  CHECK(std::abs(Simpson::integrate(Quadratic(a, b, c), x1, x2, n) 
                                    - integrateQuadratic(a, b, c, x1, x2)) < epsilon); 
                  CHECK(std::abs(Simpson::integrate(Cubic(a, b, c, d), x1, x2, n) 
                                    - integrateCubic(a, b, c, d, x1, x2)) < epsilon);
            }
      }
      /* ======================================
       * INTEGRATION WITH LAMBDA FUNCTIONS
       * ======================================*/
      TEST_CASE("Lambda Function"){
            // Define Lambda functions
            auto con = [](const double x) -> double{ return a;};
            auto lin = [](const double x) -> double{ return a*x + b;};
            auto quad = [](const double x) -> double{ return a*x*x + b*x + c;};
            auto cub = [](const double x) -> double{ return a*x*x*x + b*x*x + c*x + d;};

            for(unsigned int n = 1; n <= 10; n++){
                  CHECK(std::abs(Simpson::integrate(con, x1, x2, n) 
                                    - integrateConstant(a, x1, x2)) < epsilon);
                  CHECK(std::abs(Simpson::integrate(lin, x1, x2, n) 
                                    - integrateLinear(a, b, x1, x2)) < epsilon);
                  CHECK(std::abs(Simpson::integrate(quad, x1, x2, n) 
                                    - integrateQuadratic(a, b, c, x1, x2)) < epsilon); 
                  CHECK(std::abs(Simpson::integrate(cub, x1, x2, n) 
                                    - integrateCubic(a, b, c, d, x1, x2)) < epsilon);
            }
      }
      /* =============================================================
       * DEFINE FUNCTIONS FOR FUNCTION OBJECTS AND FUNCTION POINTERS
       * =============================================================*/

      double con(const double x){ return constant(x, a);}
      double lin(const double x){ return linear(x, a, b);}
      double quad(const double x){ return quadratic(x, a, b, c);}
      double cub(const double x){ return cubic(x, a, b, c, d);}

      /* ======================================
       * INTEGRATION WITH FUNCTION POINTER
       * ======================================*/
      TEST_CASE("Function Pointer"){
            double (*func_ptr)(const double x);
            for(unsigned int n = 1; n <= 10; n++){
                  func_ptr = &con;
                  CHECK(std::abs(Simpson::integrate(func_ptr, x1, x2, n) 
                                    - integrateConstant(a, x1, x2)) < epsilon);
                  func_ptr = &lin;
                  CHECK(std::abs(Simpson::integrate(func_ptr, x1, x2, n) 
                                    - integrateLinear(a, b, x1, x2)) < epsilon);
                  func_ptr = &quad;
                  CHECK(std::abs(Simpson::integrate(func_ptr, x1, x2, n) 
                                    - integrateQuadratic(a, b, c, x1, x2)) < epsilon); 
                  func_ptr = &cub;
                  CHECK(std::abs(Simpson::integrate(func_ptr, x1, x2, n) 
                                    - integrateCubic(a, b, c, d, x1, x2)) < epsilon);
            }
      }
      /* ======================================
       * INTEGRATION WITH FUNCTION OBJECTS
       * ======================================*/
      TEST_CASE("Fuction Object"){
            for(unsigned int n = 1; n <= 10; n++){
                  CHECK(std::abs(Simpson::integrate(con, x1, x2, n) 
                                    - integrateConstant(a, x1, x2)) < epsilon);
                  CHECK(std::abs(Simpson::integrate(lin, x1, x2, n) 
                                    - integrateLinear(a, b, x1, x2)) < epsilon);
                  CHECK(std::abs(Simpson::integrate(quad, x1, x2, n) 
                                    - integrateQuadratic(a, b, c, x1, x2)) < epsilon); 
                  CHECK(std::abs(Simpson::integrate(cub, x1, x2, n) 
                                    - integrateCubic(a, b, c, d, x1, x2)) < epsilon);
            }
      }
}
