/* ==============================================================
 * Programming Techniques for Scientific Simulations I  
 * Header file defining complex numbers
 * 
 * VERSION 1.00 (C) Copyright Free to use
 * ==============================================================*/

#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <fstream>
#include <cmath>

// namespace pt1 Library
namespace pt1{

class Complex{

private:
    double real_;       /* real part of the complex number */
    double imaginary_;  /* imaginary part of the complex number */

public:
    Complex();                              /* default ctor*/
    ~Complex();                             /* destructor */
    Complex( const Complex& );              /* copy constructor */
    Complex( const double, const double);   /* init constructor */

    const Complex& operator=(const Complex& );  /* assignment operator */

    double getReal() const;         /* getter for real part */
    double getImaginary() const;    /* getter for imaginary part */

    void setReal( const double );
    void setImaginary( const double );

    double norm() const;    /* get the length of the complex number */

}; /* end class Complex */

/* Assignment operators */
Complex& operator+=( Complex&, const Complex& ); 
Complex& operator-=( Complex&, const Complex& );   
Complex& operator*=( Complex&, const Complex& );  
Complex& operator/=( Complex&, const Complex& );

/* Input output operators */
std::ostream& operator<<( std::ostream&, const Complex& );
std::istream& operator>>( std::istream&, Complex& );

/* Logical Operators */
bool operator==( const Complex&, const Complex& );
bool operator!=( const Complex&, const Complex& );

/* Arithmethic Operators */
Complex operator+( Complex, const Complex& ); 
Complex operator-( Complex, const Complex& );   
Complex operator*( Complex, const Complex& );  
Complex operator/( Complex, const Complex& );

} /* end namespace pt1 */

#endif /* COMPLEX_HPP */