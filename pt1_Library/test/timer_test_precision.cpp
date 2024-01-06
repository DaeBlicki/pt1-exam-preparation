/* ===================================================================
 * Programming Techniques for Scientific Simulations I  
 * package  :   pt1_Library
 * function :   test the precision of the timer class
 * created  :   06/01/2024
 * author   :   DaeBlicki
 * 
 * updated  :   xx/xx/xx
 * VERSION 1.00 (C) Copyright Free to use
 * ===================================================================*/

#include <iostream>
#include <stdexcept>
#include <unistd.h>
#include "../include/Timer.hpp"

void TEST_TIMER_PRECISION()
{
    double mean, min, last_measurement;
    pt1::Timer T = pt1::Timer();
    // check validity of the measurement with tolerance 20 microsecond
    constexpr double tolerance = 20*1e-6;
    const unsigned int time_step_in_microseconds = 50;
    const unsigned int min_in_microseconds = 10;
    const unsigned int max_in_microseconds = 90; 
    // iterate 1000 with 50 ms
    for(unsigned int i = 0; i < 1000; i++){
        T.start();
        usleep(time_step_in_microseconds);
        T.stop();
    }
    // add min value
    T.start();
    usleep(min_in_microseconds);
    T.stop();
    // compensate with max value
    T.start();
    usleep(max_in_microseconds);
    T.stop();

    last_measurement = T.duration();
    mean = T.mean();
    min = T.min();
    const double exp_duration = 90 * 1e-6;
    const double exp_mean = 50 * 1e-6;
    const double exp_min = 10 * 1e-6;

    std::cout << exp_duration << " " << exp_mean << " " << exp_min << std::endl;
    std::cout << last_measurement << " " << mean << " " << min << std::endl;
    std::cout   << std::abs(exp_duration - last_measurement) << "\n"
                << std::abs(exp_mean - mean) << "\n"
                << std::abs(exp_min - min) << "\n";


    if(std::abs(exp_duration - last_measurement) < tolerance){
        throw(std::logic_error("TEST_TIMER_DATA FAILED: Bad Precision for Timer::duration()! \n"));
    }
    if(std::abs(exp_mean - mean) < tolerance){
        throw(std::logic_error("TEST_TIMER_DATA FAILED: Bad Precision for Timer::mean()! \n"));
    }
    if(std::abs(exp_min - min) < tolerance){
        throw(std::logic_error("TEST_TIMER_DATA FAILED: Bad Precision for Timer::min()! \n"));
    }
    std::cout <<"TEST_TIMER_DATA PASSED: Good Precision with error <" << tolerance << "s \n";
}

int main(){
    TEST_TIMER_PRECISION();
    return 0;
}