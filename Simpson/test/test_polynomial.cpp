/* ===================================================================
 * Programming Techniques for Scientific Simulations I  
 * package  :   Simpson Library
 * function :   Test file for polynomial functions
 * created  :   14/01/2024
 * author   :   DaeBlicki
 * 
 * updated  :   xx/xx/xx
 * VERSION 1.00 (C) Copyright Free to use
 * ===================================================================*/

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../include/Simpson/polynomial.hpp"

constexpr double epsilon = 1e-12;

/* ==================================
 * POLYNOMIAL CLASS TEST SUITE
 * ==================================*/

TEST_SUITE("Polynomial Classes"){
    TEST_CASE("Constant class"){
        SUBCASE("Monomonial"){
            Constant monomonial(1.);
            CHECK(std::abs(monomonial(0.) - 1.) < epsilon);
            CHECK(std::abs(monomonial(1.) - 1.) < epsilon);
            CHECK(std::abs(monomonial(1./3) - 1.) < epsilon);
        }
        SUBCASE("Single float coefficient"){
            Constant float_case(1./3);
            CHECK(std::abs(float_case(0.) - 1./3) < epsilon);
            CHECK(std::abs(float_case(1.) - 1./3) < epsilon);
            CHECK(std::abs(float_case(1./3) - 1./3) < epsilon);
        }
    }
    TEST_CASE("Linear class"){
        SUBCASE("Monomonial"){
            Linear monomonial(1., 0.);
            CHECK(std::abs(monomonial(0.) - 0.) < epsilon);
            CHECK(std::abs(monomonial(1.) - 1.) < epsilon);
            CHECK(std::abs(monomonial(1./3) - 1./3) < epsilon);
        }
        SUBCASE("Ones Coefficient"){
            Linear ones(1., 1.);
            CHECK(std::abs(ones(0.) - 1.) < epsilon);
            CHECK(std::abs(ones(1.) - 2.) < epsilon);
            CHECK(std::abs(ones(1./3) - 4./3) < epsilon);
        }
        SUBCASE("Single float coefficient"){
            Linear float_case(1./3, 0.);
            CHECK(std::abs(float_case(0.) - 0.) < epsilon);
            CHECK(std::abs(float_case(1.) - 1./3) < epsilon);
            CHECK(std::abs(float_case(1./3) - 1./9) < epsilon);
        }
    }
    TEST_CASE("Quadratic class"){
        SUBCASE("Monomonial"){
            Quadratic monomonial(1., 0., 0.);
            CHECK(std::abs(monomonial(0.) - 0.) < epsilon);
            CHECK(std::abs(monomonial(1.) - 1.) < epsilon);
            CHECK(std::abs(monomonial(1./3) - 1./9) < epsilon);
        }
        SUBCASE("Ones Coefficient"){
            Quadratic ones(1., 1., 1.);
            CHECK(std::abs(ones(0.) - 1.) < epsilon);
            CHECK(std::abs(ones(1.) - 3.) < epsilon);
            CHECK(std::abs(ones(1./3) - 13./9) < epsilon);
        }
        SUBCASE("Single float coefficient"){
            Quadratic float_case(1./3, 0., 0.);
            CHECK(std::abs(float_case(0.) - 0.) < epsilon);
            CHECK(std::abs(float_case(1.) - 1./3) < epsilon);
            CHECK(std::abs(float_case(1./3) - 1./27) < epsilon);
        }
    }
    TEST_CASE("Cubic class"){
        SUBCASE("Monomonial"){
            Cubic monomonial(1., 0., 0., 0.);
            CHECK(std::abs(monomonial(0.) - 0.) < epsilon);
            CHECK(std::abs(monomonial(1.) - 1.) < epsilon);
            CHECK(std::abs(monomonial(1./3) - 1./27) < epsilon);
        }
        SUBCASE("Ones Coefficient"){
            Cubic ones(1., 1., 1., 1.);
            CHECK(std::abs(ones(0.) - 1.) < epsilon);
            CHECK(std::abs(ones(1.) - 4.) < epsilon);
            CHECK(std::abs(ones(1./3) - 40./27) < epsilon);
        }
        SUBCASE("Single float coefficient"){
            Cubic float_case(1./3, 0., 0., 0.);
            CHECK(std::abs(float_case(0.) - 0.) < epsilon);
            CHECK(std::abs(float_case(1.) - 1./3) < epsilon);
            CHECK(std::abs(float_case(1./3) - 1./81) < epsilon);
        }
    }
}

/* ==================================
 * POLYNOMIAL FUNCTION TEST SUITE
 * ==================================*/

TEST_SUITE("Polynomial Functions"){
   TEST_CASE("Constant function"){
        SUBCASE("Monomonial"){
            auto monomonial = [](double x) -> double{ return constant(x, 1.);};
            CHECK(std::abs(monomonial(0.) - 1.) < epsilon);
            CHECK(std::abs(monomonial(1.) - 1.) < epsilon);
            CHECK(std::abs(monomonial(1./3) - 1.) < epsilon);
        }
        SUBCASE("Single float coefficient"){
            auto float_case = [](double x) -> double{ return constant(x, 1./3);};
            CHECK(std::abs(float_case(0.) - 1./3) < epsilon);
            CHECK(std::abs(float_case(1.) - 1./3) < epsilon);
            CHECK(std::abs(float_case(1./3) - 1./3) < epsilon);
        }
    }
    TEST_CASE("Linear function"){
        SUBCASE("Monomonial"){
            auto monomonial = [](double x) -> double{ return linear(x, 1., 0.);};
            CHECK(std::abs(monomonial(0.) - 0.) < epsilon);
            CHECK(std::abs(monomonial(1.) - 1.) < epsilon);
            CHECK(std::abs(monomonial(1./3) - 1./3) < epsilon);
        }
        SUBCASE("Ones Coefficient"){
            auto ones = [](double x) -> double{ return linear(x, 1., 1.);};
            CHECK(std::abs(ones(0.) - 1.) < epsilon);
            CHECK(std::abs(ones(1.) - 2.) < epsilon);
            CHECK(std::abs(ones(1./3) - 4./3) < epsilon);
        }
        SUBCASE("Single float coefficient"){
            auto float_case = [](double x) -> double{ return linear(x, 1./3, 0.);};
            CHECK(std::abs(float_case(0.) - 0.) < epsilon);
            CHECK(std::abs(float_case(1.) - 1./3) < epsilon);
            CHECK(std::abs(float_case(1./3) - 1./9) < epsilon);
        }
    }
    TEST_CASE("Quadratic function"){
        SUBCASE("Monomonial"){
            auto monomonial = [](double x) -> double{ return quadratic(x, 1., 0.,0.);};
            CHECK(std::abs(monomonial(0.) - 0.) < epsilon);
            CHECK(std::abs(monomonial(1.) - 1.) < epsilon);
            CHECK(std::abs(monomonial(1./3) - 1./9) < epsilon);
        }
        SUBCASE("Ones Coefficient"){
            auto ones = [](double x) -> double{ return quadratic(x, 1., 1.,1.);};
            CHECK(std::abs(ones(0.) - 1.) < epsilon);
            CHECK(std::abs(ones(1.) - 3.) < epsilon);
            CHECK(std::abs(ones(1./3) - 13./9) < epsilon);
        }
        SUBCASE("Single float coefficient"){
            auto float_case = [](double x) -> double{ return quadratic(x, 1./3, 0.,0.);};
            CHECK(std::abs(float_case(0.) - 0.) < epsilon);
            CHECK(std::abs(float_case(1.) - 1./3) < epsilon);
            CHECK(std::abs(float_case(1./3) - 1./27) < epsilon);
        }
    }
    TEST_CASE("Cubic function"){
        SUBCASE("Monomonial"){
            auto monomonial = [](double x) -> double{ return cubic(x, 1., 0., 0.,0.);};
            CHECK(std::abs(monomonial(0.) - 0.) < epsilon);
            CHECK(std::abs(monomonial(1.) - 1.) < epsilon);
            CHECK(std::abs(monomonial(1./3) - 1./27) < epsilon);
        }
        SUBCASE("Ones Coefficient"){
            auto ones = [](double x) -> double{ return cubic(x, 1., 1., 1., 1.);};
            CHECK(std::abs(ones(0.) - 1.) < epsilon);
            CHECK(std::abs(ones(1.) - 4.) < epsilon);
            CHECK(std::abs(ones(1./3) - 40./27) < epsilon);
        }
        SUBCASE("Single float coefficient"){
            auto float_case = [](double x) -> double{ return cubic(x, 1./3, 0., 0., 0.);};
            CHECK(std::abs(float_case(0.) - 0.) < epsilon);
            CHECK(std::abs(float_case(1.) - 1./3) < epsilon);
            CHECK(std::abs(float_case(1./3) - 1./81) < epsilon);
        }
    }
}

/* ==================================
 * POLYNOMIAL INTEGRATION TEST SUITE
 * ==================================*/

TEST_SUITE("Polynomial Integration"){
   TEST_CASE("Constant integration"){
        SUBCASE("Interval [0, 1]"){
            const double x1 = 0.; const double x2 = 1.;
            CHECK(std::abs(integrateConstant(1., x1, x2) - 1.) < epsilon);
            CHECK(std::abs(integrateConstant(1./3, x1, x2) - 1./3) < epsilon);
        }
        SUBCASE("Interval [-1, 1]"){
            const double x1 = -1.; const double x2 = 1.;
            CHECK(std::abs(integrateConstant(1., x1, x2) - 2.) < epsilon);
            CHECK(std::abs(integrateConstant(1./3, x1, x2) - 2./3) < epsilon);
        }
    }
    TEST_CASE("Linear integration"){
        SUBCASE("Interval [0, 1]"){
            const double x1 = 0.; const double x2 = 1.;
            CHECK(std::abs(integrateLinear(1., 0., x1, x2) - 1./2) < epsilon);
            CHECK(std::abs(integrateLinear(1., 1., x1, x2) - 3./2) < epsilon);
            CHECK(std::abs(integrateLinear(1./3, 0., x1, x2) - 1./6) < epsilon);
        }
        SUBCASE("Interval [-1, 1]"){
            const double x1 = -1.; const double x2 = 1.;
            CHECK(std::abs(integrateLinear(1., 0., x1, x2) - 0.) < epsilon);
            CHECK(std::abs(integrateLinear(1., 1., x1, x2) - 2.) < epsilon);
            CHECK(std::abs(integrateLinear(1./3, 0., x1, x2) - 0.) < epsilon);
        }
    }
    TEST_CASE("Quadratic integration"){
        SUBCASE("Interval [0, 1]"){
            const double x1 = 0.; const double x2 = 1.;
            CHECK(std::abs(integrateQuadratic(1., 0., 0., x1, x2) - 1./3) < epsilon);
            CHECK(std::abs(integrateQuadratic(1., 1., 1., x1, x2) - 11./6) < epsilon);
            CHECK(std::abs(integrateQuadratic(1./3, 0., 0., x1, x2) - 1./9) < epsilon);
        }
        SUBCASE("Interval [-1, 1]"){
            const double x1 = -1.; const double x2 = 1.;
            CHECK(std::abs(integrateQuadratic(1., 0., 0., x1, x2) - 2./3) < epsilon);
            CHECK(std::abs(integrateQuadratic(1., 1., 1., x1, x2) - 8./3) < epsilon);
            CHECK(std::abs(integrateQuadratic(1./3, 0., 0., x1, x2) - 2./9) < epsilon);
        }
    }
    TEST_CASE("Cubic integration"){
        SUBCASE("Interval [0, 1]"){
            const double x1 = 0.; const double x2 = 1.;
            CHECK(std::abs(integrateCubic(1., 0., 0., 0., x1, x2) - 1./4) < epsilon);
            CHECK(std::abs(integrateCubic(1., 1., 1., 1., x1, x2) - 25./12) < epsilon);
            CHECK(std::abs(integrateCubic(1./3, 0., 0., 0., x1, x2) - 1./12) < epsilon);
        }
        SUBCASE("Interval [-1, 1]"){
            const double x1 = -1.; const double x2 = 1.;
            CHECK(std::abs(integrateCubic(1., 0., 0., 0., x1, x2) - 0.) < epsilon);
            CHECK(std::abs(integrateCubic(1., 1., 1., 1., x1, x2) - 8./3) < epsilon);
            CHECK(std::abs(integrateCubic(1./3, 0., 0., 0., x1, x2) - 0.) < epsilon);
        }
    }
}