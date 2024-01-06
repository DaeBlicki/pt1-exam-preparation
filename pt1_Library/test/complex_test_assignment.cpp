/* ===================================================================
 * Programming Techniques for Scientific Simulations I  
 * package  :   pt1_Library
 * function :   test the assignment operator of complex
 * created  :   05/01/2024
 * author   :   DaeBlicki
 * 
 * updated  :   xx/xx/xx
 * VERSION 1.00 (C) Copyright Free to use
 * ===================================================================*/

#include "../include/Complex.hpp"

void TEST_COMPLEX_ASSIGNMENT()
{
    const double x = 4.0;
    const double y = 3.0;
    pt1::Complex a(x, y);
    pt1::Complex b = a;
    if(b.getImaginary() != a.getImaginary() || b.getReal() != a.getReal()){
        throw std::logic_error("TEST COMPLEX ASSIGNMENT FAILED! : operator= \n");
    }
    a += b;
    if(a.getReal() != 2*b.getReal() || a.getImaginary() != 2*b.getImaginary()){
        throw std::logic_error("TEST COMPLEX ASSIGNMENT FAILED! : operator+= \n");
    }
    a -= b;
    if(b.getImaginary() != a.getImaginary() || b.getReal() != a.getReal()){
        throw std::logic_error("TEST COMPLEX ASSIGNMENT FAILED! : operator-= \n");
    }
    a /= b;
    if(a.getReal() != 1.0 || a.getImaginary() != 0.0){
        throw std::logic_error("TEST COMPLEX ASSIGNMENT FAILED! : operator/= \n");
    }
    a *= b;
     if(b.getImaginary() != a.getImaginary() || b.getReal() != a.getReal()){
        throw std::logic_error("TEST COMPLEX ASSIGNMENT FAILED! : operator*= \n");
    }
    try{
        a /= pt1::Complex(0, 0);
        throw std::logic_error("TEST COMPLEX ASSIGNMENT FAILED! : divide zero! \n");
    } catch(std::runtime_error& err){}
}

int main(){
    TEST_COMPLEX_ASSIGNMENT();
    return 0;
}