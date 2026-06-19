#include "BisectionMethod.hpp"
#include <stdexcept>
#include <cmath>

double BisectionMethod::solve(const std::function<double(double)>& f,
                              double a,
                              double b,
                              double tol,
                              int maxIter)
{
    double fa = f(a);
    double fb = f(b);

    if (fa * fb > 0.0) {
        throw std::runtime_error("BisectionMethod: f(a) and f(b) must have opposite signs.");
    }

    double left = a;
    double right = b;
    double mid = 0.0;

    for (int i = 0; i < maxIter; ++i) {
        mid = 0.5 * (left + right);
        double fm = f(mid);

        if (std::abs(fm) < tol || 0.5 * (right - left) < tol) {
            return mid;
        }

        if (fa * fm < 0.0) {
            right = mid;
            fb = fm;
        } else {
            left = mid;
            fa = fm;
        }
    }

    throw std::runtime_error("BisectionMethod: did not converge.");
}