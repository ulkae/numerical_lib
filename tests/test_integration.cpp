#include "integration.h"
#include <cassert>
#include <cmath>
#include <iostream>
using namespace std;

void testPositiveCase() {
    cout << "Test pozytywny - calkowanie x^2..." << endl;
    auto f = [](double x) { return x * x; }; // calka z x^2 od 0 do 1 = 1/3
    double result = gaussLegendre(f, 0.0, 1.0, 3);
    assert(abs(result - 1.0 / 3.0) < 1e-6); //wynik powinien byc blisko 1/3
    cout << "Test pozytywny przeszedl! Wynik: " << result << endl;
}

void testNegativeCase() {
    cout << "Test negatywny - nieprawidlowy rzad kwadratury..." << endl;
    auto f = [](double x) { return x; };
    
    //proba uzycia nieobslugiwanego rzedu n=5 (implementacja obsluguje tylko n=2,3,4)
    try {
        double result = gaussLegendre(f, 0.0, 1.0, 5);
        cout << "BLAD: Powinien wystapic blad dla n=5!" << endl;
    } catch (const exception& e) {
        cout << "Poprawnie wykryto blad: " << e.what() << endl;
    } catch (...) {
        cout << "Poprawnie wykryto blad dla nieprawidlowego rzedu" << endl;
    }
}

int main() {
    testPositiveCase();
    testNegativeCase();
    cout << "Wszystkie testy calkowania zakonczone!" << endl;
    return 0;
}
