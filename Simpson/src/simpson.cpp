/* ===================================================================
 * Programming Techniques for Scientific Simulations I  
 * package  :   Simpson Library
 * function :   integration of functions using the simpson integration
 * created  :   12/01/2024
 * author   :   DaeBlicki
 * 
 * updated  :   xx/xx/xx
 * VERSION 1.00 (C) Copyright Free to use
 * ===================================================================*/

#include "../include/simpson.hpp"

// namespace Simpson
namespace Simpson{

/*
 * integrate_sine() - hard-coded integration of sine in interval (a, b) using simpson integration
 * PRECONDITIONS: N > 0
 * POST: return integration of sine in intervall (a, b) with N bins
 */
double integrate_sine(const double a, const double b, const unsigned int N)
{
    if(N <= 0 && "Checks if N is bigger than zero"){
        throw std::invalid_argument("N == 0! \n");
    }
    const double dx = (b-a)/N;
    const double pre = dx/6;
    double sum = 0.0;
    for(unsigned int i = 0; i < N-1; i++){
        double pre_sum = 0.0;
        const double x_i = dx*i + a;
        pre_sum += std::sin(x_i);
        pre_sum += 4*std::sin(0.5*(2*x_i + dx));
        pre_sum += std::sin(x_i + dx);
        pre_sum *= pre;
        sum += pre_sum;
    }
    return sum;
}

} // end namespace Simpson