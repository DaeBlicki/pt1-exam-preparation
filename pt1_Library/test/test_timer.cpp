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

#include "../include/Timer.hpp"
#include <unistd.h>

/* ==========================
 *  TEST FOR START AND STOP
 * ==========================*/

TEST_SUITE("Start and Stop"){
    TEST_CASE("Stop after initialization"){
        pt1::Timer T;
        CHECK_THROWS(T.stop());
    }
    TEST_CASE("Start after initialization"){
        pt1::Timer T;
        CHECK_NOTHROW(T.start());
    }
    TEST_CASE("Start after start"){
        pt1::Timer T;
        T.start();
        CHECK_THROWS(T.start());
    }
    TEST_CASE("Stop after start"){
        pt1::Timer T;
        T.start();
        CHECK_NOTHROW(T.stop());
    }
    TEST_CASE("Stop after stop"){
        pt1::Timer T;
        T.start();
        T.stop();
        CHECK_THROWS(T.stop());
    }
}

/* ========================
 *  TEST FOR DATA ACCESS
 * ======================== */

TEST_SUITE("Data access"){
    double duration, mean, min;
    TEST_CASE("Data access after initialization"){
        pt1::Timer T;
        CHECK_THROWS(duration = T.duration());
        CHECK_THROWS(mean = T.mean());
        CHECK_THROWS(min = T.min());
    }
    TEST_CASE("Data access during measurement"){
        pt1::Timer T;
        T.start();
        CHECK_THROWS(duration = T.duration());
        CHECK_THROWS(mean = T.mean());
        CHECK_THROWS(min = T.min());
    }
    TEST_CASE("Data access after measurement"){
        pt1::Timer T;
        T.start() ; 
        usleep(1000);
        T.stop();
        CHECK_NOTHROW(duration = T.duration());
        CHECK_NOTHROW(mean = T.mean());
        CHECK_NOTHROW(min = T.min());
        CHECK(duration == mean);
        CHECK(mean == min);
    }
    TEST_CASE("Data access after reset"){
        pt1::Timer T;
        T.start(); 
        usleep(1000);
        T.stop();
        T.reset();
        CHECK_THROWS(duration = T.duration());
        CHECK_THROWS(mean = T.mean());
        CHECK_THROWS(min = T.min());
    }
}

