/* ===================================================================
 * Programming Techniques for Scientific Simulations I  
 * package  :   pt1_Library
 * function :   test the start and stop function
 * created  :   18/12/2023
 * author   :   DaeBlicki
 * 
 * updated  :   xx/xx/xx
 * VERSION 1.00 (C) Copyright Free to use
 * ===================================================================*/

#include <iostream>
#include <stdexcept>
#include "../include/Timer.hpp"

/* TEST_TIMER_START_AND_STOP() - Test for Timer::start() and Timer::stop()*/
void TEST_TIMER_START_AND_STOP()
{
    // stop after initializing
    pt1::Timer T = pt1::Timer();
    try{
        T.stop();
        throw std::logic_error("TEST_TIMER_START_AND_STOP FAILED: Initialized Timer::stop()! \n");
    } catch(std::runtime_error& err){
        std::cout << "TEST_TIMER_START_AND_STOP PASSED: Initialized Timer::stop()! \n";
    }

    // start after initializing
    try{
        T.start();
        std::cout << "TEST_TIMER_START_AND_STOP PASSED: Initialized Timer::start()! \n";
    } catch(std::runtime_error& err){
        throw std::logic_error("TEST_TIMER_START_AND_STOP FAILED: Initialized Timer::start()! \n");
    }

    // start after start
    T = pt1::Timer();
    try{
        T.start();
        T.start();
        throw std::logic_error("TEST_TIMER_START_AND_STOP FAILED: Timer::start() after Timer::start()!\n");
    } catch(std::runtime_error& err){
        std::cout << "TEST_TIMER_START_AND_STOP PASSED: Initialized Timer::start()! after Timer::start()! \n";
    }

    // stop after start
    T = pt1::Timer();
    try{
        T.start();
        T.stop();
        std::cout << "TEST_TIMER_START_AND_STOP PASSED: Initialized Timer::stop() after Timer::start()! \n";
    } catch(std::runtime_error& err){
        throw std::logic_error("TEST_TIMER_START_AND_STOP FAILED: Timer::stop()! after start() \n");
    }

    // stop after stop
    T = pt1::Timer();
    try{
        T.start();
        T.stop();
        T.stop();
        throw std::logic_error("TEST_TIMER_START_AND_STOP FAILED: Timer::stop() after Timer::stop()!\n");
    } catch(std::runtime_error& err){
        std::cout << "TEST_TIMER_START_AND_STOP PASSED: Timer::stop()! after Timer::stop()! \n";
    }
    std::cout << "TEST_TIMER_START_AND_STOP PASSED! \n";

}

int main(){
    TEST_TIMER_START_AND_STOP();
    return 0;
}