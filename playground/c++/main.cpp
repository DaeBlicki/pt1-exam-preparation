#include <iostream>

template <typename Func>
double integrate(const Func& , const double , const double , const unsigned int );

double function(double x){
    return x*x;
}

struct Function{
    ~Function() = default;
    Function(const double a) : a_(a){}
    inline double operator()(double const x) const{
        return x*x;
    }
    private:
    const double a_;
};

int main()
{
    auto lambda = [](const double x)->double{
        return x*x;
    };

    auto pointer = &function;

    Function fclass(1.);
    
    std::cout << integrate(lambda, 0.,1.,10) << std::endl;
    std::cout << integrate(pointer, 0., 1., 10) << std::endl;
    std::cout << integrate(function, 0., 1., 10) << std::endl;
    std::cout << integrate(fclass, 0., 1., 10) << std::endl;
    return 0;
}

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