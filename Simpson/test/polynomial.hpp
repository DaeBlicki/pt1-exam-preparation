/* ==============================================================
 * Programming Techniques for Scientific Simulations I  
 * Header file defining the polynomials integrations
 * 
 * VERSION 1.00 (C) Copyright Free to use
 * ==============================================================*/

/* ======================================================
 * DEFINITIONS OF INTEGRATION FUNCTION FOR POLYNOMIALS  
 * ======================================================*/

/*
 * constant() - calculate the integral of constant function from (x1, x2)
 * PRE: -
 * POST: return integral of f(x) = a from (x1, x2)
 */
double integrateConstant(const double a, 
                const double x1, const double x2);

/*
 * linear() - calculate the integral of linear function from (x1, x2)
 * PRE: x1 <= x2: f(x) = ax + b
 * POST: return integral of f(x) = ax + b from (x1, x2)
 */
double integrateLinear(const double a, const double b,
                const double x1, const double x2);

/*
 * quadratic() - calculate the integral of quadratic function from (x1, x2)
 * PRE: -
 * POST: return integral of f(x) = ax^2 + bx + c from (x1, x2)
 */
double integrateQuadratic(const double a, const double b, const double c,
                const double x1, const double x2);

/*
 * quadratic() - calculate the integral of cubic function from (x1, x2)
 * PRE: -
 * POST: return integral of f(x) = ax^2 + bx + c from (x1, x2)
 */
double integrateCubic(const double a, const double b, const double c, const double d,
                const double x1, const double x2);

/* =================================================================================
 * DEFINITIONS OF POLYNOMIAL CLASSES USING INHERITANCE AND RUNTIME POLYMORPHISM
 * =================================================================================*/

using parameter_t = double;

// Abstract base function class
struct Polynomial{
    virtual ~Polynomial() = default;   /* destructor */
    virtual double operator()( const double ) const = 0;
};

// Constant function based on base function class
struct Constant : public Polynomial{
    Constant(const parameter_t a) : a_(a){}
    double operator()(const double x) const {
        return a_;
    }
    private:
    const parameter_t a_;  // f(x) = a
};

// Linear function based on base function class
struct Linear : public Polynomial{
    Linear(const parameter_t a, const parameter_t b) : a_(a), b_(b){}
    double operator()(const double x) const {
        return a_*x + b_;
    }
    private:
    const parameter_t a_, b_;  // f(x) = a*x + b
};

// Quadratic function based on base function class
struct Quadratic : public Polynomial{
    Quadratic(const parameter_t a, const parameter_t b, const parameter_t c) 
            : a_(a), b_(b), c_(c) {}
    double operator()(const double x) const {
        return a_*x*x + b_*x + c_;
    }
    private:
    const parameter_t a_, b_, c_;  // f(x) = a*x*x + b*x + c
};

// Quadratic function based on base function class
struct Cubic : public Polynomial{
    Cubic(const parameter_t a, const parameter_t b, const parameter_t c, const parameter_t d) 
            : a_(a), b_(b), c_(c), d_(d){}
    double operator()(const double x) const {
        return a_*x*x*x + b_*x*x + c_*x + d_;
    }
    private:
    const parameter_t a_, b_, c_, d_;  // f(x) = a*x*x*x + b*x*x + c*x + d
};

/* ===================================================
 * DEFINITIONS OF FUNCTION TO CALCULATE POLYNOMIALS 
 * ===================================================*/

/*
 * constant() - calculate the value of constant function at point x
 * PRE: a != 0
 * POST: return f(x) = a
 */
double constant(const double x, const double a);

/*
 * linear() - calculate the value of linear function at point x
 * PRE: a != 0
 * POST: return f(x) = ax + b
 */
double linear(const double x, const double a, const double b);

/*
 * quadratic() - calculate the value of quadratic function at point x
 * PRE: a != 0
 * POST: return f(x) = ax*x + b*x + c
 */
double quadratic(const double x, const double a, const double b, const double c);

/*
 * cubic() - calculate the value of quadratic function at point x
 * PRE: a != 0
 * POST: return f(x) = ax*x*x + b*x*x + c*x + d
 */
double cubic(const double x, const double a, const double b, const double c, const double d);