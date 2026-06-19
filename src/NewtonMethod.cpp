#include "NewtonMethod.hpp"
#include <cmath>
#include <stdexcept>

double NewtonMethod::solve(const std::function<double(double)>& f,
                           const std::function<double(double)>& df,
                           double x0,
                           double tol,
                           int maxIter)
{
    double x = x0;

    for (int i = 0; i < maxIter; i++) {
        double fx = f(x);
        double dfx = df(x);

        if (std::abs(dfx) < 1e-14) {
            throw std::runtime_error("Derivative too small — Newton's Method fails.");
        }

        double xNext = x - fx / dfx;

        if (std::abs(xNext - x) < tol) {
            return xNext; // Converged
        }

        x = xNext;
    }

    throw std::runtime_error("Newton's Method did not converge.");
}