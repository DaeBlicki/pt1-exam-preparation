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

#include "../include/polynomial.hpp"

/* ======================================================
 * IMPLEMENTATION OF INTEGRATION FUNCTION FOR POLYNOMIALS  
 * ======================================================*/

double integrateConstant(const double a, 
                const double x1, const double x2)
{
    const double dx = (x2 - x1);
    return a*dx;
}

double integrateLinear(const double a, const double b,
                const double x1, const double x2)
{
    const double dxx = (x2*x2 - x1*x1);
    return (1./2)*a*dxx + integrateConstant(b, x1, x2);
}

double integrateQuadratic(const double a, const double b, const double c,
                const double x1, const double x2)
{
    const double dx3 = (x2*x2*x2 - x1*x1*x1);
    return (1./3)*a*dx3 + integrateLinear(b, c, x1, x2);(1./2);
}

double integrateCubic(const double a, const double b, const double c, const double d,
                const double x1, const double x2)
{
    const double dx4 = (x2*x2*x2*x2 - x1*x1*x1*x1);
    return (1./4)*a*dx4 + integrateQuadratic(b, c, d, x1, x2);
}


/* ===================================================
 * DEFINITIONS OF FUNCTION TO CALCULATE POLYNOMIALS 
 * ===================================================*/

double constant(const double x, const double a){
    return a;
}

double linear(const double x, const double a, const double b){
    return a*x + b;
}

double quadratic(const double x, const double a, const double b, const double c){
    return a*x*x + b*x + c;
}

double cubic(const double x, const double a, const double b, const double c, const double d){
    return a*x*x*x + b*x*x + c*x + d;
}