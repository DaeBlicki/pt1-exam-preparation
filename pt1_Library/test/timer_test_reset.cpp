/* ===================================================================
 * Programming Techniques for Scientific Simulations I  
 * package  :   pt1_Library
 * function :   test the reset function
 * created  :   18/12/2023
 * author   :   DaeBlicki
 * 
 * updated  :   xx/xx/xx
 * VERSION 1.00 (C) Copyright Free to use
 * ===================================================================*/

#include <iostream>
#include <stdexcept>
#include <unistd.h>
#include "../include/Timer.hpp"

void TEST_TIMER_RESET()
{
    // Filling Timer History and then reset
    pt1::Timer T = pt1::Timer();
    for(unsigned int i = 0; i < 5; i++){
        T.start();
        sleep(1);
        T.stop();
    }
    T.reset();

    // Check reset by accessing data
    try{
        T.duration();
        throw std::logic_error("TEST_TIMER_RESET FAILED: Reset did not worked ! \n");
    } catch(std::runtime_error& err){
        std::cout << "TEST_TIMER_RESET PASSED: Reset worked! \n";
    }

    // Reset during measurement
    try{
        T.start();
        T.reset();
        throw std::logic_error("TEST_TIMER_RESET FAILED: Resetted during measurment ! \n");
    } catch(std::runtime_error& err){
        std::cout << "TEST_TIMER_RESET PASSED: Can not reset during measurement! \n";
    }
    
    std::cout << "TEST_TIMER_RESET PASSED! \n";
}

int main(){
    TEST_TIMER_RESET();
    return 0;
}