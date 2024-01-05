#ifndef ANIMAL_H
#define ANIMAL_H

#include "genome.hpp"
#include <tuple>

using age_t = unsigned int;

// Penna namespace
namespace Penna
{

class Animal
{
protected:
    Genome gen_;              /* individual genome at birth */
    age_t age_;                     /* current age of the animal */
    bool pregnant_;                 /* state of pregnancy */
    
    static unsigned int deletion_threshhold_;   /* maximal number of deletion of animal */
    static age_t reproduction_age_;             /* minimal age for reproduction of animal */
    static double propability_to_get_pregnant_; /* percentage to get pregnant [0, 1] */
    static age_t const maximal_age_ = std::numeric_limits<unsigned long>::digits;    /* maximal age is equals genome size*/
    
public:
    Animal();                   /* Default constructor */
    ~Animal();                  /* Destructor */
    Animal( const Animal& );    /* Copy Constructor */
    Animal( const Genome&, const age_t, const bool);

    bool operator<( const Animal& );    /* lesser operator*/
    bool operator>( const Animal& );    /* lesser operator*/
    bool operator==( const Animal& );    /* lesser operator*/


    age_t age() const;          /* Return the age of the animal */
    bool isPregnant() const;    /* Return value if the animal is pregnant */
    Genome genome() const;      /* Return the genome of the animal */
    static age_t maximalAge();  /* Return the maximal age of the animal*/

    /*
     * giveBirth() - Animal giving birth to another animal and lose pregnancy state
     * PRE: Animal is pregnant for approximately 1 year
     * POST: return animal with gen = mutated mother genome and age = 0 
     */
    Animal giveBirth();

    /*
     * reproduction() - Animal is trying to inpregnate himself assexually
     * PRE: Animal age is not pregnant and atleast reproduction age
     *      * POST: Animal has probability_to_get_pregnant chance to get pregnant
     */
    void reproduction(); 

    /*
     * growth() - Animal is getting older
     * PRE: -
     * POST: Animal is one year older
     */
    void growth();

    /*
     * survive() - Animal is trying to survive against the mutation and force of nature
     * PRE: Verhulst factor and deletion threshhold is is known
     * POST: Animal is dead if deletion > threshhold or bad luck (RNG based)
     */
    bool survive( const double );

    /*
     * init() - initialize the static member for the animal class
     * PRE: deletion_treshhold_, reproduction_age_ <= genome size and probability_to_get_pregnant_ is [0, 1]
     * POST: animal class is initialized
     */
    static void init( const unsigned int, const age_t, const double );

    /* 
     * getInitialization() - Access to the static member of Animal
     * PRE: Animal is initialized
     * POST: return tuple<threshhold_parameter, reproduction_parameter, pregnancy_parameter>
     */
    static std::tuple<unsigned int, age_t, double> getInitialization();
};

} // end namespace Penna

#endif /* ANIMAL_H */