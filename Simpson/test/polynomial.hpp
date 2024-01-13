/* ==============================================================
 * Programming Techniques for Scientific Simulations I  
 * Header file defining the polynomials integrations
 * 
 * VERSION 1.00 (C) Copyright Free to use
 * ==============================================================*/

#include <stdexcept>

/*
 * constant() - calculate the integral of constant function from (x1, x2)
 * PRE: x1 <= x2: f(x) = a
 * POST: return integral of f(x) = a from (x1, x2)
 */
double constant(const double a, 
                const double x1, const double x2);

/*
 * linear() - calculate the integral of linear function from (x1, x2)
 * PRE: x1 <= x2: f(x) = ax + b
 * POST: return integral of f(x) = ax + b from (x1, x2)
 */
double linear(const double a, const double b,
                const double x1, const double x2);

/*
 * quadratic() - calculate the integral of quadratic function from (x1, x2)
 * PRE: x1 <= x2 : f(x) = ax^2 + bx + c
 * POST: return integral of f(x) = ax^2 + bx + c from (x1, x2)
 */
double quadratic(const double a, const double b, const double c,
                const double x1, const double x2);

/*
 * quadratic() - calculate the integral of cubic function from (x1, x2)
 * PRE: x1 <= x2 : f(x) = ax^3 + bx^2 + cx + d
 * POST: return integral of f(x) = ax^2 + bx + c from (x1, x2)
 */
double cubic(const double a, const double b, const double c, const double d,
                const double x1, const double x2);

// check_pre() - check precondition and throws invalid_argument
void check_pre(double const x1, double const x2);
