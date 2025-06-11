#pragma once
#include <vector>
using namespace std;

vector<double> rungeKutta4(double (*f)(double, double), double y0, double t0, double t_end, int steps);