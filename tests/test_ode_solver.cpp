#include "ode_solver.h"
#include <cassert>
#include <cmath>
#include <iostream>
using namespace std;

double f_good(double t, double y) {
    return -2 * y + 1;  // y' = -2y + 1
}

void testPositiveCase() {
    cout << "Test pozytywny - ODE y' = -2y + 1..." << endl;
    double y0 = 0.0;
    double t0 = 0.0;
    double t_end = 0.5;
    int steps = 10;
    vector<double> wyniki = rungeKutta4(f_good, y0, t0, t_end, steps);

    double y_oczekiwane = 0.5 * (1 - exp(-1.0)); // Rozwiazanie analityczne
    double y_liczone = wyniki.back();
    assert(abs(y_liczone - y_oczekiwane) < 1e-3);
    cout << "Test pozytywny przeszedl! y(0.5) = " << y_liczone << endl;
}

void testNegativeCase() {
    cout << "Test negatywny - bardzo malo krokow..." << endl;
    double y0 = 1.0;
    double t0 = 0.0;
    double t_end = 10.0;  // Duzy przedzial
    int steps = 1;        // Bardzo malo krokow

    try {
        vector<double> wyniki = rungeKutta4(f_good, y0, t0, t_end, steps);
        cout << "Algorytm zakonczony, ale wynik moze byc niedokladny" << endl;
        cout << "Rozmiar wyniku: " << wyniki.size() << endl;
        cout << "Koncowa wartosc: " << wyniki.back() << endl;

        // Sprawdz czy wynik jest rozumny
        if (abs(wyniki.back()) > 1e10) {
            cout << "UWAGA: Wynik bardzo duzy - moze byc niestabilny!" << endl;
        }

    }
    catch (const exception& e) {
        cout << "Poprawnie wykryto blad: " << e.what() << endl;
    }
    catch (...) {
        cout << "Wykryto blad w algorytmie ODE" << endl;
    }
}

int main() {
    testPositiveCase();
    testNegativeCase();
    cout << "Wszystkie testy rownan rozniczkowych zakonczone!" << endl;
    return 0;
}
