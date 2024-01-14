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

#include "Timer.hpp"

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
    starting_time_ = clock::now();
    ending_time_ = starting_time_;

}

void Timer::stop()
{
    // throw exception if the Timer is not measuring
    if(!measuring_){
        throw std::runtime_error("The timer is not measuring at the moment");
    }
    ending_time_ = clock::now();
    duration_t duration_time = ending_time_ - starting_time_;
    // update last measurement
    last_measurement_ = duration_time;
    // update the min time if necessary
    if(duration_time < min_ || history_.empty()){
        min_ = duration_time;
    }
       // update measurement history
    history_.push_back(duration_time);
    measuring_ = false;
}

void Timer::reset()
{    
    checkRunning();
    history_ = std::vector<duration_t>();
}

double Timer::duration() const 
{
    checkEmptyHistory();
    checkRunning();
    precision duration = std::chrono::duration_cast<precision>(last_measurement_);
    return double(duration.count())/ divisor_;
}

double Timer::min() const{
    checkEmptyHistory();
    checkRunning();
    precision min = std::chrono::duration_cast<precision>(min_);
    return double(min.count())/ divisor_;
}

double Timer::mean() const{
    checkEmptyHistory();
    checkRunning();
    const size_t history_size = history_.size();
    double sum = 0.;
    for(size_t i = 0; i < history_size; i++){
        precision current_time = std::chrono::duration_cast<precision>(history_.at(i));
        sum += double(current_time.count());
    }
    const double mean = sum / history_size;
    return mean/ divisor_;
}

} // end namespace pt1