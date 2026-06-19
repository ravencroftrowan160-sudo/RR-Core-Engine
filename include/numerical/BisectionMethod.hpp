#ifndef BISECTION_METHOD_HPP
#define BISECTION_METHOD_HPP

#include <functional>

class BisectionMethod {
public:
    // Solve f(x) = 0 on [a, b] assuming f(a)*f(b) < 0
    static double solve(const std::function<double(double)>& f,
                        double a,
                        double b,
                        double tol = 1e-10,
                        int maxIter = 1000);
};

#endif