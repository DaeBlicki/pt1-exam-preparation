/* ===================================================================
 * Programming Techniques for Scientific Simulations I  
 * package  :   pt1_Library
 * function :   test access to data
 * created  :   18/12/2023
 * author   :   DaeBlicki
 * 
 * updated  :   06/01/2024
 * message  :   removed precision test in this file
 * VERSION 1.01 (C) Copyright Free to use
 * ===================================================================*/

#include <iostream>
#include <stdexcept>
#include <unistd.h>
#include "../include/Timer.hpp"

void TEST_TIMER_DATA()
{
    pt1::Timer T = pt1::Timer();
    double last_measurement;
    double mean;
    double min;

    // try get data without any data
    try{
        last_measurement = T.duration();
        throw(std::logic_error("TEST_TIMER_DATA FAILED: Initialized Timer::duration()!  \n"));
    } catch(std::runtime_error& err){
        try{
            mean = T.mean();
            throw(std::logic_error("TEST_TIMER_DATA FAILED: Initialized Timer::mean()!  \n"));
        } catch(std::runtime_error& err){
            try{
                min = T.min();
                throw(std::logic_error("TEST_TIMER_DATA FAILED: Initialized Timer::min()!  \n"));
            }catch(std::runtime_error& err){
                std::cout << "TEST_TIMER_DATA PASSED: No access on data without any data!  \n";
            }
        }
    }

    // try get data during measurement
    T.start();
    try{
        last_measurement = T.duration();
        throw(std::logic_error("TEST_TIMER_DATA FAILED: Measuring Timer::duration()!  \n"));
    } catch(std::runtime_error& err){
        try{
            mean = T.mean();
            throw(std::logic_error("TEST_TIMER_DATA FAILED: Measuring Timer::mean()!  \n"));
        } catch(std::runtime_error& err){
            try{
                min = T.min();
                throw(std::logic_error("TEST_TIMER_DATA FAILED: Measuring Timer::min()!  \n"));
            }catch(std::runtime_error& err){
                std::cout << "TEST_TIMER_DATA PASSED: No access on data during measurement!  \n";
            }
        }
    }
    T.stop();
    std::cout << "TEST_TIMER_DATA PASSED!  \n";

}

int main(){
    TEST_TIMER_DATA();
    return 0;
}