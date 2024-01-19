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
 * integrate() - use function to integrate f(x) in interval (a,b) using simpson integration
 * PRECONDITIONS:   
 * @ f : is a function with operation double operator()(const double)
 *     : can be Lambda function, Function class or Function Pointer
 * @ a : is start of the integration interval (a < b)
 * @ b : is end of the integration interval (b > a)
 * @ N : numbers of bins to split interval into smaller intervals (N > 0)
 * POST: return integration of the function object in intervall (a, b) with N bins
 */
template <typename Function>
double integrate(const Function& f, const double a, const double b, const unsigned int N)
{
     if(N <= 0 && "Checks if N is bigger than zero"){
        throw std::invalid_argument("N == 0! \n");
    }
    const unsigned int steps = 2*N + 1;
    const double dr = (b - a) / (steps - 1);
    double I = f(a);

    for(unsigned int i = 1; i < steps-1; ++i)
        I += 2 * (1.0 + i%2) * f(a + dr * i);

    I += f(b);
    return I * (1./3) * dr;
}


/*
 * integrate2d() - use function to integrate f(x,y) on a square (a,b)x(c,d)
 * using simpson integration and Fubinis theorem
 * PRECONDITIONS:   
 * @ f : is a function with operation double operator()(const double, const double)
 *     : can be Lambda function, Function class or Function Pointer
 * @ a : is start of the integration interval for x axis
 * @ b : is end of the integration interval for x axis
 * @ c : is start of the integration interfal for y axis
 * @ d : is end of teh integration interval for y axis
 * @ N : numbers of bins to split interval into smaller intervals (N > 0)
 * POST: return integration of the function object in intervall (a, b) with N bins
 */
template<typename Function>
double integrate2d(const Function& f, 
                const double a, const double b,
                const double c, const double d, const unsigned int N)
{
    auto F = [&](const double x) -> double{
        return integrate([&](const double y)->double{return f(x, y);}, a, b, N);
    };

    return integrate(F, a, b, N);
}



} // end namespace Simpson

#endif /* SIMPSON_H */