#include "approximation.h"
#include <cassert>
#include <cmath>
#include <iostream>

using namespace std;

int main() {
    vector<double> x = { 0, 1, 2 };
    vector<double> y = { 1, 3, 7 }; // y = 1 + x + x^2

    vector<double> coeffs = computeLeastSquares(x, y, 2);

    assert(abs(coeffs[0] - 1.0) < 1e-6);
    assert(abs(coeffs[1] - 1.0) < 1e-6);
    assert(abs(coeffs[2] - 1.0) < 1e-6);

    double val = evaluatePolynomial(3, coeffs);
    assert(abs(val - 13.0) < 1e-6);

    cout << "Test przeszedl pomyslnie. f(3) = " << val << endl;

    return 0;
}
