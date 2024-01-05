/* 
 *Programming Techniques for Scientific Simulations I 
 * .cpp file for Complex number class implementation
 * Author: David Blickenstorfer
 * Created: 05/01/2024
 */

#include "complex.hpp"
#include <stdexcept>

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

bool operator>=(const Complex& a, const Complex& b)
{
    return (a.norm() >= b.norm());
}   

bool operator<=(const Complex& a, const Complex& b)
{
    return (a.norm() <= b.norm());
}

bool operator>( const Complex& a, const Complex& b)
{
    return (a.norm() > b.norm());
}

bool operator<( const Complex& a, const Complex& b)
{
    return (a.norm() < b.norm());
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

