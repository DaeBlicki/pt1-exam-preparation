#include "complex.hpp"
#include <iostream>

int main(){
    Complex a = Complex(0.0, 4.0);
    Complex b = Complex(3.0, 0.0);
    std::cout << a << "+" << b << " = " << a+b << std::endl;
    std::cout << a << "-" << b << " = " << a-b << std::endl;
    std::cout << a << "*" << b << " = " << a*b << std::endl;
    std::cout << a << "/" << b << " = " << a/b << std::endl;

    std::cout << "norm of a + b = " << (a+b).norm() << std::endl;
    std::cout << "confirm a + b = " <<  a+b << "\n";
    Complex c;
    std::cin >> c;
    std::cout << c << std::endl;

    return 0;
}