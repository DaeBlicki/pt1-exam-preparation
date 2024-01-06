# Library for Programming Techniques for Scientific Simulations I

Library containing useful class implementation and tests used in pt1 lecture.

## Content
1) Complex number class
2) Random number generator class
3) Time measurement class

## How to get started

### Requirement
- Ubuntu 22.04+
- CMake version 3.22+
- GNU 11.4.0

## Complex number
Comlex numbers can be representated as a 2-dimensional vector in the Real and Imaginary plane.

```
pt1::Complex a(2.0, -3.0);
pt1::Complex b(6.0, 0.0);
pt1::Complex c = b - a;
std::cout << a << " " << b " " << c << "\n";
std::cout << a.norm() << " " << b.norm() " " << c.norm() << "\n";
```

## Random number generator
Random number generator based on modular arithmetic.

```
pt1::Random_Number_Generator::seed(42);
unsigned int random1 = pt1::Random_Number_Generator::generate();
unsigned int random2 = pt1::Random_Number_Generator::generate() % 100;
```

## Timer
Timer class to measure the code speed. The guaranteed precision is 20 microseconds!

```
pt1::Timer t;
// measuring the code of method summing from 0 to 100
unsigned int sum = 0;
t.start();
for(unsigned int i = 0; i <= 100; i++){
    sum += i;
}
t.stop();
std::cout << t.duration() << "\n";

// reset the timer
t.reset();

// measuring the average time for summing from 0 to 100
for(unsigned int j = 0; j < 10; j++){
    sum = 0;
    t.start();
    for(unsigned int i = 0; i <= 100; i++){
        sum += i;
    }
    t.stop();
}
std::cout << t.mean() << "\n";
```
