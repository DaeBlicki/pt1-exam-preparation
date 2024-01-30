/* ==============================================================
 * Programming Techniques for Scientific Simulations I  
 * Header file defining template container functions
 * 
 * VERSION 1.00 (C) Copyright Free to use
 * ==============================================================*/

#include <vector>
#include <iostream>
#include <unordered_set>
#include <set>
#include <list>
#include <algorithm>

/*
 * fill() - template function to filling up the Container with size n
 * PRECONDITIONS:
 * @ C : Empty container from the standard library, must contain an iterator
 * @ n : n > 0
 * POST: The container is filled with the index number up to size n
 */
template <typename Container>
void fill(Container& C, const unsigned int n)
{
    C.clear();
    typename Container::iterator it;
    for (size_t i = 0; i < n; ++i) {
        it = C.insert(C.end(), i);
    }

}

/*
 * print() - debugging function to print the content of the container
 * PRE: -
 * POST: print sequence of container in the terminal
 * example: 
 * std::vector<int> myVec = {1, 2, 3};  // initialize myVec = [1, 2, 3]
 * print<std::vector<int>, int>(myVec); // output: 1 2 3
 */
template<typename Container, typename Ctype>
void print(const Container& C)
{
    auto f = [](const Ctype& idx){std::cout << idx << " ";};
    std::for_each(C.begin(), C.end(), f);
    std::cout << "\n";
}