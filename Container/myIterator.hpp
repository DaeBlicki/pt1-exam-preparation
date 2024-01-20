#ifndef MY_ITERATOR_HPP
#define MY_ITERATOR_HPP

#include <cassert>
#include <iostream> // for debugging
#include <iterator> // for iterator category tags

// My Iterator
template <typename T>
class MyIterator 
{
public:
    /* ===============================================
     * myIterator used alias to increase readability
     * ===============================================*/
    using reference = T&;   // type of address to the type of values
    using pointer = T*;     // type of pointer to the type of values
    using value_type = T;   // type of values by dereferencing the iterator

    // signed integer type to represent distance between iterators
    using difference_type = std::size_t;

    // category of iterator
    using iterator_category = std::bidirectional_iterator_tag;
private:
    /* ==========================================================
     * myIterator private member variables and invariant checker
     * ==========================================================*/
    pointer first_;     //< store the pointer to the first element 
    pointer last_;      //< store the pointer to the element AFTER last element
    pointer current_;   //< store the pointer to current element

    /*
     * check() - checks the class invariant of the current iterator
     * PRECONDITION:
     * @ initialized or empty: all nullptr
     * @ first_ < end_ && first_ <= current_
     * POST: do nothing or throws exception if class invariant is violated
     */
    void check(bool Dereferenceable) const
    {
        bool itChecksOut;
        if (Dereferenceable) {  // must be dereferenceable
            itChecksOut = (first_ <= current_) && (current_ <= last_);
        } else {  // does not have to be dereferenceable
            bool allNullPtr = (first_ == nullptr)     // catches case
                            && (current_ == nullptr)     // of default ctored
                            && (last_ == nullptr);     // iterator
        itChecksOut =
            allNullPtr || ((first_ <= current_) && (current_ <= last_));
        }
        if(!itChecksOut){
            throw std::logic_error("MyIterator class invariants violated! \n");
        }
    }

public:
    /* ======================================================
     * myIterator Constructors (Default, Move, Copy & Dtor)
     * ======================================================*/
    MyIterator() : first_(nullptr), last_(nullptr), current_(nullptr)
    {
        check(false);
    }
    
    MyIterator(pointer current, pointer first, pointer last)
        : first_(first), last_(last), current_(current)
    {
        check(false);
    }
    
    MyIterator(const MyIterator&) = default;

    ~MyIterator() = default;

    /* =====================================
     * Dereference and Reference Operators
     * =====================================*/

    // Dereference current ppointer
    reference operator*() const
    {
        check(true);
        return *current_;
    }   

    // Return address of current pointer
    pointer operator->() const
    {
        check(true);
        return current_;
    }   

    /* ===============================
     * myIterator Assignment Operator
     * ===============================*/
    MyIterator& operator=(const MyIterator& rhs)
    {
        first_ = rhs.first_;
        current_ = rhs.current_;
        last_ = rhs.last_;
        check(false);
        return *this;
    }


    /* ===============================
     * myIterator Logical Operators
     * ===============================*/
    
    // Equality Operator
    bool operator==(const MyIterator& rhs) const
    {
    return (first_ == rhs.first_            // check that beginnings match
            && current_ == rhs.current_     // check that current position match
            && last_ == rhs.last_);         // check that endings match
    }

    // Inequality Operator
    bool operator!=(const MyIterator& rhs) const
    {
        return !(*this == rhs);  // DRY: use of equality
    }   

    /* ======================================
     * myIterator Increments and Decrements
     * ======================================*/

    // prefix increment
    MyIterator& operator++()
    {
        check(true);
        current_++;
        return *this;
    }

    // postfix increment (DRY application)
    MyIterator operator++(int)
    {
        MyIterator old = *this;
        ++(*this);
        return old;
    }

    // prefix decrement
    MyIterator& operator--()
    {
        check(false);
        current_--;
        check(true);
        return *this;
    }

    // postfix decrement (DRY application)
    MyIterator operator--(int)
    {
        MyIterator old = *this;
        --(*this);
        return old;
    }
};

#endif /* MY_ITERATOR_HPP */
