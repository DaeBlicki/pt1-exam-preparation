/* ===================================================================
 * Programming Techniques for Scientific Simulations I  
 * package  :   penna
 * function :   Tests for animal class
 * created  :   05/01/2024
 * author   :   DaeBlicki
 * 
 * updated  :   12/01/24
 * message  :   doctest.h overhaul
 * VERSION 1.00 (C) Copyright Free to use
 * ===================================================================*/

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "../include/Penna/animal.hpp"
#include "../include/pt1/Random.hpp"

/* ===================================================================
 * TESTS FOR ANIMAL CONSTRUCTORS
 * ===================================================================*/
TEST_SUITE("Animal Constructors"){
    // DEFAULT CONSTRUCTOR
    TEST_CASE("Animal Default Constructor"){
        pt1::Random_Number_Generator::seed(42);
        Penna::Animal animal_one = Penna::Animal();
        Penna::Animal animal_two = Penna::Animal();
        age_t maximalAge = Penna::Animal::maximalAge();
        bool identical = true;
        for(age_t age = 0; age < maximalAge; age++){
            // check if the genome is identical, if not, identical is false
            if(animal_one.genome().countBad(age) != animal_two.genome().countBad(age)){
                identical = false;
            }
        }
        CHECK_FALSE(identical);
        CHECK_FALSE(animal_one.isPregnant());
        CHECK(animal_one.age() == 0);
    }
    TEST_CASE("Animal Copy Constructor"){
        pt1::Random_Number_Generator::seed(42);
        Penna::Animal parent_animal = Penna::Animal();
        Penna::Animal child_animal = Penna::Animal(parent_animal);
        const age_t maximalAge = Penna::Animal::maximalAge();
        bool identical = true;
        for(age_t age = 0; age < maximalAge; age++){
            // check if the genome is identical, if not, identical is false
            if(parent_animal.genome().countBad(age) != child_animal.genome().countBad(age)){
                identical = false;
            }
        }
        CHECK(identical);
        CHECK(parent_animal.age() == child_animal.age());
        CHECK(parent_animal.isPregnant() == child_animal.isPregnant());
    }
}

/* ===================================================================
 * TESTS FOR ANIMAL INITIALIZATION FUNCTION
 * ===================================================================*/
TEST_SUITE("Animal Initialization") {
    TEST_CASE("Basis Animal Intialization"){
        const age_t maximalAge = Penna::Animal::maximalAge();
        constexpr double epsilon = 1e-6;
        CHECK_THROWS(Penna::Animal::init(5, maximalAge, 0.5));
        CHECK_THROWS(Penna::Animal::init(5, 1, 0 - epsilon));
        CHECK_THROWS(Penna::Animal::init(5, 1, 1 + epsilon));
    }
    TEST_CASE("Pregnancy status under reproduction age") {
        pt1::Random_Number_Generator::seed(42);
        const age_t maximalAge = Penna::Animal::maximalAge();
        const unsigned int mutation_rate = 5;
        Penna::Animal mother = Penna::Animal();

        const age_t reproductionAge = 5;
        Penna::Animal::init(mutation_rate, reproductionAge, 1.0);

        for (unsigned int i = 0; i < reproductionAge - 1; i++) {
            mother.growth();
            mother.reproduction();
        }
        CHECK(mother.isPregnant() == false);
    }

    TEST_CASE("Pregnancy after successful reproduction") {
        pt1::Random_Number_Generator::seed(42);
        const age_t maximalAge = Penna::Animal::maximalAge();
        const unsigned int mutation_rate = 5;
        Penna::Animal mother = Penna::Animal();

        const age_t reproductionAge = 5;
        Penna::Animal::init(mutation_rate, reproductionAge, 1.0);

        for (unsigned int i = 0; i < reproductionAge; i++) {
            mother.growth();
            mother.reproduction();
        }
        CHECK(mother.isPregnant() == true);
    }

    TEST_CASE("Pregnancy status after giving birth") {
        pt1::Random_Number_Generator::seed(42);
        const age_t maximalAge = Penna::Animal::maximalAge();
        const unsigned int mutation_rate = 5;
        Penna::Animal mother = Penna::Animal();

        const age_t reproductionAge = 5;
        Penna::Animal::init(mutation_rate, reproductionAge, 1.0);

        for (unsigned int i = 0; i < reproductionAge; i++) {
            mother.growth();
            mother.reproduction();
        }
        Penna::Animal child = mother.giveBirth();
        CHECK(mother.isPregnant() == false);
    }

    TEST_CASE("Genome mutation of child and mother") {
        pt1::Random_Number_Generator::seed(42);
        const age_t maximalAge = Penna::Animal::maximalAge();
        const unsigned int mutation_rate = 5;
        Penna::Animal mother = Penna::Animal();

        const age_t reproductionAge = 5;
        Penna::Animal::init(mutation_rate, reproductionAge, 1.0);

        for (unsigned int i = 0; i < reproductionAge; i++) {
            mother.growth();
            mother.reproduction();
        }
        Penna::Animal child = mother.giveBirth();

        unsigned int mother_bad_count = mother.genome().countBad(maximalAge - 1);
        unsigned int child_bad_count = child.genome().countBad(maximalAge - 1);
        unsigned int upper_range = mother_bad_count + mutation_rate;
        unsigned int lower_range = mother_bad_count - mutation_rate;
        CHECK(child_bad_count >= lower_range);
        CHECK(child_bad_count <= upper_range);
    }

    TEST_CASE("Pregnancy with 100 protection") {
        pt1::Random_Number_Generator::seed(42);
        const age_t maximalAge = Penna::Animal::maximalAge();
        const unsigned int mutation_rate = 5;
        Penna::Animal mother = Penna::Animal();

        const age_t reproductionAge = 5;
        Penna::Animal::init(mutation_rate, reproductionAge, 0);

        const unsigned int iteration = 100;
        for (unsigned int i = 0; i < iteration; i++) {
            mother.reproduction();
        }
        CHECK(mother.isPregnant() == false);
    }
}

