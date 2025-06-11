#include "approximation.h"
#include <iostream>
using namespace std;

int main() {
    vector<double> x = { 0, 1, 2, 3, 4 };
    vector<double> y = { 1, 2.1, 4.5, 7.8, 11.0 };

    auto coeffs = computeLeastSquares(x, y, 2);

    cout << "Aproksymacja LSQ (stopień 2):" << endl;
    for (size_t i = 0; i < coeffs.size(); ++i)
        cout << "a" << i << " = " << coeffs[i] << endl;

    double test_x = 2.5;
    double wynik = evaluatePolynomial(test_x, coeffs);
    cout << "f(" << test_x << ") ≈ " << wynik << endl;

    return 0;
}
