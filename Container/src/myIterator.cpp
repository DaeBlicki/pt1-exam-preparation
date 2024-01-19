/* ===================================================================
 * Programming Techniques for Scientific Simulations I  
 * package  :   Container 
 * function :   Implementation of myIterator class
 * created  :   19/01/2024
 * author   :   DaeBlicki
 * 
 * updated  :   xx/xx/xx
 * VERSION 1.00 (C) Copyright Free to use
 * ===================================================================*/

#include "../include/myIterator.hpp"

// Class invariant checker
bool MyIterator::check_invariants()
{
    //TODO::implementation
}


// Default Constructor
MyIterator::MyIterator() : first_(nullptr), last_(nullptr), current_(nullptr)
{
    //TODO::implementation
}                            


// Equality operator
bool MyIterator::operator==(const &MyIterator) const
{
    //TODO::implementation
}

// Inequality operator
bool MyIterator::operator!=(const &MyIterator) const
{
    //TODO::implementation
}

// Dereference Operators
reference MyIterator::operator*() const
{
    //TODO::implementation
}

// Address Operator
pointer MyIterator::operator->() const
{
    //TODO::implementation
}

// Pre-increment
MyIterator& MyIterator::operator++()
{
    //TODO::implementation
}

// Post-increment
MyIterator MyIterator::operator++(int)
{
    //TODO::implementation
}

// Pre-decrement
MyIterator& MyIterator::operator--()
{
    //TODO::implementation
}

// Post-decrement
MyIterator MyIterator::operator--(int)
{
    //TODO::implementation
}