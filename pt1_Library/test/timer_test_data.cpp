/* ===================================================================
 * Programming Techniques for Scientific Simulations I  
 * package  :   pt1_Library
 * function :   test access to data
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

    // check validity of the measurement with tolerance 1e-9
    constexpr double tolerance = 0.01;
    for(unsigned int i = 1; i <= 10; i++){
        T.start();
        sleep(i);
        T.stop();
    }
    last_measurement = T.duration();
    mean = T.mean();
    min = T.min();
    const double exp_duration = 10.0;
    const double exp_mean = 5.5;
    const double exp_min = 1.0;

    if(abs(exp_duration - last_measurement) > tolerance){
        throw(std::logic_error("TEST_TIMER_DATA FAILED: Bad Precision for Timer::duration()! \n"));
    }
    if(abs(exp_mean - mean) > tolerance){
        throw(std::logic_error("TEST_TIMER_DATA FAILED: Bad Precision for Timer::mean()! \n"));
    }
    if(abs(exp_min - min) > tolerance){
        throw(std::logic_error("TEST_TIMER_DATA FAILED: Bad Precision for Timer::min()! \n"));
    }
    std::cout <<"TEST_TIMER_DATA PASSED: Good Precision with error < 0.01s! \n";

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