#include <iostream>

template <typename Func>
double calculate(const Func& f, const double x){
    return f(x);
};

template <typename Func>
double integrate(const Func& f, const double a, const double b, const unsigned int N)
{
    const unsigned int steps = 2*N + 1;
    const double dr = (b - a) / (steps - 1);
    double I = f(a);

    for(unsigned int i = 1; i < steps-1; ++i)
        I += 2 * (1.0 + i%2) * f(a + dr * i);

    I += f(b);
    return I * (1./3) * dr;
}

double g(double x){
    return x*x;
}

int main()
{
    auto f = [](const double x)->double{
        return x*x*x;
    };
    
    const double a = 5.;
    auto pointer = &g;
    std::cout << integrate(f, 0.,1.,10) << std::endl;
    std::cout << integrate(pointer, 0., 1., 10) << std::endl;
    return 0;
}