/* ==============================================================
 * Programming Techniques for Scientific Simulations I  
 * Header file defining timer class
 * 
 * VERSION 1.00 (C) Copyright Free to use
 * ==============================================================*/

#ifndef TIMER_H   
#define TIMER_H

#include <chrono>
#include <vector>
#include <stdexcept>

// namespace pt1 library
namespace pt1
{
   
typedef std::chrono::high_resolution_clock clock;
typedef std::chrono::duration<double> duration_t;
typedef std::chrono::nanoseconds precision;

class Timer
{
private:
    static const unsigned int divisor_ = 1e9;       /* nano second presision*/

    clock::time_point starting_time_;   /* the time the timer start to measurement */
    clock::time_point ending_time_;     /* the time the timer end the LAST measurement */
    bool measuring_;                    /* true if the timer is measuring */
    std::vector<double> history_;       /* history of all measured time */
    double last_measurement_;       /* store the last measured time */
    double min_;                    /* store the minimal measured time */

    void checkEmptyHistory() const;           /* throw Exception when access min() or mean() without any measurements*/
    void checkRunning() const;                /* throw Exception when timer is measuring */

public:
    Timer();    /* default ctor */
    ~Timer() = default;

    /*
     * isMeasuring() - return the measurement status
     * PRE: -
     * POST: return true if Timer is measuring
     */
    bool isMeasuring();

    /*
     * start() - Timer starts to measuring the time
     * PRE: Timer is not measuring
     * POST: Timer is measuring and remember the starting time
     */
    void start();

    /*
     * stop() - The Timer stops the measurement
     * PRE: Timer is measuring
     * POST: Timer stop the measurement and remember the ending time
     */
    void stop();

    /*
     * reset() - Timer get resetted and delete history
     * PRE: Timer is not measuring
     * POST: Timer has no history anymore
     */
    void reset();

    /* 
     * duration() - Timer return the last measured time
     * PRE: Timer has already measured atleast one measurement
     * POST: return the last measured time
     */
    double duration() const;

    /*
     * min() - Timer return the shortest measured time
     * PRE: Timer has already measured atleast one measurement
     * POST: return the shortest measured time
     */
    double min() const;
    
    /*
     * mean() - Timer return the average measured time
     * PRE: Timer has already measured atleast one measurement
     * POST: return the average of all measurement in the history
    */
    double mean() const;
};

} // end namespace pt1


#endif /* TIMER_H */