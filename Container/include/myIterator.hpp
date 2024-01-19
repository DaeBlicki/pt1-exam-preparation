/* ==============================================================
 * Programming Techniques for Scientific Simulations I  
 * Header file defining complex numbers
 * 
 * VERSION 1.00 (C) Copyright Free to use
 * ==============================================================*/

#ifndef MY_ITERATOR_HPP
#define MY_ITERATOR_HPP

#include <cassert>
#include <iostream> // for debugging
#include <iterator> // for iterator category tags

// My Iterator
template <typename T>
class MyIterator {
    using value_type = T;   // type of values obtained when dereferencing the
                            // iterator
    using reference = T&;   // type of reference to type of values
    using pointer = T*;     // type of pointer to the type of values

    // signed integer type to represent distance between iterators
    using difference_type = std::size_t;

    // category of iterator
    using iterator_category = std::bidirectional_iterator_tag;

private:
    // myIterator private member variables
    size_t size_;       //< store the size of the container 
    pointer first_;     //< store the pointer to the first element 
    pointer last_;      //< store the pointer to the last element
    pointer current_;   //< store the pointer to current element

    // myIterator private member functions
    void check_invariants();    //< check invariants and throw exceptions

public:
    // Constructors
    MyIterator();                                   //< Default Ctor
    MyIterator(const &MyIterator ) = default;       //< Copy Ctor
    ~MyIterator() = default;                        //< Dtor

    // Assignement Operator
    MyIterator& operator=(const &MyIterator) = default;

    // Logical Operators
    bool operator==(const &MyIterator) const;    //< Equality
    bool operator!=(const &MyIterator) const;    //< Inequality

    // Dereference and Refernce Operators
    reference operator*() const;     //< Dereference current pointer
    pointer operator->() const;      //< Return address of current pointer

    // Increments and Decrements
    MyIterator& operator++();   //< prefix increment
    MyIterator operator++(int); //< postfix increment
    MyIterator& operator--();   //< prefix decrement
    MyIterator operator--(int); //< postfix decrement
};

#endif /* MY_ITERATOR_HPP */
