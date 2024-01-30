/* ===================================================================
 * Programming Techniques for Scientific Simulations I  
 * package  :   pt1_Library
 * function :   STL algorithm example
 * created  :   30/01/2024
 * author   :   DaeBlicki
 * 
 * updated  :   xx/xx/xx
 * VERSION 1.00 (C) Copyright Free to use
 * ===================================================================*/

#include "include/container.hpp"

int main()
{
    /* =========================================================
     * Create Datastructure std::vector, std::list and std::set
     * =========================================================*/
    std::vector<int> myVec = {5, 5, 3, 2, 4, 0, 0, 1, 3, 3};           //< myVec = [5 5 3 2 4 0 0 1 3 3]
    std::list<int> myList = {5, 5, 3, 2, 4, 0, 0, 1, 3, 3};            //< myList = [5 5 3 2 4 0 0 1 3 3]
    std::unordered_set<int> mySet = {5, 5, 3, 2, 4, 0, 0, 1, 3, 3};    //< mySet = [1 0 4 2 3 5]

    /* ===============================
     * Reordering Element Algorithms
     * ===============================*/
    std::sort(myVec.begin(), myVec.end());              //< myVec = [0 0 1 2 3 3 3 4 5 5]
    //< partion function: seperate by odd and even
    auto is_odd = [](int &n)->bool{
        return (n % 2 == 1);
    };
    auto it = std::partition(myVec.begin(), myVec.end(), is_odd);
    std::reverse(myList.begin(), myList.end());         //< myList = [3 3 1 0 0 4 2 3 5 5]

    /* ========================================================
     * Debugging Code (print content of Container in Terminal)
     * ========================================================*/
    print<std::vector<int>, int>(myVec);
    print<std::list<int>, int>(myList);
    print<std::unordered_set<int>, int>(mySet);


    
    return 0;
}