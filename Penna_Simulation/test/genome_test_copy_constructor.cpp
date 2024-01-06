/* ===================================================================
 * Programming Techniques for Scientific Simulations I  
 * package  :   penna
 * function :   test if copied genome is identical
 * created  :   05/01/2024
 * author   :   DaeBlicki
 * 
 * updated  :   xx/xx/xx
 * VERSION 1.00 (C) Copyright Free to use
 * ===================================================================*/

#include "../include/Penna/genome.hpp"
#include <stdexcept>

void TEST_GENOME_COPY_CONSTRUCTOR()
{
    Penna::Genome parent_genome = Penna::Genome();
    Penna::Genome child_genome = Penna::Genome(parent_genome);
    size_t maximal_age = parent_genome.getSize();
    for(size_t age = 0; age < maximal_age; age++){
        if(child_genome.countBad(age) != parent_genome.countBad(age)){
            throw std::logic_error("TEST FAILED: GENOME COPY CONSTRUCTOR! \n");
        }
    }
}

int main(){
    TEST_GENOME_COPY_CONSTRUCTOR();
    return 0;
}
