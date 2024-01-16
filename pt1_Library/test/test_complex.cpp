/* ===================================================================
 * Programming Techniques for Scientific Simulations I  
 * package  :   pt1 Library
 * function :   Tests for the timer class
 * created  :   16/01/2024
 * author   :   DaeBlicki
 * 
 * VERSION 1.00 (C) Copyright Free to use
 * ===================================================================*/

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../include/Complex.hpp"

/* =========================
 * Test for Constructors
 * =========================*/

TEST_SUITE("Constructor"){
    TEST_CASE("Default Constructor"){
        CHECK(pt1::Complex().getReal() == 0.);
        CHECK(pt1::Complex().getImaginary() == 0.);
    }
    TEST_CASE("Copy Constructor"){
        pt1::Complex a(3.0, 4.0);
        REQUIRE(a.getReal() == 3.);
        REQUIRE(a.getImaginary() == 4.);

        pt1::Complex b(a);
        CHECK(a.getReal() == b.getReal());
        CHECK(a.getImaginary() == b.getImaginary());
    }
}

/* =============================
 * Tests for Logical Operators
 * ============================= */

TEST_SUITE("Logical Assignments"){
    TEST_CASE("Assignment: == "){
        CHECK(pt1::Complex(4.0, 3.0) == pt1::Complex(4.0, 3.0));
    }
    TEST_CASE("Assignment: != "){
        CHECK(pt1::Complex(4.0, 3.0) != pt1::Complex(4.0, 0.0));
        CHECK(pt1::Complex(4.0, 3.0) != pt1::Complex(0.0, 3.0));
        CHECK(pt1::Complex(4.0, 3.0) != pt1::Complex(3.0, 4.0));
    }
}


/* =================================
 * Tests for Assignments Operators
 * =================================*/

TEST_SUITE("Assignement operators"){
    TEST_CASE("Assignment: ="){
        pt1::Complex a(4.0, 3.0);
        pt1::Complex b = a;
        CHECK(a == b);
    }
    TEST_CASE("Assignement : += "){
        pt1::Complex a(4.0, 3.0);
        a += pt1::Complex(4.0, 3.0);
        CHECK(a.getReal() == 8.0);
        CHECK(a.getImaginary() == 6.0);
    }
    TEST_CASE("Assignement : -="){
        pt1::Complex a(4.0, 3.0);
        a -= pt1::Complex(3.0, 2.0);
        CHECK(a.getReal() == 1.0);
        CHECK(a.getImaginary() == 1.0);
    }
    TEST_CASE("Assignement : /= "){
        pt1::Complex a(4.0, 3.0);
        a /= pt1::Complex(4.0, 3.0);
        CHECK(a.getReal() == 1.0);
        CHECK(a.getImaginary() == 0.0);
    }
    TEST_CASE("Assignement : *= "){
        pt1::Complex a(4.0, 3.0);
        a *= pt1::Complex(4.0, 3.0);
        CHECK(a.getReal() == 7.0);
        CHECK(a.getImaginary() == 24.0);
    }
}

/* =================================
 * Tests for Arithmetic Operators
 * =================================*/

TEST_SUITE("Arithmetic Operators"){
    TEST_CASE("Assignement : + "){
        pt1::Complex a(4.0, 3.0);
        a = a + pt1::Complex(4.0, 3.0);
        CHECK(a.getReal() == 8.0);
        CHECK(a.getImaginary() == 6.0);
    }
    TEST_CASE("Assignement : - "){
        pt1::Complex a(4.0, 3.0);
        a = a - pt1::Complex(3.0, 2.0);
        CHECK(a.getReal() == 1.0);
        CHECK(a.getImaginary() == 1.0);
    }
    TEST_CASE("Assignement : / "){
        pt1::Complex a(4.0, 3.0);
        a = a / pt1::Complex(4.0, 3.0);
        CHECK(a.getReal() == 1.0);
        CHECK(a.getImaginary() == 0.0);
    }
    TEST_CASE("Assignement : * "){
        pt1::Complex a(4.0, 3.0);
        a =  a * pt1::Complex(4.0, 3.0);
        CHECK(a.getReal() == 7.0);
        CHECK(a.getImaginary() == 24.0);
    }
}
