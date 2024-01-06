/* ===================================================================
 * Programming Techniques for Scientific Simulations I  
 * package  :   pt1_Library
 * function :   test the complex constructor, getter and setter
 * created  :   05/01/2024
 * author   :   DaeBlicki
 * 
 * updated  :   xx/xx/xx
 * VERSION 1.00 (C) Copyright Free to use
 * ===================================================================*/

#include "../include/Complex.hpp"
#include <stdexcept>

void TEST_COMPLEX_CONSTRUCTOR()
{
    pt1::Complex a;
    if(a.getImaginary() != 0.0 || a.getReal() != 0.0){
        throw std::logic_error("COMPLEX CONSTRUCTOR TEST FAILED! Default! \n");
    }
    const double x = 4.0;
    const double y = 3.0;
    const double norm = 5.0;
    pt1::Complex b(x, y);
    if(b.getReal() != x || b.getImaginary() != y){
        throw std::logic_error("COMPLEX CONSTRUCTOR TEST FAILED! Initialization! \n");
    }
    pt1::Complex c = pt1::Complex(b);
    if(c.getReal() != x || c.getImaginary() != y){
        throw std::logic_error("COMPLEX CONSTRUCTOR TEST FAILED! Copy constructor! \n");
    }
    a.setReal(x);
    a.setImaginary(y);
    if(a.getReal() != x || a.getImaginary() != y){
        throw std::logic_error("COMPLEX CONSTRUCTOR TEST FAILED! Setter! \n");
    }
    if(a.norm() != norm || b.norm() != norm || c.norm() != norm){
        throw std::logic_error("COMPLEX CONSTRUCTOR TEST FAILED! norm()! \n");
    }
}

int main(){
    TEST_COMPLEX_CONSTRUCTOR();
    return 0;
}