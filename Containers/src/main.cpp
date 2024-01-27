/* ===================================================================
 * Programming Techniques for Scientific Simulations I  
 * package  :   Container
 * function :   Benchmark the various standard container
 * created  :   20/01/2024
 * author   :   DaeBlicki
 * 
 * updated  :   xx/xx/xx
 * VERSION 1.00 (C) Copyright Free to use
 * ===================================================================*/

#include <iostream>
#include <iomanip>
#include "../include/container.hpp"

int main()
{
    std::vector<unsigned int> myVector; // create Vector
    std::list<unsigned int> myList;     // create List
    std::set<unsigned int> mySet;       // create Set
    
    // printing the header for vector
    std::cout << "Benchmark the Standard Vector: \n";
    measure(myVector);
    std::cout << "\n";

    // printing the header for list
    std::cout << "Benchmark the Standard List \n";
    measure(myList);
    std::cout << "\n";

    // printing the header for set
    std::cout << "Benchmark the Standard Set \n";
    measure(mySet);
    std::cout << "\n";

    // printing out content of Container fast
    auto print = [](const unsigned int &n){std::cout << n << " ";};
    fill(myVector, 10);
    fill(mySet, 10);
    fill(myList, 10);

    double incr = 0.;
    std::for_each(myVector.begin(), myVector.end(), [](unsigned int &n){n = 2*n;});
    std::for_each(myList.begin(), myList.end(), [&](unsigned int &n){incr += n;});

    std::cout << "print std::vector \n";
    std::for_each(myVector.begin(), myVector.end(), print);
    std::cout << "\n";
    std::cout << "print std::list \n";
    std::for_each(myList.begin(), myList.end(), print);
    std::cout << "\n";
    std::cout << "sum = " << std::setprecision(0) << std::fixed << incr << "\n";    
    std::cout << "print std::set \n";
    std::for_each(mySet.begin(), mySet.end(), print);

    return 0;
}


