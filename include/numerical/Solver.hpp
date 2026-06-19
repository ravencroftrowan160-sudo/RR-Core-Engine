#ifndef SOLVER_HPP
#define SOLVER_HPP

#include <functional>

enum class RootMethod {
    Newton,
    Bisection,
    Secant
};

class Solver {
public:
    // Newton: needs f and f'
    static double rootNewton(const std::function<double(double)>& f,
                             const std::function<double(double)>& df,
                             double x0,
                             double tol = 1e-10,
                             int maxIter = 1000);

    // Bisection: needs bracket [a, b]
    static double rootBisection(const std::function<double(double)>& f,
                                double a,
                                double b,
                                double tol = 1e-10,
                                int maxIter = 1000);

    // Secant: needs two starting guesses
    static double rootSecant(const std::function<double(double)>& f,
                             double x0,
                             double x1,
                             double tol = 1e-10,
                             int maxIter = 1000);
};

#endif