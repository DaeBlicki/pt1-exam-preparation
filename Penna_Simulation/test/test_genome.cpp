/* ===================================================================
 * Programming Techniques for Scientific Simulations I  
 * package  :   penna
 * function :   Tests for genome class
 * created  :   05/01/2024
 * author   :   DaeBlicki
 * 
 * updated  :   12/01/24
 * message  :   doctest.h overhaul
 * VERSION 1.00 (C) Copyright Free to use
 * ===================================================================*/

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "../include/Penna/genome.hpp"
#include "../include/pt1/Random.hpp"

/* ===================================================================
 * TESTS FOR GENOME CONSTRUCTORS
 * ===================================================================*/
TEST_SUITE("Genome Constructors"){
    // GENOME DEFAULT CONSTRUCTOR
    TEST_CASE("Genome Default Constructor"){
        pt1::Random_Number_Generator::seed(42);
        Penna::Genome test_genome = Penna::Genome();
        Penna::Genome random_genome = Penna::Genome();
        size_t maximal_age = test_genome.getSize();
        // check if the genome has only good genes (chances are too small)
        CHECK(test_genome.countBad(maximal_age - 1) != 0);
        CHECK(test_genome.countBad(maximal_age - 1) != random_genome.countBad(maximal_age - 1));
    }
    // GENOME COPY CONSTRUCTOR
    TEST_CASE("Genome Copy Constructor"){
        pt1::Random_Number_Generator::seed(42);
        Penna::Genome parent_genome = Penna::Genome();
        Penna::Genome child_genome = Penna::Genome(parent_genome);
        size_t maximal_age = parent_genome.getSize();
        bool identical = true;
        for(size_t age = 0; age < maximal_age; age++){
            if(child_genome.countBad(age) != parent_genome.countBad(age)){
                identical = false;
            }
        }
        CHECK(identical);
    }
}