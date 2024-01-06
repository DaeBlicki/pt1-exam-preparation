/* ===================================================================
 * Programming Techniques for Scientific Simulations I  
 * package  :   pt1_Library
 * function :   test the isMeasuring function
 * created  :   18/12/2023
 * author   :   DaeBlicki
 * 
 * updated  :   xx/xx/xx
 * VERSION 1.00 (C) Copyright Free to use
 * ===================================================================*/

#include <iostream>
#include <stdexcept>
#include "../include/Timer.hpp"

void TEST_TIMER_IS_MEASURING()
{
    pt1::Timer T = pt1::Timer();

    // initialized Timer
    if(T.isMeasuring()){
        throw std::logic_error("TEST_TIMER_IS_MEASURING FAILED: initialized Timer \n");
    }
    // Timer during measuring mode
    T.start();
    if(!T.isMeasuring()){
        throw std::logic_error("TEST_TIMER_IS_MEASURING FAILED: measuring Timer gives wrong return value! \n");
    }
    // Timer during rest mode
    T.stop();
    if(T.isMeasuring()){
        throw std::logic_error("TEST_TIMER_IS_MEASURING FAILED: not measuring Timer gives wrong return value! \n");
    }
    std::cout << "TEST_TIMER_IS_MEASURING PASSED! \n";
}

int main(){
    TEST_TIMER_IS_MEASURING();
    return 0;
}