#include "nonlinear_solver.h"
#include <cassert>
#include <cmath>
#include <iostream>

using namespace std;

double f(double x) {
    return x * x - 2;
}

double df(double x) {
    return 2 * x;
}

int main() {
    double wynik = newtonAnalytical(f, df, 1.0);

    assert(!isnan(wynik));
    assert(abs(wynik - sqrt(2)) < 1e-6);

    cout << "Test Newtona przeszedl. Wynik = " << wynik << endl;
    return 0;
}
