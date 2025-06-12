#include "nonlinear_solver.h"
#include <cassert>
#include <cmath>
#include <iostream>
using namespace std;

double f_good(double x) { return x * x - 2; }
double df_good(double x) { return 2 * x; }

double f_bad(double x) { return x * x - 1; }
double df_bad(double x) { return 0.001; } // Bardzo mala pochodna zamiast zera

void testPositiveCase() {
    cout << "Test pozytywny - pierwiastek z 2..." << endl;
    double wynik = newtonAnalytical(f_good, df_good, 1.0);
    assert(!isnan(wynik));
    assert(abs(wynik - sqrt(2)) < 1e-6);
    cout << "Test pozytywny przeszedl! Pierwiastek = " << wynik << endl;
}

void testNegativeCase() {
    cout << "Test negatywny - bardzo mala pochodna..." << endl;
    double wynik = newtonAnalytical(f_bad, df_bad, 0.5, 1e-8, 5); // Malo iteracji

    if (isnan(wynik)) {
        cout << "Algorytm nie osiagnal zbieznosci" << endl;
    }
    else {
        cout << "Wynik po 5 iteracjach: " << wynik << endl;
        cout << "Wartosc funkcji: " << f_bad(wynik) << endl;
        if (abs(f_bad(wynik)) > 1e-3) {
            cout << "UWAGA: Slaba zbieznosc - nie osiagnieto dokladnosci!" << endl;
        }
    }
}

int main() {
    testPositiveCase();
    testNegativeCase();
    cout << "Wszystkie testy rownan nieliniowych zakonczone!" << endl;
    return 0;
}
