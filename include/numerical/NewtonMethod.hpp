#ifndef NEWTON_METHOD_HPP
#define NEWTON_METHOD_HPP

#include <functional>

class NewtonMethod {
public:
    // Solve f(x) = 0 using Newton's Method
    static double solve(const std::function<double(double)>& f,
                        const std::function<double(double)>& df,
                        double x0,
                        double tol = 1e-10,
                        int maxIter = 1000);
};

#endif