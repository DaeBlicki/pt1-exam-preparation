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
#include <functional>

constexpr double epsilon = 1e-9;

/* ================================================
 * TEST INTEGRATION WITH FUNCTION POINTER
 * ================================================*/
TEST_SUITE("Integration with function pointer"){

    // constant function as function
    double constant1(const double x){ return 1.0;}      // default case
    double constant2(const double x){ return 1./3;}     // floating point case

    // linear function as function
    double linear1(const double x){return x;}           // basic
    double linear2(const double x){return x + 1.0;}     // default
    double linear3(const double x){return (1./3)*x;}    //floating

    // quadratic function as function
    double quadr1(const double x){return x*x;}              // basic
    double quadr2(const double x){return x*x + x + 1.0;}    // default
    double quadr3(const double x){return (1./3)*x*x;}       // float

    // cubic function as function
    double cubic1(const double x){return x*x*x;}                    // basic
    double cubic2(const double x){return x*x*x + x*x + x + 1.0;}    // default
    double cubic3(const double x){return (1./3)*x*x*x;}             // float

    // pointer
    double (*basic_)(const double);     // pointer for basic
    double (*default_)(const double);   // pointer for default
    double (*floating_)(const double);  // pointer for floating

    const double x1 = 0.0;  const double x2 = 1.0;  // [x1, x2] == [0., 1.]
    const unsigned int N = 10;
    TEST_CASE("Constant functions"){
        basic_ = &constant1; default_ = &constant2;
        for(unsigned int n = 1; n <= N; n++){
            CHECK_MESSAGE(std::abs(Simpson::integrate(basic_, x1, x2, n) - constant(1., x1, x2)) < epsilon,
                  "Result: " << Simpson::integrate(basic_, x1, x2, n) << ", Expected: " << constant(1., x1, x2));
            CHECK_MESSAGE(std::abs(Simpson::integrate(default_, x1, x2, n) - constant(1./3, x1, x2)) < epsilon,
                  "Result: " << Simpson::integrate(default_, x1, x2, n) << ", Expected: " << constant(1., x1, x2));
        }
    }
    // LINEAR FUNCTIONS
    TEST_CASE("Linear functions"){
        basic_ = &linear1;
        default_ = &linear2;
        floating_ = &linear3;
        for(unsigned int n = 1; n <= N; n++){
            CHECK_MESSAGE(std::abs(Simpson::integrate(basic_, x1, x2, n) - linear(1., 0., x1, x2)) < epsilon,
                  "Result: " << Simpson::integrate(basic_, x1, x2, n) << ", Expected: " << linear(1., 0, x1, x2));
            CHECK_MESSAGE(std::abs(Simpson::integrate(default_, x1, x2, n) - linear(1., 1., x1, x2)) < epsilon,
                  "Result: " << Simpson::integrate(default_, x1, x2, n) << ", Expected: " << linear(1., 1., x1, x2));
            CHECK_MESSAGE(std::abs(Simpson::integrate(floating_, x1, x2, n) - linear(1./3, 0., x1, x2)) < epsilon,
                  "Result: " << Simpson::integrate(floating_, x1, x2, n) << ", Expected: " << linear(1./3, 0., x1, x2));
        }
    }
     // QUADRATIC FUNCTIONS
    TEST_CASE("Quadratic functions"){
        basic_ = &quadr1;
        default_ = &quadr2;
        floating_ = &quadr3;
        for(unsigned int n = 1; n <= N; n++){
            CHECK_MESSAGE(std::abs(Simpson::integrate(basic_, x1, x2, n) - quadratic(1., 0., 0., x1, x2)) < epsilon,
                  "Result: " << Simpson::integrate(basic_, x1, x2, n) << ", Expected: " << quadratic(1., 0., 0., x1, x2));
            CHECK_MESSAGE(std::abs(Simpson::integrate(default_, x1, x2, n) - quadratic(1., 1., 1., x1, x2)) < epsilon,
                  "Result: " << Simpson::integrate(default_, x1, x2, n) << ", Expected: " << quadratic(1., 1., 1., x1, x2));
            CHECK_MESSAGE(std::abs(Simpson::integrate(floating_, x1, x2, n) - quadratic(1./3, 0., 0., x1, x2)) < epsilon,
                  "Result: " << Simpson::integrate(floating_, x1, x2, n) << ", Expected: " << quadratic(1./3, 0., 0., x1, x2));
        }
    }
     // CUBIC FUNCTIONS
    TEST_CASE("Cubic functions"){
        basic_ = &cubic1;
        default_ = &cubic2;
        floating_ = &cubic3;
        for(unsigned int n = 1; n <= N; n++){
            CHECK_MESSAGE(std::abs(Simpson::integrate(basic_, x1, x2, n) - cubic(1, 0, 0, 0, x1, x2)) < epsilon,
                  "Result: " << Simpson::integrate(basic_, x1, x2, n) << ", Expected: " << cubic(1, 0, 0, 0, x1, x2));
            CHECK_MESSAGE(std::abs(Simpson::integrate(default_, x1, x2, n) - cubic(1, 1, 1, 1, x1, x2)) < epsilon,
                  "Result: " << Simpson::integrate(default_, x1, x2, n) << ", Expected: " << cubic(1, 1, 1, 1, x1, x2));
            CHECK_MESSAGE(std::abs(Simpson::integrate(floating_, x1, x2, n) - cubic(1./3, 0, 0, 0, x1, x2)) < epsilon,
                  "Result: " << Simpson::integrate(floating_, x1, x2, n) << ", Expected: " << cubic(1./3, 0, 0, 0, x1, x2));
        }
    }
}

/* ================================================
 * TEST INTEGRATION WITH FUNCTION OBJECT
 * ================================================*/
TEST_SUITE("Integration with function object"){
    // constant function as function
    using func = std::function<double( const double)>;

    func constant1 = [](const double x) -> double{ return 1.;};   // default 
    func constant2 = [](const double x) -> double{ return 1./3;};   // default 

    // linear function as function
    func linear1 = [](const double x) -> double{ return x;};        // basic 
    func linear2 = [](const double x) -> double{ return x + 1.;};   // default 
    func linear3 = [](const double x) -> double{ return (1./3)*x;}; // float

    // quadratic function as function
    func quadr1 = [](const double x) -> double{ return x*x;};           // basic 
    func quadr2 = [](const double x) -> double{ return x*x + x + 1.;};  // default 
    func quadr3 = [](const double x) -> double{ return (1./3)*x*x;};    // float

    // cubic function as function
    func cubic1 = [](const double x) -> double{ return x*x*x;};                     // basic 
    func cubic2 = [](const double x) -> double{ return x*x*x + x*x + + x + 1.;};    // default 
    func cubic3 = [](const double x) -> double{ return (1./3)*x*x*x;};              // float

    const double x1 = 0.0;  const double x2 = 1.0;  // [x1, x2] == [0., 1.]
    const unsigned int N = 10;
    
    /*
    
    TEST_CASE("Constant functions"){
        for(unsigned int n = 1; n <= N; n++){
            CHECK_MESSAGE(std::abs(Simpson::integrate<func>(constant1, x1, x2, n) - constant(1., x1, x2)) < epsilon,
                  "Result: " << Simpson::integrate<func>(constant1, x1, x2, n) << ", Expected: " << constant(1., x1, x2));
            CHECK_MESSAGE(std::abs(Simpson::integrate<func>(constant2, x1, x2, n) - constant(1./3, x1, x2)) < epsilon,
                  "Result: " << Simpson::integrate<func>(constant2, x1, x2, n) << ", Expected: " << constant(1., x1, x2));
        }
    }
    
    // LINEAR FUNCTIONS
    TEST_CASE("Linear functions"){
        for(unsigned int n = 1; n <= N; n++){
            CHECK_MESSAGE(std::abs(Simpson::integrate<func>(linear1, x1, x2, n) - linear(1., 0., x1, x2)) < epsilon,
                  "Result: " << Simpson::integrate<func>(linear1, x1, x2, n) << ", Expected: " << linear(1., 0, x1, x2));
            CHECK_MESSAGE(std::abs(Simpson::integrate<func>(linear2, x1, x2, n) - linear(1., 1., x1, x2)) < epsilon,
                  "Result: " << Simpson::integrate<func>(linear2, x1, x2, n) << ", Expected: " << linear(1., 1., x1, x2));
            CHECK_MESSAGE(std::abs(Simpson::integrate<func>(linear3, x1, x2, n) - linear(1./3, 0., x1, x2)) < epsilon,
                  "Result: " << Simpson::integrate<func>(linear3, x1, x2, n) << ", Expected: " << linear(1./3, 0., x1, x2));
        }
    }
     // QUADRATIC FUNCTIONS
    TEST_CASE("Quadratic functions"){
        for(unsigned int n = 1; n <= N; n++){
            CHECK_MESSAGE(std::abs(Simpson::integrate<func>(quadr1, x1, x2, n) - quadratic(1., 0., 0., x1, x2)) < epsilon,
                  "Result: " << Simpson::integrate<func>(quadr1, x1, x2, n) << ", Expected: " << quadratic(1., 0., 0., x1, x2));
            CHECK_MESSAGE(std::abs(Simpson::integrate<func>(quadr2, x1, x2, n) - quadratic(1., 1., 1., x1, x2)) < epsilon,
                  "Result: " << Simpson::integrate<func>(quadr2, x1, x2, n) << ", Expected: " << quadratic(1., 1., 1., x1, x2));
            CHECK_MESSAGE(std::abs(Simpson::integrate<func>(quadr3, x1, x2, n) - quadratic(1./3, 0., 0., x1, x2)) < epsilon,
                  "Result: " << Simpson::integrate<func>(quadr3, x1, x2, n) << ", Expected: " << quadratic(1./3, 0., 0., x1, x2));
        }
    }
     // CUBIC FUNCTIONS
    TEST_CASE("Cubic functions"){
        for(unsigned int n = 1; n <= N; n++){
            CHECK_MESSAGE(std::abs(Simpson::integrate<func>(cubic1, x1, x2, n) - cubic(1, 0, 0, 0, x1, x2)) < epsilon,
                  "Result: " << Simpson::integrate<func>(cubic1, x1, x2, n) << ", Expected: " << cubic(1, 0, 0, 0, x1, x2));
            CHECK_MESSAGE(std::abs(Simpson::integrate<func>(cubic2, x1, x2, n) - cubic(1, 1, 1, 1, x1, x2)) < epsilon,
                  "Result: " << Simpson::integrate<func>(cubic2, x1, x2, n) << ", Expected: " << cubic(1, 1, 1, 1, x1, x2));
            CHECK_MESSAGE(std::abs(Simpson::integrate<func>(cubic3, x1, x2, n) - cubic(1./3, 0, 0, 0, x1, x2)) < epsilon,
                  "Result: " << Simpson::integrate<func>(cubic3, x1, x2, n) << ", Expected: " << cubic(1./3, 0, 0, 0, x1, x2));
        }
    }
    */
}


/* ================================================
 * TEST INTEGRATION WITH FUNCTION CLASS
 * ================================================*/
/*
TEST_SUITE("Integration with function class"){

}
*/