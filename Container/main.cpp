#include "main.hpp" // for print_reverse
#include "sarray.hpp"
#include <iostream>

int main() {

  // alias for SArray type
  using sarray_t = SArray<int>;

  // create SArray with five elements
  sarray_t a(5);

  // set some values in the array using our (forward) iterator
  std::cout << "Fill array with some values:\n";
  sarray_t::iterator end;
  end = a.end(); // copy assignment!
  // auto end = a.end(); // or copy ctor with auto (C++11)
  int i = 0;
  for (sarray_t::iterator iter = a.begin(); iter != end; ++iter) {
    *iter = i++;
    std::cout << "*iter = " << *iter << '\n';
  }

  // range-based for loop (C++11) using our (forward) iterator
  std::cout << "Print array with range-based for loop:\n";
  for (auto const& elem : a) {
    std::cout << "elem = " << elem << '\n';
  }

  print_reverse(a);

}
