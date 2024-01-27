/* ==============================================================
 * Programming Techniques for Scientific Simulations I  
 * Header file defining random number generator
 * 
 * VERSION 1.00 (C) Copyright Free to use
 * ==============================================================*/

#ifndef RANDOM_H
#define RANDOM_H

#include <random>
#include <cstdint>

// namespace pt1
namespace pt1{

using parameter_t = std::uint64_t;
using result_t = std::uint32_t;

class Random_Number_Generator
{

private:
    static const parameter_t m_ = (UINT64_C(1)<<31);    /* modulo parameter */
    static const parameter_t a_ = 1664525;      /* multiplicator parameter */
    static const parameter_t c_ = 1013904223;   /* addition parameter */

    static parameter_t X_;     /* Initial number seed */

public:
    Random_Number_Generator();              /* Default Constructor */
    
    /*
     * generate() - return a random number dependant on the X
     * PRE: -
     * POST: return random number by algorithm
     */
    static result_t generate();

    /*
     * max() - return the maximal possible number
     * PRE: -
     * POST: return max number of RNG
     */
    static result_t max();

    /*
     * seed() - change the initial seed to predict the outcome
     * PRE: parameter must be an uint64_t
     * POST: RNG is seeded and gerenate same output sequence
     */
    static void seed( parameter_t );

    /*
     * coin() - return 0 or 1
     * PRE: -
     * POST: return 0 or 1 with 50% chance
     */
    static bool coin();

};

} // end namespace pt1

#endif /* RANDOM_H  */