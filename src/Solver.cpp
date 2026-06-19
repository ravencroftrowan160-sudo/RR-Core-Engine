#include "Solver.hpp"
#include "NewtonMethod.hpp"
#include "BisectionMethod.hpp"
#include "SecantMethod.hpp"

double Solver::rootNewton(const std::function<double(double)>& f,
                          const std::function<double(double)>& df,
                          double x0,
                          double tol,
                          int maxIter)
{
    return NewtonMethod::solve(f, df, x0, tol, maxIter);
}

double Solver::rootBisection(const std::function<double(double)>& f,
                             double a,
                             double b,
                             double tol,
                             int maxIter)
{
    return BisectionMethod::solve(f, a, b, tol, maxIter);
}

double Solver::rootSecant(const std::function<double(double)>& f,
                          double x0,
                          double x1,
                          double tol,
                          int maxIter)
{
    return SecantMethod::solve(f, x0, x1, tol, maxIter);