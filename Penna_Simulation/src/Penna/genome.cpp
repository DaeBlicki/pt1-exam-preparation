#include "../../include/Penna/genome.hpp"
#include <iostream>
#include <set>

namespace Penna{

using position_t = size_t;

/* Definitions of the static member*/
parameter_t Genome::mutation_rate_ = 5;      /* Parameter M from Penna paper, M bits should be randomely flipped by mutation */

Genome::Genome()
{
    for(parameter_t i = 0; i < genome_size_;i++){
        unsigned int mutation_calculator = pt1::Random_Number_Generator::generate() % 100;
        bool deletion_mutation = (mutation_calculator < 50);
        gene_sequence_.set(i, deletion_mutation);
    }
}   

Genome::~Genome()
{}              

Genome::Genome( const Genome& parent_genome)
{
    gene_sequence_ = parent_genome.gene_sequence_;
} 

size_t Genome::getSize()
{
    return genome_size_;
}

unsigned int Genome::getMutationRate()
{
    return mutation_rate_;
}        
void Genome::setMutationRate(const parameter_t mutation_rate)
{
    mutation_rate_ = mutation_rate;
} 

void Genome::mutate()
{
    std::set<parameter_t> Set_contains_mutated_bits;
    while(Set_contains_mutated_bits.size() != mutation_rate_){
        unsigned int deletion_mutation = pt1::Random_Number_Generator::generate() % genome_size_;
        Set_contains_mutated_bits.insert(deletion_mutation);
    }
    for(parameter_t index: Set_contains_mutated_bits){
        gene_sequence_.flip(position_t(index));
    }
}

unsigned int Genome::countBad( const age_t age) const
{
   return (gene_sequence_ << (genome_size_ - age -1)).count();
}

 /* printSequence() - debugging purposes */
void Genome::printSequence() const
{
    const unsigned int n = genome_size_ - 1;
    for(unsigned int i = 0; i < n; i++){
        std::cout << (gene_sequence_ << i).count();
    }
    std::cout << std::endl;
}

} // end namespace penna