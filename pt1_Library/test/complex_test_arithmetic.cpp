/* ===================================================================
 * Programming Techniques for Scientific Simulations I  
 * package  :   pt1_Library
 * function :   test the arithmetic operator of complex
 * created  :   05/01/2024
 * author   :   DaeBlicki
 * 
 * updated  :   xx/xx/xx
 * VERSION 1.00 (C) Copyright Free to use
 * ===================================================================*/

#include "../include/Complex.hpp"
#include <iostream>

void TEST_COMPLEX_ARITHMETIC()
{
    const double x = 3.0;
    const double y = 4.0;
    pt1::Complex a(x, y);
    pt1::Complex b(x, y);
    pt1::Complex c;
    pt1::Complex d;

    /* testing simple arithmetic */
    c = a + b;
    if(c.getReal() != 2*x || c.getImaginary() != 2*y){
        throw std::logic_error("TEST COMPLEX ARITHMETIC FAILED! operator+ \n");
    }
    c = a - b;
    if(c.getReal() != 0.0 || c.getImaginary() != 0.0){
        throw std::logic_error("TEST COMPLEX ARITHMETIC FAILED! operator+ \n");
    }
    try{
        d = a/c;
        throw std::logic_error("TEST COMPLEX ARITHMETIC FAILED! divied by zero! \n");
    } catch(std::runtime_error& err){}
    c = a/b;
    if(c.getReal() != 1.0 || c.getImaginary() != 0.0){
        throw std::logic_error("TEST COMPLEX ARITHMETIC FAILED! operator/ \n");
    }
    d = a*c;
    if(d.getReal() != x || d.getImaginary() != y){
        throw std::logic_error("TEST COMPLEX ARITHMETIC FAILED! operator* \n");
    }
    /* testing commutativity of addition and multiplication */
    a = pt1::Complex(x, y);
    b = pt1::Complex(y, x);
    c = a+b;
    d = b+a;
    if(c != d){
        throw std::logic_error("TEST COMPLEX ARITHMETIC FAILED! commutativity addition! \n");
    }
    c = a-b;
    d = b-a;
    if(c == d){
        throw std::logic_error("TEST COMPLEX ARITHMETIC FAILED! commutativity substraction! \n");
    }
    c = a*b;
    d = b*a;
     if(c != d){
        throw std::logic_error("TEST COMPLEX ARITHMETIC FAILED! commutativity multiplication! \n");
    }
    c = a/b;
    d = b/a;
    if(c == d){
        throw std::logic_error("TEST COMPLEX ARITHMETIC FAILED! commutativity division! \n");
    }

}

int main()
{
    TEST_COMPLEX_ARITHMETIC();
    return 0;
}