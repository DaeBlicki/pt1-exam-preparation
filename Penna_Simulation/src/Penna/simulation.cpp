#include "../../include/Penna/simulation.hpp"
#include <iostream>
#include <fstream>
#include <error.h>
#include <iomanip>
#include <matplot/matplot.h>

namespace Penna{

Simulation::Simulation()
{
    years_ = 0;
    population_ = Penna::Population();
    Random_Number_Generator_Seed_ = 42;
    Mutation_Rate_Parameter_ = 0;
    Starting_Size_ = 0;
    Maximal_Size_ = 0;
}

void Simulation::init()
{
    if(Maximal_Size_ != 0 || Starting_Size_ != 0){
        throw std::runtime_error("Simulation is already initialized! \n");
    }
    std::cout << "Initialization Menu of the Penna Simulation \n \n";

    /* Initialize the seed of the Random Number Generator */
    std::cout << "The Penna Simulation is based on Random Number Generator. \n";
    std::cout << "Enter the random number generator initializing seed! \n";
    std::cout << "Valid arguments: 0, 1, 2, 3, ..., 2^32 - 1 \n";
    std::cin >> Random_Number_Generator_Seed_;
    while(Random_Number_Generator_Seed_ < 0 || Random_Number_Generator_Seed_ > (1<<31)){
        std::cout << "Invalid argument: enter this parameter again! \n";
        std::cin >> Random_Number_Generator_Seed_;
    }
    pt1::Random_Number_Generator::seed(Random_Number_Generator_Seed_);
    std::cout << "\n";

    /* Initialize the Genome Mutation Rate */
    const unsigned int highest_mutation_rate = std::numeric_limits<unsigned long>::digits;
    std::cout << "The newborn child will get a mutated version of his mother genome. \n";
    std::cout << "An high mutation rate will cause an heavy mutated genome. \n";
    std::cout << "Enter the mutation rate of the genome! \n";
    std::cout << "Valid arguments: 0, 1, 2, ..., " << highest_mutation_rate << " \n";
    std::cin >> Mutation_Rate_Parameter_;
    while(Mutation_Rate_Parameter_ < 0 || Mutation_Rate_Parameter_ > highest_mutation_rate){
        std::cout << "Invalid argument: enter this parameter again! \n";
        std::cin >> Mutation_Rate_Parameter_;
    }
    Penna::Genome::setMutationRate(Mutation_Rate_Parameter_);
    std::cout << "\n";

    /* Define which Species should be used, or define your own animal class */
    const unsigned int highest_threshhold = std::numeric_limits<unsigned long>::digits;
    std::cout << "The properties of an animal is a crucial factor for the survival of the population. \n";
    std::cout << "Choose the properties for the animal you want to simulate: \n \n";

    /* Define animal static mutation threshhold */
    std::cout << "Deleterious mutations is a natural process in the evolution to prevent immortality. \n";
    std::cout << "Animals can suffer a limited number of deleterious mutations before it dies. \n";
    std::cout << "A low mutation tolerance will make the animal vulnerable to mutations. \n";
    std::cout << "Enter mutation tolerance for the animal! \n";
    std::cout << "Valid arguments: 1, 2, ..., " << highest_threshhold-1 << " \n";
    unsigned int threshhold_parameter;
    std::cin >> threshhold_parameter;
    while(threshhold_parameter <= 0 || threshhold_parameter > highest_threshhold-1){
        std::cout << "Invalid argument: enter this parameter again! \n";
        std::cin >> threshhold_parameter;
    }
    std::cout << "\n";

    /* Define animal static reproduction age */
    std::cout << "Metamorphosis is a process where the animal transform from child to adult \n";
    std::cout << "Being an adult sucks, however, it gives opportunity to reproduce :) \n";
    std::cout << "Penna animals have no sex and therefore, will reproduce assexually through mitosis. \n";
    std::cout << "The reproduction age describes at which age, the animals metamorphosis has ended. \n";
    std::cout << "Enter reproduction age for the animal! \n";
    std::cout << "Valid arguments: 0, 1, 2, ..., " << highest_threshhold-1 << " \n";
    unsigned int reproduction_parameter;
    std::cin >> reproduction_parameter;
    while(reproduction_parameter > highest_threshhold-1){
        std::cout << "Invalid argument: enter this parameter again! \n";
        std::cin >> reproduction_parameter;
    }
    std::cout << "\n";

    /* Define animal static pregnancy chance */
    std::cout << "The assexual animals can get pregnant (However this should work?). \n";
    std::cout << "After reaching the reproduction age, the individual can get pregnant spontaneously! \n";
    std::cout << "Enter probability to get pregnant [0, 1] for the assexual animal! \n";
    std::cout << "Valid arguments: 0, 0.3, 0.9, 1 \n";
    double pregnancy_parameter;
    std::cin >> pregnancy_parameter;
    while(pregnancy_parameter < 0 || pregnancy_parameter > 1){
        std::cout << "Invalid argument: enter this parameter again! \n";
        std::cin >> pregnancy_parameter;
    }
    Penna::Animal::init(threshhold_parameter, reproduction_parameter, pregnancy_parameter);
    std::cout << "\n";
    

    /* Enter maximal size of the population */
    std::cout << "Animals are social individual and live in groups so called populations. \n";
    std::cout << "The size of the population is limited due to the avaible resources of the environment. \n";
    std::cout << "Environments with little ressources, cannot maintain a lot of animals without any issues. \n";
    std::cout << "Thus, an environment can only mantain a maximal amount of animals. \n";
    std::cout << "Enter the maximal amount of animals the environment can maintain! \n";
    std::cout << "Valid arguments: 2, 3, ..., " << UINT64_MAX << " \n";
    std::cin >> Maximal_Size_;
    while(Maximal_Size_ < 2){
        std::cout << "Invalid argument: enter this parameter again! \n";
        std::cin >> Maximal_Size_;
    }
    std::cout << "\n";

    /* Enter starting size of teh population */
    std::cout << "The bottleneck effect often occurs after a natural disaster like earthquakes or tsunamis. \n";
    std::cout << "Massive reduction of a population's size cause randomized genetic pool of the population. \n";
    std::cout << "The animals starting the population, will also have randomized genes. \n";
    std::cout << "Enter the starting size of the population! \n";
    const unsigned int it = Maximal_Size_ - 1;
    std::cout << "Valid arguments: ";
    if(Maximal_Size_ == 2){
        std::cout << "1 or 2 \n";
    } else if(Maximal_Size_ == 3){
        std::cout << "1, 2 or 3 \n";
    } else if(Maximal_Size_ == 4){
        std::cout << "1, 2, 3 or 4 \n";
    } else{
        std::cout << "1, 2, 3, ..., " << Maximal_Size_ << " \n";
    }
    std::cin >> Starting_Size_;
    while(Starting_Size_ > Maximal_Size_){
        std::cout << "Invalid argument: enter this parameter again! \n";
        std::cin >> Starting_Size_;
    }
    std::cout << std::endl;
    
    population_.start(Starting_Size_, Maximal_Size_);
}

/*
* simulate() - simulate the penna simulation and return the distinction yearc
* PRE: Simulation is initialized
* POST: Population is distinct and result is given in output file
*/
void Simulation::simulate()
{
    std::cout << "PENNA SIMULATION STARTED! \n";
    while(population_.survived() && years_ <= 500){
        population_.timeStep();
        years_++;
    }
    if(population_.survived()){
        std::cout << "Population can survive over 10'000 years! \n";
    } else {
        std::cout << "Population survived: " << years_ << " years! \n";
    }
    std::cout << "PENNA SIMULATION ENDED! \n";
}

/*
* simulate_with_visuals() - simulate the penna simulation and show graphical result
* PRE: Simulation is initialized
* POST: Population is distinct and each timestep is visually presented
*/
void Simulation::simulate_with_visuals()
{
    const std::string file_path = "../doc/Simulation_results/";
    std::cout << "PENNA SIMULATION STARTED! \n";
    std::vector<unsigned int> size_vector;
    std::vector<unsigned int> bad_mutation_vector;
    while(population_.survived() && years_ <= 500){
        size_vector.push_back(population_.size());
        bad_mutation_vector.push_back(population_.countBadPerAnimal());
        population_.timeStep();
        years_++;
    }
    if(population_.survived()){
        std::cout << "Population can survive over 500 years! \n";
    } else {
        std::cout << "Population survived: " << years_ << " years! \n";
    }
    matplot::bar(size_vector);
    matplot::save("../doc/Simulation_results/population_size", "png");
    matplot::bar(bad_mutation_vector);
    matplot::save("../doc/Simulation_results/mutation_per_animals", "png");
    /*
    matplot::plot(age_vector, size_vector);
    matplot::title("Penna Simulation");
    matplot::xlabel("years");
    matplot::ylabel("survived animals");
    matplot::show();
    */
    std::cout << "PENNA SIMULATION ENDED! \n";

}

void Simulation::saveResult()
{
    /* 1. Open result file */
    std::string file_path = "../doc/Simulation_results/parameter.txt";
    std::ofstream result_file(file_path, std::ofstream::trunc);
    if(result_file.is_open()){
        /* 2. Process result file */
        const unsigned int Parameter_White_Space = 30;
        const unsigned int Value_White_Space = 10;

        /* HEADER FOR THE PARAMETER PART */
        result_file << "Penna Simulation VERSION 1.0 \n";
        result_file << std::setw(Parameter_White_Space) << "Parameter" 
                    << std::setw(Value_White_Space) << "Value"
                    << std::endl;

        // Random Number Generator parameter
        result_file << std::setw(Parameter_White_Space) << "Random Seed = " 
                    << std::setw(Value_White_Space) << Random_Number_Generator_Seed_ << "\n";

        // Genome Parameter
        result_file << std::setw(Parameter_White_Space) << "Mutation Rate = " 
                    << std::setw(Value_White_Space) << Mutation_Rate_Parameter_ << "\n";

        // Animal static members
        std::tuple<unsigned int, age_t, double> Animal_members = Penna::Animal::getInitialization();
        const unsigned int threshhold_parameter = std::get<0>(Animal_members);
        const age_t reproduction_parameter = std::get<1>(Animal_members);
        const double pregnancy_parameter = std::get<2>(Animal_members);
        result_file << std::setw(Parameter_White_Space) << "Threshhold Parameter  = "   
                    << std::setw(Value_White_Space) << threshhold_parameter << "\n"

                    << std::setw(Parameter_White_Space) << "Reproduction Parameter = " 
                    << std::setw(Value_White_Space) << reproduction_parameter << "\n"

                    << std::setw(Parameter_White_Space) << "Pregnancy Parameter = "    
                    << std::setw(Value_White_Space) << pregnancy_parameter << "\n";

        // Save the results (start size, max size and years)
        result_file << std::setw(Parameter_White_Space) << "Starting Size = "   
                    << std::setw(Value_White_Space) << Starting_Size_ << "\n"
                    << std::setw(Parameter_White_Space) << "Maximal Size = "   
                    << std::setw(Value_White_Space) << Maximal_Size_ << "\n"
                    << std::setw(Parameter_White_Space) << "Survived Years = "   
                    << std::setw(Value_White_Space) << years_ << "\n";
        /* 3. close file */
        result_file.close();
        if(result_file.is_open()){
            std::cerr << "ERROR: Result File could not be closed! \n";
        }else{
            std::cout << "Result File successfully closed! \n";
        }
        
    } else {
        /* ERROR HANDLING: FILE CANNOT BE OPENED! */
        std::cerr << "ERROR: Result File could not be opened! \n";
    }
}





} // end namespace Penna