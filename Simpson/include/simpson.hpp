/* ==============================================================
 * Programming Techniques for Scientific Simulations I  
 * Header file defining the simpson library
 * 
 * VERSION 1.00 (C) Copyright Free to use
 * ==============================================================*/

#ifndef SIMPSON_H
#define SIMPSON_H

#include <stdexcept>
#include <functional>
#include <cmath>

// namespace Simpson
namespace Simpson{

/*
 * integrate_sine() - hard-coded integration of sine in interval (a, b) using simpson integration
 * PRECONDITIONS:
 * @ a : start of interval (a < b)
 * @ b : end of interval (b > a)
 * @ N : numbers of bins to split interval into smaller intervals (N > 0)
 * POST: return integration of sine in intervall (a, b) with N bins
 */
double integrate_sine( const double, const double, const unsigned int );

/*
 * integrate() - use function object to integrate f(x) in interval (a,b) using simpson integration
 * PRECONDITIONS:   
 * @ f : is a function object (example Lambda expression) with argument double x and return double f(x)
 * @ a : is start of the integration interval (a < b)
 * @ b : is end of the integration interval (b > a)
 * @ N : numbers of bins to split interval into smaller intervals (N > 0)
 * POST: return integration of the function object in intervall (a, b) with N bins
 */
template <typename Function>
double integrate( const Function&, const double, const double, const unsigned int );

} // end namespace Simpson

#endif /* SIMPSON_H */