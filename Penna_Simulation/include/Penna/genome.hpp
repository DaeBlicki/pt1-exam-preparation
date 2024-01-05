#ifndef GENOME_H
#define GENOME_H

#include <bitset>
#include <limits>
#include "../pt1/Random.hpp"


namespace Penna
{
    using parameter_t = unsigned int;
    using age_t = unsigned int;

/* 
 * Header for Penna Genome class
 */
class Genome
{
private:
    static parameter_t mutation_rate_;   /* Parameter M from Penna paper, M bits should be randomely flipped by mutation */
    static const size_t genome_size_ = std::numeric_limits<unsigned long>::digits;  /* genome size should be large as possible */

    std::bitset<genome_size_> gene_sequence_;   /* gene sequence contains one and zeros and indicates deletion at i-th age */

public:
    Genome();                   /* default constructor */            
    ~Genome();                  /* destructor */
    Genome( const Genome& );    /* copy constructor */

    static size_t getSize();                            /* getter for genome_size */
    static unsigned int getMutationRate();              /* getter for mutation_rate */
    static void setMutationRate( const parameter_t );   /* setter for mutation_rate */

    /* 
     * mutate() - the gene sequence will flipp mutation rate number of bits
     * PRE: -
     * POST: gene sequence will randomely (with RNG) flipp M (mutation rate) number of bits
     */
    void mutate();

    /*
     * countBad( const age_t ) - return number of deleterous mutation at given age
     * PRE: -
     * POST: return number of ones up to the i-th bit in gene sequence
     */
    unsigned int countBad( const age_t ) const;

    /* printSequence() - debugging purposes */
    void printSequence() const;
};

} // end namespace Penna

#endif /* GENOME_H */