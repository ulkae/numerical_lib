#pragma once
#include <vector>
using namespace std;

//rozwiązuje równanie y'(t) = f(t,y) metodą Runge-Kutta 4. rzędu
vector<double> rungeKutta4(double (*f)(double, double), double y0, double t0, double t_end, int steps);
