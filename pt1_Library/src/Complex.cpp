/* ===================================================================
 * Programming Techniques for Scientific Simulations I  
 * package  :   pt1_Library
 * function :   complex numbers representation and complex arithmetic
 * created  :   05/01/2024
 * author   :   DaeBlicki
 * 
 * updated  :   xx/xx/xx
 * VERSION 1.00 (C) Copyright Free to use
 * ===================================================================*/

#include "../include/Complex.hpp"
#include <stdexcept>

// namespace pt1 Librar
namespace pt1{

Complex::Complex()
{
    real_ = 0.0;
    imaginary_ = 0.0;
}

Complex::~Complex(){}

Complex::Complex( const Complex& c )
{
    real_ = c.getReal();
    imaginary_ = c.getImaginary();
}

Complex::Complex( const double x, const double y) 
{
    real_ = x;
    imaginary_ = y;
}

const Complex& Complex::operator=(const Complex& c)
{
    real_ = c.getReal();
    imaginary_ = c.getImaginary();
    return *this;
}

double Complex::getReal() const
{
    return real_;
}

double Complex::getImaginary() const
{
    return imaginary_;
}

void Complex::setReal(const double x)
{
    real_ = x;
}

void Complex::setImaginary(const double y)
{
    imaginary_ = y;
}

double Complex::norm() const
{
    return sqrt(real_*real_ + imaginary_*imaginary_);
}

/* Assignment operators */
Complex& operator+=(Complex& a, const Complex& b)
{
    const double x = a.getReal() + b.getReal();
    const double y = a.getImaginary() + b.getImaginary();
    a.setReal(x);
    a.setImaginary(y);    
    return a;
}

Complex& operator-=(Complex& a, const Complex& b)
{
    const double x = a.getReal() - b.getReal();
    const double y = a.getImaginary() - b.getImaginary();
    a.setReal(x);
    a.setImaginary(y);  
    return a;
}

Complex& operator*=(Complex& a, const Complex& b)
{
    const double x = a.getReal() * b.getReal() - a.getImaginary() * b.getImaginary();
    const double y = a.getImaginary() * b.getReal() + a.getReal() * b.getImaginary();
    a.setReal(x);
    a.setImaginary(y);
    return a;

}

Complex& operator/=(Complex& a, const Complex& b)
{
    const double x1 = a.getReal(); const double y1 = a.getImaginary();
    const double x2 = b.getReal(); const double y2 = b.getImaginary();
    if(x2 == 0 && y2 == 0){
        throw std::runtime_error("Cannot divide by zero! \n");
    }
    const double x = (x1*x2 + y1*y2)/(x2*x2 + y2*y2);
    const double y = (y1*x2 - x1*y2)/(x2*x2 + y2*y2);
    a.setReal(x);
    a.setImaginary(y);
    return a;
}

/* Input output operators */
std::ostream& operator<<(std::ostream& out, const Complex& c)
{
    out << "(" << c.getReal() <<"," << c.getImaginary() <<")";
}

std::istream& operator>>(std::istream& in, Complex& c)
{
    double x, y;
    char check;
    in >> check;
    if(check != '('){
        throw std::runtime_error("Complex input have to start with '(' \n");
    }
    in >> x;
    in >> check;
    if(check != ','){
        throw std::runtime_error("Complex input have to seperate x and y with ',' \n");
    }
    in >> y;
    in >> check;
    if(check != ')'){
        throw std::runtime_error("Complex input have to end with ')' \n");
    }
    c.setReal(x);
    c.setImaginary(y);
    return in;
}

/* Logical Operators */
bool operator==(const Complex& a, const Complex& b)
{
    return (a.getReal() == b.getReal() && a.getImaginary() == b.getImaginary());
}

bool operator!=(const Complex& a, const Complex& b)
{
    return (!(a == b));
}

/* Arithmethic Operators */
Complex operator+(Complex a, const Complex& b)
{
    return a += b;
}

Complex operator-(Complex a, const Complex& b)
{
    return a -= b;
}

Complex operator*(Complex a, const Complex& b)
{
    return a *= b;
}

Complex operator/(Complex a, const Complex& b)
{
    return a /= b;
}

} /* end namespace pt1 */