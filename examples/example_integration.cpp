#include "integration.h"
#include <iostream>
#include <cmath>
#ifndef M_PI
#define M_PI 3.141592653589793
#endif
using namespace std;

//obliczanie calki funkcji cos(x^2), Program oblicza pole pod krzywa od 0 do 1 metoda Gaussa-Legendre'a
double f(double x) {
    return cos(x * x);
}

int main() {
    double wynik = gaussLegendre(f, 0.0, 1.0, 4);
    cout << "Całka ∫cos(x^2) dx od 0 do 1 (Gauss, n=4): " << wynik << endl;
    return 0;
}
