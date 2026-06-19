#include <iostream>
#include "numerical/SolverSandbox.hpp"

double f(double x) {
    return x*x - 2;   // root at sqrt(2)
}

double df(double x) {
    return 2*x;
}

int main() {
    SolverSandbox solver(f, df);

    double root = solver.runNewton(1.0);  // start at x0 = 1

    std::cout << "Approx root: " << root << "\n";

    return 0;
}