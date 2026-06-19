#include "SecantMethod.hpp"
#include <stdexcept>
#include <cmath>

double SecantMethod::solve(const std::function<double(double)>& f,
                           double x0,
                           double x1,
                           double tol,
                           int maxIter)
{
    double f0 = f(x0);
    double f1 = f(x1);

    for (int i = 0; i < maxIter; ++i) {
        double denom = (f1 - f0);
        if (std::abs(denom) < 1e-14) {
            throw std::runtime_error("SecantMethod: denominator too small.");
        }

        double x2 = x1 - f1 * (x1 - x0) / denom;
        if (std::abs(x2 - x1) < tol) {
            return x2;
        }

        x0 = x1;
        f0 = f1;
        x1 = x2;
        f1 = f(x1);
    }

    throw std::runtime_error("SecantMethod: did not converge.");
}