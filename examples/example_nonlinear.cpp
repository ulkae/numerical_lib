#include "nonlinear_solver.h"
#include <iostream>
#include <cmath>
using namespace std;

double f(double x) { return x * x * x - x - 2; }
double df(double x) { return 3 * x * x - 1; }

int main() {
    double root = newtonAnalytical(f, df, 1.5);
    cout << "Pierwiastek rownania x^3 - x - 2 = 0: " << root << endl;
    return 0;
}
