/* ===================================================================
 * Programming Techniques for Scientific Simulations I  
 * package  :   penna
 * function :   Tests for population class
 * created  :   05/01/2024
 * author   :   DaeBlicki
 * 
 * updated  :   12/01/24
 * message  :   doctest.h overhaul
 * VERSION 1.00 (C) Copyright Free to use
 * ===================================================================*/

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "../include/Penna/population.hpp"
#include "../include/pt1/Random.hpp"

TEST_SUITE("Population class"){
    TEST_CASE("Default Constructor"){
        pt1::Random_Number_Generator::seed(42);
        Penna::Population test_population = Penna::Population();
        CHECK(test_population.size() == 0);
        CHECK(test_population.maxSize() == 0);
        CHECK(test_population.population().empty());
    }
    TEST_CASE("Initialization function"){
        pt1::Random_Number_Generator::seed(42);
        Penna::Population test_population = Penna::Population();
        CHECK_THROWS(test_population.start(0, 100));    //< start with zero
        CHECK_THROWS(test_population.start(100, 100));  //< start with max
        CHECK_THROWS(test_population.start(0, 100));    //< start with over max
        CHECK_THROWS(test_population.start(0, 100));    //< start with max == 0
    }
    TEST_CASE("Member functions before initialization"){
         pt1::Random_Number_Generator::seed(42);
        Penna::Population test_population = Penna::Population();
        CHECK_THROWS(test_population.survived());
        CHECK_THROWS(test_population.timeStep());
        CHECK_THROWS(test_population.getVelhustFactor());
    }
    TEST_CASE("Member functions after initialization"){
        pt1::Random_Number_Generator::seed(42);
        Penna::Population test_population = Penna::Population();
        const unsigned int size = 5;
        const unsigned int maxSize = 50000;
        const double velhust = 1.0 - (size/ maxSize);   //< should be 0.9999
        const age_t maximalAge = Penna::Animal::maximalAge();
        test_population.start(size, maxSize);
        CHECK(test_population.getVelhustFactor() == velhust);
        CHECK(test_population.size() == size);
        CHECK(test_population.maxSize() == maxSize);
        /* ====================================================
         * CHECK POPULATION::TIMESTEP() METHOD
         * ====================================================*/
        Penna::Animal::init(maximalAge-1, 0, 1.0);  //< always get pregnant and high mutation tolerance!
        test_population.timeStep();                 //< make everyone pregnant!
        CHECK(test_population.size() == size);      //< check unlucky random number generator!
        // check if everyone is pregnant
        bool pregnancy = true;
        for(Penna::Animal& current: test_population.population()){
            if(current.isPregnant() == false){
                pregnancy = false;
            }
        }
        CHECK(pregnancy);
        Penna::Animal::init(maximalAge-1, maximalAge-1, 0.0);   //< make impossible to get pregnant
        test_population.timeStep();                             //< every pregnant Animal will giving birth
        const unsigned int current_size = test_population.size();
        const unsigned int calculated_size = 2*size;
        const unsigned int epsilon = 2; //< In case of Bad RNG, one Animal can die before birth
        CHECK(current_size >= calculated_size - epsilon);   // lower bound with bad rng calculation
        CHECK(current_size <= calculated_size);             // sharp upper bound when nobody dies
        Penna::Animal::init(0, maximalAge- 1, 0);  //< impossible to get pregnant, vulnerable to mutations!
        for(age_t i = 0; i < maximalAge; i++){
            test_population.timeStep();
        }
        // impossible to survive!
        CHECK_FALSE(test_population.survived());
    }

}
