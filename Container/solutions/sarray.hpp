#ifndef SARRAY_HPP
#define SARRAY_HPP

#include "my_iterator.hpp"
#include <cassert>
#include <iostream>
#include <utility> // for std::swap

// (Too!) Simple array class template
template <typename T>
class SArray {
  public:
    // member types
    using size_type = std::size_t;    // size type
    using value_type = T;             // value/element type
    using reference = T&;             // reference type
    using const_reference = T const&; // const reference type
    using iterator = MyIterator<T>;   // iterator
    // special members
    // ctors
    SArray();                   // default ctor: empty array
    explicit SArray(size_type); // ctor: array of given size
                                // (explicit to avoid sarray v = 10 creating
                                // an array of size 10!)
    // copy ctor
    SArray(SArray const&);
    // copy assignment
    SArray& operator=(SArray const&);
    #ifdef MOVE
    // move ctor
    SArray(SArray&&);
    // move assignment
    SArray& operator=(SArray&&);
    #endif
    // dtor
    ~SArray();
    // iterators
    iterator begin() const; // iterator to the beginning 
    iterator end() const;   // iterator to the end
    // element access
    reference operator[](size_type const);             // subscript operator
    const_reference operator[](size_type const) const; // const subscript
                                                       // operator
    // further utility member functions
    size_type size() const;  // size of the array
    void swap(SArray&);      // swap
    // compound arithmetic operators
    SArray& operator+=(SArray const&);
    SArray& operator-=(SArray const&);
    SArray& operator*=(SArray const&);
    SArray& operator/=(SArray const&);

  private:
    size_type size_;   // size of array
    value_type* elem_; // pointer to (dynamic) memory of array
};


// Helper for verbose output
#ifdef VERBOSE
#define VERBOSE_(X) X
#else
#define VERBOSE_(X)
#endif

// special members
// ctors
// default
template <typename T>
SArray<T>::SArray() : size_(0), elem_(nullptr) {
  VERBOSE_( std::cout << "SArray default ctor called" << std::endl; )
}
// array of given size
template <typename T>
SArray<T>::SArray(size_type size) : size_(size)
                                  , elem_(new value_type[size]) {
  VERBOSE_( std::cout << "SArray ctor with size argument called" << std::endl; )
}

// copy ctor
template <typename T>
SArray<T>::SArray(SArray const& a) : size_(a.size_)
                                   , elem_(new value_type[a.size_]) {
  VERBOSE_( std::cout << "SArray copy ctor called" << std::endl; )
  // copy elements
  for (size_type i = 0; i < size_; ++i) {
    elem_[i] = a.elem_[i];
  }
}

// copy assignment
template <typename T>
SArray<T>& SArray<T>::operator=(SArray const& rhs) {
  VERBOSE_( std::cout << "SArray copy assignment called" << std::endl; )
  SArray tmp(rhs);
  swap(tmp); // swap
  return *this;
}

#ifdef MOVE
// move ctor
template <typename T>
SArray<T>::SArray(SArray&& a) : size_(a.size_), elem_(a.elem_) {
  VERBOSE_( std::cout << "SArray move ctor called" << std::endl; )
  a.size_ = 0;
  a.elem_ = nullptr;
}
// move assignment
template <typename T>
SArray<T>& SArray<T>::operator=(SArray&& rhs) {
  VERBOSE_( std::cout << "SArray move assignment called" << std::endl; )
  swap(rhs);
  return *this;
}
#endif

// dtor
template <typename T>
SArray<T>::~SArray() {
  VERBOSE_( std::cout << "SArray dtor called" << std::endl; )
  delete[] elem_;
  elem_ = nullptr;
  size_ = 0;
}

// iterators
// begin
template <typename T>
typename SArray<T>::iterator SArray<T>::begin() const {
  return iterator(elem_, elem_, elem_ + size_);
}
// end
template <typename T>
typename SArray<T>::iterator SArray<T>::end() const {
  return iterator(elem_ + size_, elem_, elem_ + size_);
}

// element access
// subscript operator
template <typename T>
typename SArray<T>::reference SArray<T>::operator[](size_type index){
  assert(index < size());
  return elem_[index];
}
// const subscript operator
template <typename T>
typename SArray<T>::const_reference
SArray<T>::operator[](size_type index) const {
  assert(index < size());
  return elem_[index];
}

// compound arithmetic operators
template <typename T>
SArray<T>& SArray<T>::operator+=(SArray const& rhs) {
  assert(size_ == rhs.size_); // check if compatible sizes!
  for (size_type i = 0; i < size_; ++i) {
    elem_[i] += rhs.elem_[i];
  }
  return *this;
}
template <typename T>
SArray<T>& SArray<T>::operator-=(SArray const& rhs) {
  assert(size_ == rhs.size_); // check if compatible sizes!
  for (size_type i = 0; i < size_; ++i) {
    elem_[i] -= rhs.elem_[i];
  }
  return *this;
}
template <typename T>
SArray<T>& SArray<T>::operator*=(SArray const& rhs) {
  assert(size_ == rhs.size_); // check if compatible sizes!
  for (size_type i = 0; i < size_; ++i) {
    elem_[i] *= rhs.elem_[i];
  }
  return *this;
}
template <typename T>
SArray<T>& SArray<T>::operator/=(SArray const& rhs) {
  assert(size_ == rhs.size_); // check if compatible sizes!
  for (size_type i = 0; i < size_; ++i) {
    elem_[i] /= rhs.elem_[i];
  }
  return *this;
}
// further utility member functions
// size
template <typename T>
typename SArray<T>::size_type SArray<T>::size() const {
  return size_;
}
// swap member
template <typename T>
void SArray<T>::swap(SArray& other) {
  using std::swap; // let C++ determine which swap to call!
  swap(size_, other.size_);
  swap(elem_, other.elem_);
}

// free-function swap
template <typename T>
void swap(SArray<T>& a, SArray<T>& b) {
  a.swap(b);
}

// binary arithmetic operators
template <typename T>
SArray<T> operator+(SArray<T> a, SArray<T> const& b) {
  a += b;
  return a;
}
template <typename T>
SArray<T> operator-(SArray<T> a, SArray<T> const& b) {
  a -= b;
  return a;
}
template <typename T>
SArray<T> operator*(SArray<T> a, SArray<T> const& b) {
  a *= b;
  return a;
}
template <typename T>
SArray<T> operator/(SArray<T> a, SArray<T> const& b) {
  a /= b;
  return a;
}

#endif /* SARRAY_HPP */
