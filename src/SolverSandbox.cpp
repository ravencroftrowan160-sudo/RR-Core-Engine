#include "numerical/SolverSandbox.hpp"
#include <iostream>
#include <cmath>

SolverSandbox::SolverSandbox(const std::function<double(double)>& f,
                             const std::function<double(double)>& df)
    : f(f), df(df) {}

// Store one iteration's data in your Deque
void SolverSandbox::record(int iter, double x) {
    IterationData data;
    data.iteration = iter;
    data.x = x;
    data.fx = f(x);

    iterations.addTail(data);
}

double SolverSandbox::runNewton(double x0, double tol, int maxIter) {
    iterations.clear();  // now valid since we added clear()

    double x = x0;

    for (int i = 0; i < maxIter; i++) {
        record(i, x);

        double fx = f(x);
        double dfx = df(x);

        if (std::abs(fx) < tol) {
            return x;   // converged
        }

        if (dfx == 0) {
            std::cerr << "Derivative zero — cannot continue Newton's Method\n";
            return x;   // return best guess
        }

        x = x - fx / dfx;
    }

    return x; // return last approximation
}