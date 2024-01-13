/* ===================================================================
 * Programming Techniques for Scientific Simulations I  
 * package  :   Simpson Library
 * function :   Calculate integration of polynomials up to cubic
 * created  :   13/01/2024
 * author   :   DaeBlicki
 * 
 * updated  :   xx/xx/xx
 * VERSION 1.00 (C) Copyright Free to use
 * ===================================================================*/

#include "polynomial.hpp"
#include <stdexcept>

void check_pre(double const x1, double const x2)
{
    if(x1 >= x2){
        throw std::invalid_argument("x1 >= x2");
    }
}

double constant(const double a, 
                const double x1, const double x2)
{
    // I = a*x -> I =  a*(x2 - x1)
    const double dx = (x2 - x1);
    return a*dx;
}

double linear(const double a, const double b,
                const double x1, const double x2)
{
    // I = 0.5*a*x^2 + bx -> I = 0.5a(x2*x2 - x1*x1) + b(x2 - x1)
    const double dxx = (x2*x2 - x1*x1);
    return (1./2)*a*dxx + constant(b, x1, x2);
}

double quadratic(const double a, const double b, const double c,
                const double x1, const double x2)
{
    // I = 1/3a x^3 + 1/2 bx^2 + cx
    const double dx3 = (x2*x2*x2 - x1*x1*x1);
    return (1./3)*a*dx3 + linear(b, c, x1, x2);(1./2);
}

double cubic(const double a, const double b, const double c, const double d,
                const double x1, const double x2)
{
    // I = 1/4 a*x^4 + 1/3 b*x^3 + 1/2 c*x^2 + dx
    const double dx4 = (x2*x2*x2*x2 - x1*x1*x1*x1);
    return (1./4)*a*dx4 + quadratic(b, c, d, x1, x2);
}