/* ===================================================================
 * Programming Techniques for Scientific Simulations I  
 * package  :   Simpson Library
 * function :   Benchmark various approach to integrate
 * created  :   14/01/2024
 * author   :   DaeBlicki
 * 
 * updated  :   xx/xx/xx
 * VERSION 1.00 (C) Copyright Free to use
 * ===================================================================*/

#include "../include/Simpson/simpson.hpp"
#include "../include/Simpson/polynomial.hpp"
#include "../include/pt1/Timer.hpp"
#include <iostream>
#include <iomanip>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

void benchmark_polynomial();
void benchmark_exponential();
void benchmark_cosine();
void benchmark_log();

TEST_SUITE("Benchmark various approach"){
    TEST_CASE("Cubic Polynomial"){
        benchmark_polynomial();
    }
    TEST_CASE("Exponential Function"){
        benchmark_exponential();
    }
    TEST_CASE("Cosine Function"){
        benchmark_cosine();
    }
    TEST_CASE("Logarithmic Function"){
        benchmark_log();
    }
}

// printHeader() - print out of the Benchmark
void printHeader()
{
    std::cout   << std::setw(5) << "n|" 
                << std::setw(15) << "error"
                << std::setw(15) << "t (class)"
                << std::setw(15) << "t (object)"
                << std::setw(15) << "t (pointer)"
                << std::setw(15) << "t (lambda)" 
                << std::endl
    << "----------------------------------------"
    << "---------------------------------------- \n";
}

//  printLine() - print out the line of the table
void printLine(const unsigned int n, 
                double e1,
                const double t1, const double t2,
                const double t3, const double t4)
{
    if(e1 < 1e-12){
        e1 = 0.;
    }
    std::cout   << std::setw(5) << n 
                << std::setw(15) << e1
                << std::setw(15) << t1
                << std::setw(15) << t2
                << std::setw(15) << t3
                << std::setw(15) << t4
                << std::endl;
}

/* =======================
 * FUNCTION FOR TESTING
 * =======================*/
double poly(const double x){
    return cubic(x, 1., 2., 3., 4.);
}

double myExponential(const double x){
    return std::exp(x);
}

double myCosine(const double x){
    return std::cos(x);
}

double myLogarithm(const double x){
    return std::log(x);
}

/* ============================
 * FUNCTION CLASS FOR TESTING
 * ============================*/

struct myExp{
    ~myExp() = default;
    inline double operator()(const double x) const{
        return std::exp(x);
    }
};

struct myCos{
    ~myCos() = default;
    inline double operator()(const double x) const{
        return std::cos(x);
    }
};

struct myLog{
    ~myLog() = default;
    inline double operator()(const double x) const{
        return std::log(x);
    }
};


/* =======================
 * BENCHMARK POLYNOMIAL
 * =======================*/
void benchmark_polynomial()
{
    const double a = 1.;    const double b = 2.;
    const double c = 3.;    const double d = 4.;
    const double x1 = -1.;  const double x2 = 3.;
    double err1, err2, err3, err4, t1, t2, t3, t4;

    auto func_ptr = &poly;
    auto lambda = [&](double x){
        return a*x*x*x + b*x*x + c*x + d;
    };
    
    pt1::Timer clock1 = pt1::Timer(); pt1::Timer clock2 = pt1::Timer(); 
    pt1::Timer clock3 = pt1::Timer(); pt1::Timer clock4 = pt1::Timer();
    
    std::cout << "f(x) = x^3 + 2x^2 + 3x + 4 in Integral [-1., 3.] \n";
    const double exact = integrateCubic(a, b, c, d, x1, x2);
    printHeader();
    for(unsigned int n = 10; n <= 100; n += 10){
        // reset the timer
        clock1.reset(); clock2.reset();
        clock3.reset(); clock4.reset();
        for(unsigned int it = 0; it < 10; it++){
            clock1.start();
            err1 = std::abs(Simpson::integrate(Cubic(a, b, c, d), x1, x2, n) - exact);
            clock1.stop();
            clock2.start();
            err2 = std::abs(Simpson::integrate(poly, x1, x2, n) - exact);
            clock2.stop();
            clock3.start();
            err3 = std::abs(Simpson::integrate(func_ptr, x1, x2, n) - exact);
            clock3.stop();
            clock4.start();
            err4 = std::abs(Simpson::integrate(lambda, x1, x2, n) - exact);
            clock4.stop();
        }
        // store the time and print out
        t1 = clock1.mean(); t2 = clock2.mean();
        t3 = clock3.mean(); t4 = clock4.mean();
        printLine(n, err1, t1, t2, t3, t4);
    }
    std::cout << "\n";
}



/* =======================
 * BENCHMARK EXPONENTIALS
 * =======================*/
void benchmark_exponential()
{
    const double x1 = -1.;  const double x2 = 3.;
    double err1, err2, err3, err4, t1, t2, t3, t4;

    auto func_ptr = &myExponential;
    auto lambda = [&](double x){
        return std::exp(x);
    };
    
    pt1::Timer clock1 = pt1::Timer(); pt1::Timer clock2 = pt1::Timer(); 
    pt1::Timer clock3 = pt1::Timer(); pt1::Timer clock4 = pt1::Timer();
    
    std::cout << "f(x) = exp(x) in Integral [-1., 3.] \n";
    const double exact = std::exp(x2) - std::exp(x1);
    printHeader();
    for(unsigned int n = 10; n <= 100; n += 10){
        // reset the timer
        clock1.reset(); clock2.reset();
        clock3.reset(); clock4.reset();
        for(unsigned int it = 0; it < 10; it++){
            clock1.start();
            err1 = std::abs(Simpson::integrate(myExp(), x1, x2, n) - exact);
            clock1.stop();
            clock2.start();
            err2 = std::abs(Simpson::integrate(myExponential, x1, x2, n) - exact);
            clock2.stop();
            clock3.start();
            err3 = std::abs(Simpson::integrate(func_ptr, x1, x2, n) - exact);
            clock3.stop();
            clock4.start();
            err4 = std::abs(Simpson::integrate(lambda, x1, x2, n) - exact);
            clock4.stop();
        }
        // store the time and print out
        t1 = clock1.mean(); t2 = clock2.mean();
        t3 = clock3.mean(); t4 = clock4.mean();
        printLine(n, err1, t1, t2, t3, t4);
    }
    std::cout << "\n";
}

/* =======================
 * BENCHMARK COSINE
 * =======================*/
void benchmark_cosine()
{
    const double x1 = -1.;  const double x2 = 3.;
    double err1, err2, err3, err4, t1, t2, t3, t4;

    auto func_ptr = &myCosine;
    auto lambda = [&](double x){
        return std::cos(x);
    };
    
    pt1::Timer clock1 = pt1::Timer(); pt1::Timer clock2 = pt1::Timer(); 
    pt1::Timer clock3 = pt1::Timer(); pt1::Timer clock4 = pt1::Timer();
    
    std::cout << "f(x) = cos(x) in Integral [-1., 3.] \n";
    const double exact = std::sin(x2) - std::sin(x1);
    printHeader();
    for(unsigned int n = 10; n <= 100; n += 10){
        // reset the timer
        clock1.reset(); clock2.reset();
        clock3.reset(); clock4.reset();
        for(unsigned int it = 0; it < 10; it++){
            clock1.start();
            err1 = std::abs(Simpson::integrate(myCos(), x1, x2, n) - exact);
            clock1.stop();
            clock2.start();
            err2 = std::abs(Simpson::integrate(myCosine, x1, x2, n) - exact);
            clock2.stop();
            clock3.start();
            err3 = std::abs(Simpson::integrate(func_ptr, x1, x2, n) - exact);
            clock3.stop();
            clock4.start();
            err4 = std::abs(Simpson::integrate(lambda, x1, x2, n) - exact);
            clock4.stop();
        }
        // store the time and print out
        t1 = clock1.mean(); t2 = clock2.mean();
        t3 = clock3.mean(); t4 = clock4.mean();
        printLine(n, err1, t1, t2, t3, t4);
    }
    std::cout << "\n";
}

/* =======================
 * BENCHMARK LOGARITHMIC
 * =======================*/
void benchmark_log()
{
    const double x1 = 1.;  const double x2 = 5.;
    double err1, err2, err3, err4, t1, t2, t3, t4;

    auto func_ptr = &myLogarithm;
    auto lambda = [&](double x){
        return std::log(x);
    };
    
    pt1::Timer clock1 = pt1::Timer(); pt1::Timer clock2 = pt1::Timer(); 
    pt1::Timer clock3 = pt1::Timer(); pt1::Timer clock4 = pt1::Timer();
    
    std::cout << "f(x) = log(x) in Integral [1., 5.] \n";
    const double exact = 5*std::log(5) - 4.;
    printHeader();
    for(unsigned int n = 10; n <= 100; n += 10){
        // reset the timer
        clock1.reset(); clock2.reset();
        clock3.reset(); clock4.reset();
        for(unsigned int it = 0; it < 10; it++){
            clock1.start();
            err1 = std::abs(Simpson::integrate(myLog(), x1, x2, n) - exact);
            clock1.stop();
            clock2.start();
            err2 = std::abs(Simpson::integrate(myLogarithm, x1, x2, n) - exact);
            clock2.stop();
            clock3.start();
            err3 = std::abs(Simpson::integrate(func_ptr, x1, x2, n) - exact);
            clock3.stop();
            clock4.start();
            err4 = std::abs(Simpson::integrate(lambda, x1, x2, n) - exact);
            clock4.stop();
        }
        // store the time and print out
        t1 = clock1.mean(); t2 = clock2.mean();
        t3 = clock3.mean(); t4 = clock4.mean();
        printLine(n, err1, t1, t2, t3, t4);
    }
    std::cout << "\n";
}