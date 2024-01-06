/* ===================================================================
 * Programming Techniques for Scientific Simulations I  
 * package  :   penna
 * function :   test if initialized genome is only good
 * created  :   05/01/2024
 * author   :   DaeBlicki
 * 
 * updated  :   xx/xx/xx
 * VERSION 1.00 (C) Copyright Free to use
 * ===================================================================*/

#include "../include/Penna/genome.hpp"
#include <stdexcept>


/*
 * TEST_GENOME_DEFAULT_CONSTRUCTOR() - Test the default constructor of genome
 * Genome should not be initialized with only good genes
 */

void TEST_GENOME_DEFAULT_CONSTRUCTOR()
{
    pt1::Random_Number_Generator::seed(42);
    Penna::Genome test_genome = Penna::Genome();
    size_t maximal_age = test_genome.getSize();
    if(test_genome.countBad(maximal_age - 1) == 0){
        throw std::logic_error("TEST FAILED: GENOME DEFAULT CONSTRUCTOR");  
    }
    Penna::Genome random_genome = Penna::Genome();
    if(test_genome.countBad(maximal_age - 1) == random_genome.countBad(maximal_age - 1)){
        throw std::logic_error("TEST FAILED: GENOME IS NOT RANDOMIZED INITIALIZED!");
    }
}

int main(){
    TEST_GENOME_DEFAULT_CONSTRUCTOR();
    return 0;
}