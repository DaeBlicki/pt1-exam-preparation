#include <iostream>
#include "Timer.hpp"

int main()
{
    pt1::Timer t = pt1::Timer();
    double sum = 0.0;
    t.start();
    for(unsigned int i = 0; i < 1000000; i++){
        sum += i;
    }
    t.stop();
    std::cout << "The sum is = " << sum << std::endl;
    std::cout << "time to sum up from 1 to 1000000: " << t.duration() << std::endl; 
}