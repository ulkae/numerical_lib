#include "interpolation.h"
#include <iostream>
using namespace std;
//przewidywanie wartosci pomiedzy pomiarami
//program interpoluje 4 punkty i oblicza wartosc w x=5
int main() {
    vector<double> x = { 1, 2, 4, 7 };
    vector<double> y = { 3, 6, 12, 24 };

    auto coeffs = computeNewtonCoefficients(x, y);
    double wynik = newtonInterpolation(5, x, coeffs);

    cout << "Interpolacja Newtona w x=5: " << wynik << endl;
    return 0;
}
