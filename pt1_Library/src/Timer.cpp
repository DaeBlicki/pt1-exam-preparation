/* ===================================================================
 * Programming Techniques for Scientific Simulations I  
 * package  :   pt1_Library
 * function :   measure code segment
 * created  :   18/12/2023
 * author   :   DaeBlicki
 * 
 * updated  :   xx/xx/xx
 * VERSION 1.00 (C) Copyright Free to use
 * ===================================================================*/

#include "../include/Timer.hpp"

// nanmespace pt1 library
namespace pt1{

void Timer::checkRunning() const
{
    if(measuring_){
        throw std::runtime_error("The timer is measuring at the moment");
    }
}

void Timer::checkEmptyHistory() const
{
    if(history_.empty()){
        throw std::runtime_error("The timer has not any measured data");
    }
}

bool Timer::isMeasuring()
{
    return measuring_;
}

void Timer::start()
{
    // throw exception if the Timer is measuring
    checkRunning();
    measuring_ = true;
    ending_time_ = starting_time_;
    starting_time_ = clock::now();

}

void Timer::stop()
{
    // throw exception if the Timer is not measuring
    ending_time_ = clock::now();
    if(!measuring_){
        throw std::runtime_error("The timer is not measuring at the moment");
    }
    // update last measurement
    duration_t duration_time = ending_time_ - starting_time_;
    auto conversion = std::chrono::duration_cast<precision>(duration_time);
    last_measurement_ = double(conversion.count())/ divisor_;
    // update the min time if necessary
    if(last_measurement_ < min_ || history_.empty()){
        min_ = last_measurement_;
    }
       // update measurement history
    history_.push_back(last_measurement_);
    measuring_ = false;
}

void Timer::reset()
{    
    checkRunning();
    history_ = std::vector<double>();
}

double Timer::duration() const 
{
    checkEmptyHistory();
    checkRunning();
    return last_measurement_;
}

double Timer::min() const{
    checkEmptyHistory();
    checkRunning();
    return min_;
}

double Timer::mean() const{
    checkEmptyHistory();
    checkRunning();
    const size_t history_size = history_.size();
    double sum = 0.;
    for(size_t i = 0; i < history_size; i++){
        sum += history_.at(i);
    }
    const double mean = sum / history_size;
    return mean;
}

} // end namespace pt1