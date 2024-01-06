/* ===================================================================
 * Programming Techniques for Scientific Simulations I  
 * package  :   pt1_Library
 * function :   test the logical operator of complex
 * created  :   05/01/2024
 * author   :   DaeBlicki
 * 
 * updated  :   xx/xx/xx
 * VERSION 1.00 (C) Copyright Free to use
 * ===================================================================*/

#include "../include/Complex.hpp"

void TEST_COMPLEX_LOGICAL()
{
    const double x = 3.0;
    const double y = 4.0;

    pt1::Complex a(x, x);
    pt1::Complex b(y, x);
    pt1::Complex c(x, y);
    pt1::Complex d(x, y);
    if(a == b || a == c || b == c || !(c == d)){
        throw std::logic_error("TEST COMPLEX LOGICAL FAILED! operator== \n");
    }
    if(c != d || !(a != b) || !(a != c) || !(b != c)){
        throw std::logic_error("TEST COMPLEX LOGICAL FAILED! operator!= \n");
    }
}

int main()
{
    TEST_COMPLEX_LOGICAL();
    return 0;
}