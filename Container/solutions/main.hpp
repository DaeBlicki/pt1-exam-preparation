#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream> // for std::cout
#include <iterator> // for std::iterator_traits, std::bidirectional_iterator_tag
#include <type_traits> // for std::enable_if_t, std::is_base_of_v

// WARNING: INTERNAL CODE
// this code is only here to make everyone's life easier
// and make both the base exercise and the bonus compile

// we use the SFINAE idiom ("substitution failure is not an error")
// to check if `my_iterator` implements *BidirectionalIterator*
// this way, code compiles in both cases, without the hassle of commenting
// or using the preprocessor
// read more about SFINAE here:
// https://en.cppreference.com/w/cpp/language/sfinae

// Base version (without BidirectionalIterator implemented)
template<class T>
typename std::enable_if<!std::is_base_of<
  std::bidirectional_iterator_tag,
  typename std::iterator_traits<typename T::iterator>::iterator_category>::
                          value>::type
print_reverse(T const&) {
  std::cout << "my_iterator does not implement BidirectionalIterator\n";
}

// Bonus version (with BidirectionalIterator implemented)
template<class T>
typename std::enable_if<std::is_base_of<
  std::bidirectional_iterator_tag,
  typename std::iterator_traits<typename T::iterator>::iterator_category>::
                          value>::type
print_reverse(T const& a) {
  // print in reverse order using our bidirectional iterator
  std::cout << "Print array in reverse order with bidirectional iterator:\n";
  auto beg{a.begin()};
  auto iter{a.end()};
  do {
    std::cout << "*(--iter) = " << *(--iter) << '\n';
  } while (iter != beg);
}

#endif // MAIN_HPP
