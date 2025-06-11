#include "ode_solver.h"
#include <cassert>
#include <cmath>
#include <iostream>

using namespace std;

double f(double t, double y) {
    return -2 * y + 1;
}

int main() {
    double y0 = 0.0;
    double t0 = 0.0;
    double t_end = 0.5;
    int steps = 10;

    vector<double> wyniki = rungeKutta4(f, y0, t0, t_end, steps);

    double y_oczekiwane = 0.5 * (1 - exp(-1.0)); // y(0.5)
    double y_liczone = wyniki.back();

    assert(abs(y_liczone - y_oczekiwane) < 1e-3);
    cout << "Test RK4 przeszedl. y(0.5) = " << y_liczone << endl;

    return 0;
}
