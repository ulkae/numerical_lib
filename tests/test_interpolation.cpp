#include "interpolation.h"
#include <cassert>
#include <cmath>
#include <iostream>
using namespace std;

void testPositiveCase() {
    cout << "Test pozytywny - interpolacja liniowa..." << endl;

    //punkty lezace na prostej y = x + 1: (0,1), (1,2), (2,3)
    vector<double> x = { 0, 1, 2 };
    vector<double> y = { 1, 2, 3 };
    vector<double> coeffs = computeNewtonCoefficients(x, y);

    //test interpolacji w punkcie x=1.5 (oczekiwana wartosc y=2.5)
    double result = newtonInterpolation(1.5, x, coeffs);
    double expected = 2.5;
    assert(abs(result - expected) < 1e-6);
    cout << "Test pozytywny przeszedl! Wynik = " << result << endl;
}

void testNegativeCase() {
    cout << "Test negatywny - identyczne wartosci x..." << endl;
    //dane z powtorzona wspolrzedna x=1 (powoduje dzielenie przez zero w dzielonych roznicach)
    vector<double> x = { 1, 1, 2 };  
    vector<double> y = { 3, 5, 7 };

    try {
        vector<double> coeffs = computeNewtonCoefficients(x, y);
        double result = newtonInterpolation(1.5, x, coeffs);
        cout << "UWAGA: Algorytm nie wykryl identycznych wartosci x, wynik: " << result << endl;
    }
    catch (const exception& e) {
        cout << "Poprawnie wykryto blad: " << e.what() << endl;
    }
    catch (...) {
        cout << "Poprawnie wykryto blad dla identycznych wartosci x" << endl;
    }
}

int main() {
    testPositiveCase();
    testNegativeCase();
    cout << "Wszystkie testy interpolacji zakonczone!" << endl;
    return 0;
}
