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
 * check_precondition() - check precondition and throws run_time_exception in bad cases
 * PRECONDITION:
 * @ a : start of interval (a <= b)
 * @ b : end of interval (b >= a)
 * @ N : numbers of bins to split interval into smaller intervals (N > 0)
 * POST: do nothing if preconditions are good
 */
void check_precondition(const double a, const double b, const unsigned int N)
{
    if(a > b && "Checks if a is bigger than b"){
        throw std::invalid_argument("a > b! \n");
    }
    if(N <= 0 && "Checks if N is bigger than zero"){
        throw std::invalid_argument("N == 0! \n");
    }
}

/*
 * integrate_sine() - hard-coded integration of sine in interval (a, b) using simpson integration
 * PRECONDITIONS:
 * @ a : start of interval (a <= b)
 * @ b : end of interval (b >= a)
 * @ N : numbers of bins to split interval into smaller intervals (N > 0)
 * POST: return integration of sine in intervall (a, b) with N bins
 */
double integrate_sine(const double a, const double b, const unsigned int N)
{
    Simpson::check_precondition(a, b, N);
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


/*
 * integrate() - use function pointer to integrate f(x) in interval (a, b) using simpson integration
 * PRECONDITIONS:   
 * @ f : is a pointer to a function with argument double x and return double f(x)
 * @ a : is start of the integration interval (a <= b)
 * @ b : is end of the integration interval (b >= a)
 * @ N : numbers of bins to split interval into smaller intervals (N > 0)
 * POST: return integration of function pointer in intervall (a, b) with N bins
 */
double integrate( double (*f)(const double), const double a, const double b, const unsigned int N)
{
    Simpson::check_precondition(a, b, N);
    const unsigned int steps = 2*N + 1;
    const double dr = (b - a) / (steps - 1);
    double I = f(a);

    for(unsigned int i = 1; i < steps-1; ++i)
        I += 2 * (1.0 + i%2) * f(a + dr * i);

    I += f(b);
    return I * (1./3) * dr;
}

/*
 * integrate() - use function object to integrate f(x) in interval (a,b) using simpson integration
 * PRECONDITIONS:   
 * @ f : is a function object (example Lambda expression) with argument double x and return double f(x)
 * @ a : is start of the integration interval (a <= b)
 * @ b : is end of the integration interval (b >= a)
 * @ N : numbers of bins to split interval into smaller intervals (N > 0)
 * POST: return integration of the function object in intervall (a, b) with N bins
 */
template <typename Func>
double integrate(const Func& f, const double a, const double b, const unsigned int N)
{
    Simpson::check_precondition(a, b, N);
    const unsigned int steps = 2*N + 1;
    const double dr = (b - a) / (steps - 1);
    double I = f(a);

    for(unsigned int i = 1; i < steps-1; ++i)
        I += 2 * (1.0 + i%2) * f(a + dr * i);

    I += f(b);
    return I * (1./3) * dr;
}

/*
 * integrate() - use function class to integrate f(x) in interval (a,b) using simpson integration
 * PRECONDITIONS:   
 * @ f : is a simpson function class with defined operator()
 * @ a : is start of the integration interval (a <= b)
 * @ b : is end of the integration interval (b >= a)
 * @ N : numbers of bins to split interval into smaller intervals (N > 0)
 * POST: return integration of the function object in intervall (a, b) with N bins
 */
double integrate(const Simpson::Function& f, const double a, const double b, const unsigned int N)
{
    Simpson::check_precondition(a, b, N);
    return 0.0;
}

} // end namespace Simpson