#ifndef MY_ITERATOR_HPP
#define MY_ITERATOR_HPP

#include <cassert>
#include <iostream>  // for debugging
#include <iterator>  // for iterator category tags

/*
Forward & bidirectional iterators requirements:

Iterator:
- CopyConstructible
- CopyAssignable
- Destructible
- Supports: *a (Dereferenceable)
- Supports: ++a (Preincrementable)

Input Iterator:
- All requirements of an iterator.
- Supports: == (EqualityComparable)
- Supports: !=
- Supports: ->
- Supports: a++ (Postincrementable)

Forward Iterator:
- All requirements of an input iterator
- DefaultConstructible
- Supports expression: *a++

Bidirectional Iterator:
- All requirements of a forward iterator
- Predecrementable
- Postdecrementable
- Supports expression: *a--

*/

// my iterator
template <typename T>
class MyIterator {
 public:
  // member types
  using value_type = T;  // type of values obtained when dereferencing the
                         // iterator
  using difference_type = std::size_t;  // signed integer type to represent
                                        // distance between iterators
  using reference = T&;                 // type of reference to type of values
  using pointer = T*;                   // type of pointer to the type of values
  // using iterator_category = std::forward_iterator_tag; // category of
  //                                                      // the iterator
  using iterator_category = std::bidirectional_iterator_tag;  // category of
                                                              // the iterator
  // special members
  // ctor
  MyIterator(pointer p_curr, pointer p_begin, pointer p_end)
      : p_curr_(p_curr), p_begin_(p_begin), p_end_(p_end) {
    assert(check(false));
  };
  // copy ctor
  MyIterator(MyIterator const&) = default;
  // copy assignment
  MyIterator& operator=(MyIterator const&) = default;
  // dtor
  ~MyIterator() {}
  // dereference operator
  reference operator*() const {
    assert(check(true));
    return *p_curr_;
  }
  // prefix increment operator
  MyIterator& operator++() {
    assert(check(true));
    ++p_curr_;
    return *this;
  }
  // so far we model an iterator
  // equality operator
  bool operator==(MyIterator const& rhs) const {
    return (p_begin_ == rhs.p_begin_   // check that beginnings match
            && p_curr_ == rhs.p_curr_  // check that current position match
            && p_end_ == rhs.p_end_);  // check that endings match
  }
  // inequality operator (implemented in terms of equality operator!)
  bool operator!=(MyIterator const& rhs) const {
    return !(*this == rhs);  // note that we reuse the operator== (DRY!)
  }
  // arrow operator
  pointer operator->() const {
    assert( check(true) );
    return p_curr_;
  }
  // postfix increment operator
  MyIterator operator++(int) {
    MyIterator old = *this;  // copy necessary!
    ++(*this);               // we reuse the prefix increment (DRY!)
    return old;              // return old here!
  }
  // so far we model an input iterator
  // default ctor
  MyIterator() : p_curr_(nullptr), p_begin_(nullptr), p_end_(nullptr) {
    assert(check(false));
  };
  // so far we model a forward iterator
  // prefix decrement operator
  MyIterator& operator--() {
    assert(check(false));  // check!
    --p_curr_;
    assert(check(true));  // check!
    return *this;
  }
  // postfix decrement operator
  MyIterator operator--(int) {
    MyIterator old = *this;  // copy necessary!
    --(*this);               // we reuse the prefix increment (DRY!)
    return old;              // return old here!
  }
  // now we model a bidirectional iterator
 private:
  // private data members
  pointer p_curr_;   // current position pointer
  pointer p_begin_;  // pointer to beginning
  pointer p_end_;    // pointer to "one past" the end
  // check iterator
  bool check(bool Dereferenceable) const {
    bool itChecksOut;
    if (Dereferenceable) {  // must be dereferenceable
      itChecksOut = (p_begin_ <= p_curr_) && (p_curr_ < p_end_);
    } else {  // does not have to be dereferenceable
      bool allNullPtr = (p_begin_ == nullptr)    // catches case
                        && (p_curr_ == nullptr)  // of default ctored
                        && (p_end_ == nullptr);  // iterator
      itChecksOut =
          allNullPtr || ((p_begin_ <= p_curr_) && (p_curr_ <= p_end_));
    }
    return itChecksOut;
  }
};

#endif /* MY_ITERATOR_HPP */
