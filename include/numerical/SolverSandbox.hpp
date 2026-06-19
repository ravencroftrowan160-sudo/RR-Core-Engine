#ifndef SOLVER_SANDBOX_HPP
#define SOLVER_SANDBOX_HPP

#include <functional>
#include "Deque.hpp"

struct IterationData{
    int iteration;
    double x;
    double fx;
};

class SolverSandbox{
public:
    SolverSandbox(const std::function<double(double)>& f, const std::function<double(double)>& df=nullptr);

    double runNewton(double x0, double tol = 1e-10, int maxIter = 1000);
    double runSecant(double x0, double x1, double tol = 1e-10, int maxIter = 1000);
    double runBisection(double a, double b, double tol = 1e-10, int maxIter = 1000);

    void printReport(const std::string& methodName) const;

private:
    std::function<double(double)> f;
    std::function<double(double)> df;

    Deque<IterationData> iterations;

    void record(int iter, double x);
};

#endif