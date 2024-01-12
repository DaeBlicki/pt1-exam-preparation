/* ===================================================================
 * Programming Techniques for Scientific Simulations I  
 * package  :   Simpson Library
 * function :   Test throwing invalid_argument exception
 * created  :   12/01/2024
 * author   :   DaeBlicki
 * 
 * updated  :   xx/xx/xx
 * VERSION 1.00 (C) Copyright Free to use
 * ===================================================================*/

#include "../include/simpson.hpp"

void TEST_CHECK_CONDITION()
{
    /* Initialize some interval arguments for integration */
    const double a1 = -2.0; const double a2 = 2.0;
    const double b1 = -3.0; const double b2 = 3.0;

    // check if a > b will throw exception
    try{
        Simpson::check_precondition(a1, b1, 1);
        throw std::logic_error("TEST INVALID ARGUMENT FAILED!: a > b \n");
    }catch(std::invalid_argument& err){}

    // check if a < b will throw exception
    try{
        Simpson::check_precondition(a2, b2, 1);
    }catch(std::invalid_argument& err){
        throw std::logic_error("TEST INVALID ARGUMENT FAILED!: a < b, should not throw exception! \n");
    }

    // check if N == 0 will throw exception
    try{
        Simpson::check_precondition(a2, b2, 0);
    }catch(std::invalid_argument& err){}
}   

int main(){
    TEST_CHECK_CONDITION();
    return 0;
}