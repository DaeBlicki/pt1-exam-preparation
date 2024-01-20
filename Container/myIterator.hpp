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
     * @ first_ <= current_ && current_ <= end_
     * POST: do nothing or throws exception if class invariant is violated
     */
    void check(bool Dereferenceable) const
    {
        bool all_null_ptr, ordered_ptr;
        all_null_ptr =  (first_ == nullptr) && (last_ == nullptr) && (current_ == nullptr);
        ordered_ptr = (first_ <= current_) && (current_ <= last_);
        if(Dereferenceable && "The iterator must be dereferenceable!"){
            if(ordered_ptr == false){
                throw std::logic_error("Dereferenceable pointer have not ordered pointers! \n");
            }
        } 
        if(!Dereferenceable && "The iterator must not be dereferenceable!"){
            if(all_null_ptr || ordered_ptr){
                return;
            }
            throw std::logic_error("Not deferenceable pointer have not all nullptr or ordered pointers! \n");
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
    MyIterator& operator=(const MyIterator&) = default;

    /* ===============================
     * myIterator Logical Operators
     * ===============================*/
    
    // Equality Operator
    bool operator==(const MyIterator& rhs) const
    {
        return (current_ == rhs.current_)
            && (last_ == rhs.last_)
            && (first_ == rhs.first_);
    }

    // Inequality Operator
    bool operator!=(const MyIterator& rhs) const
    {
        return !(*this == rhs);
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
        MyIterator old = this;
        ++(*this);
        return old;
    }

    // prefix decrement
    MyIterator& operator--()
    {
        check(true);
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
