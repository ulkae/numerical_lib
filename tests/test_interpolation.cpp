#include "interpolation.h"
#include <cassert>
#include <cmath>
#include <iostream>

using namespace std;

int main() {
    vector<double> x = { 0, 1, 2 };
    vector<double> y = { 1, 2, 3 };
    vector<double> coeffs = computeNewtonCoefficients(x, y);

    double result = newtonInterpolation(1.5, x, coeffs);
    double expected = 2.5;

    assert(abs(result - expected) < 1e-6);
    cout << "Test przeszedl pomyslnie. Wynik = " << result << endl;

    return 0;
}
