/* ==============================================================
 * Programming Techniques for Scientific Simulations I  
 * Header file defining complex numbers
 * 
 * VERSION 1.00 (C) Copyright Free to use
 * ==============================================================*/

#include <vector>
#include <set>
#include <list>
#include <algorithm>
#include "pt1/Timer.hpp"

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

// printHeader() - printing the header of the table
void printHeader();

// printLine() - printing the line of the table
void printLine(const unsigned int N, const double timeVec, 
            const double timeList, const double timeSet);


/*
 * measure() - measure and printing out the time table of the Container
 * PRE: Empty container C from the standard library, must contain an iterator
 * POST: printing the time table to create, insert and erase first element
 */
template <typename Container>
void measure(Container& C)
{
    const unsigned int N = 10000;
    double timeToCreate, timeToInsert, timeToErase;
    pt1::Timer T;
    printHeader();
    for(unsigned int n = 1; n <= N; n *= 10){
        // filling up the container
        T.start();
        fill(C, n);
        T.stop();
        timeToCreate = T.duration();
        // insert at first element
        T.start();
        C.insert(C.begin(), 0);
        T.stop();
        timeToInsert = T.duration();
        // remove first element
        T.start();
        C.erase(C.begin());
        T.stop();
        timeToErase = T.duration();
        printLine(n, timeToCreate, timeToInsert, timeToCreate);
    }

}

// printHeader() - printing the header of the table
void printHeader()
{
    std::cout   << std::setw(10) << "N"
                << std::setw(15) << "Creating"
                << std::setw(15) << "Inserting"
                << std::setw(15) << "Erasing"
                << "\n"
                << "------------------------------------------------------- \n";
}

// printLine() - printing the line of the table
void printLine(const unsigned int size, const double timeToCreate, 
            const double timeToInsert, const double timeToErase)
{
    std::cout   << std::setw(10) << std::setprecision(0) << std::fixed << size
                << std::setw(15) << std::setprecision(3) << std::scientific << timeToCreate
                << std::setw(15) << std::setprecision(3) << std::scientific << timeToInsert
                << std::setw(15) << std::setprecision(3) << std::scientific << timeToErase
                << "\n";
}

/*
 * benchmark_foreach() - benchmark and iterate over standard container with foreach
 * PRE: function f with operator()(double) that return double
 * POST: print out the time needed to iterate with foreach
 */
template <typename Function>
void benchmark_foreach(const Function& f)
{
    std::vector<double> myVec;  //< create std::vector
    std::list<double> myList;   //< create std::list
    std::set<double> mySet;     //< create std::set

    /* =========================
     * Printing out the header
     * =========================*/

    std::cout   << std::setw(5) << "N"
                << std::setw(15) << "std::vector"
                << std::setw(15) << "std::list"
                << std::setw(15) << "std::set"
                << "\n"
                << "-------------------------------------------------- \n";

    pt1::Timer vec_timer, list_timer, set_timer;
    for(unsigned int i = 0; i < 10; i++){
        /* ===================================
         * Filling up the data for the table
         * ===================================*/
        const unsigned int M = 10*(1 << i);
        //< clear and fill all containers
        fill(myVec, M);
        fill(myList, M);
        fill(mySet, M);
        //< time foreach
        vec_timer.start();
        std::for_each(myVec.begin(), myVec.end(), f);
        vec_timer.stop();
        list_timer.start();
        std::for_each(myList.begin(), myList.end(), f);
        list_timer.stop();
        set_timer.start();
        std::for_each(mySet.begin(), mySet.end(), f);
        set_timer.stop();
        //< print out line
            std::cout << std::setw(5) << std::setprecision(0) << std::fixed << M
                << std::setw(15) << std::setprecision(3) << std::scientific << vec_timer.duration()
                << std::setw(15) << std::setprecision(3) << std::scientific << list_timer.duration()
                << std::setw(15) << std::setprecision(3) << std::scientific << set_timer.duration()
                << "\n";
    }
}