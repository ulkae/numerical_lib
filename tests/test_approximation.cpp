#include "approximation.h"
#include <cassert>
#include <cmath>
#include <iostream>
using namespace std;

void testPositiveCase() {
    cout << "Test pozytywny - aproksymacja kwadratowa..." << endl;
    
    //dane testowe: punkty lezace dokladnie na paraboli y = 1 + x + x^2
    vector<double> x = { 0, 1, 2 };
    vector<double> y = { 1, 3, 7 }; // y = 1 + x + x^2
    vector<double> coeffs = computeLeastSquares(x, y, 2);
    
    //sprawdzenie czy otrzymane wspolczynniki sa poprawne
    assert(abs(coeffs[0] - 1.0) < 1e-6);
    assert(abs(coeffs[1] - 1.0) < 1e-6);
    assert(abs(coeffs[2] - 1.0) < 1e-6);

    //dla x=3 oczekujemy y = 1 + 3 + 9 = 13
    double val = evaluatePolynomial(3, coeffs);
    assert(abs(val - 13.0) < 1e-6);
    cout << "Test pozytywny przeszedl!" << endl;
}

void testNegativeCase() {
    cout << "Test negatywny - stopien wiekszy niz liczba punktow..." << endl;
    vector<double> x = { 1, 2 };      // Tylko 2 punkty
    vector<double> y = { 3, 4 };      // Tylko 2 punkty
    
//proba aproksymacji wielomianem stopnia 5 (wymaga 6 wspolczynnikow) dla 2 punktow
    try {
        vector<double> coeffs = computeLeastSquares(x, y, 5); // Stopien 5 dla 2 punktow!
        cout << "UWAGA: Algorytm nie wykryl problemu ze stopniem wielomianu" << endl;
        cout << "Otrzymano " << coeffs.size() << " wspolczynnikow" << endl;
    }
    catch (const exception& e) {
        cout << "Poprawnie wykryto blad: " << e.what() << endl;
    }
    catch (...) {
        cout << "Poprawnie wykryto blad dla nieprawidlowego stopnia" << endl;
    }
}

int main() {
    testPositiveCase();
    testNegativeCase();
    cout << "Wszystkie testy aproksymacji zakonczone!" << endl;
    return 0;
}
