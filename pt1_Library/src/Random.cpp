/* ===================================================================
 * Programming Techniques for Scientific Simulations I  
 * package  :   pt1_Library
 * function :   generate random number
 * created  :   18/12/2023
 * author   :   DaeBlicki
 * 
 * updated  :   xx/xx/xx
 * VERSION 1.00 (C) Copyright Free to use
 * ===================================================================*/

#include "../include/Random.hpp"

namespace pt1{

/* Definition of the static members */
parameter_t Random_Number_Generator::X_ = 42;

Random_Number_Generator::Random_Number_Generator(){
    Random_Number_Generator::seed(42);
}

result_t Random_Number_Generator::generate(){
    X_ = (a_ * X_ + c_) % m_;
    return X_;
}

/*
    * max() - return the maximal possible number
    * PRE: -
    * POST: return max number of RNG
    */
result_t Random_Number_Generator::max(){
    return UINT32_C(m_ - 1);
}

/*
    * seed() - change the initial seed to predict the outcome
    * PRE: parameter must be an uint64_t
    * POST: RNG is seeded and gerenate same output sequence
    */
void Random_Number_Generator::seed( parameter_t X){
    X_ = X;
}

} // end namespace pt1