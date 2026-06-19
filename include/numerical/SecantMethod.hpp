#ifndef SECANT_METHOD_HPP
#define SECANT_METHOD_HPP

#include <functional>

class SecantMethod {
public:
    // Solve f(x) = 0 using the secant method (no derivative needed)
    static double solve(const std::function<double(double)>& f,
                        double x0,
                        double x1,
                        double tol = 1e-10,
                        int maxIter = 1000);
};

#endif