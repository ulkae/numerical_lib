#include "linear_systems.h"
#include <cassert>
#include <cmath>
#include <iostream>
using namespace std;

void testPositiveCase() {
    cout << "Test pozytywny - uklad 2x2..." << endl;
    vector<vector<double>> A = { {2, 1}, {8, 7} };
    vector<double> b = { 3, 23 };
    vector<vector<double>> L, U;
    luDecomposition(A, L, U);
    vector<double> z = forwardSubstitution(L, b);
    vector<double> x = backSubstitution(U, z);

    // Poprawione asercje z poprawnymi wartoœciami rozwi¹zania
    assert(abs(x[0] + 1.0 / 3.0) < 1e-6);
    assert(abs(x[1] - 11.0 / 3.0) < 1e-6);

    cout << "Test pozytywny przeszedl! x = [-1/3, 11/3]" << endl;
}

void testNegativeCase() {
    cout << "Test negatywny - sprawdzenie stabilnosci..." << endl;

    vector<vector<double>> A = { {3, 2}, {1, 4} };
    vector<double> b = { 7, 9 };

    try {
        vector<vector<double>> L, U;
        luDecomposition(A, L, U);

        bool dekompozycja_ok = true;

        for (int i = 0; i < L.size(); i++) {
            if (abs(L[i][i] - 1.0) > 1e-10) {
                dekompozycja_ok = false;
                break;
            }
        }

        for (int i = 0; i < U.size(); i++) {
            if (abs(U[i][i]) < 1e-12) {
                dekompozycja_ok = false;
                break;
            }
        }

        if (!dekompozycja_ok) {
            cout << "UWAGA: Dekompozycja LU ma nieprawidlowa strukture!" << endl;
        }
        else {
            cout << "Dekompozycja LU poprawna" << endl;

            vector<double> z = forwardSubstitution(L, b);
            vector<double> x = backSubstitution(U, z);

            cout << "Rozwiazanie: x[0] = " << x[0] << ", x[1] = " << x[1] << endl;

            double blad1 = abs(A[0][0] * x[0] + A[0][1] * x[1] - b[0]);
            double blad2 = abs(A[1][0] * x[0] + A[1][1] * x[1] - b[1]);

            cout << "Bledy: " << blad1 << ", " << blad2 << endl;
            if (blad1 > 1e-10 || blad2 > 1e-10) {
                cout << "UWAGA: Duze bledy w rozwiazaniu!" << endl;
            }
        }

    }
    catch (const exception& e) {
        cout << "Wykryto wyjatek: " << e.what() << endl;
    }
    catch (...) {
        cout << "Wykryto nieznany problem" << endl;
    }
}

int main() {
    testPositiveCase();
    testNegativeCase();
    cout << "Wszystkie testy ukladow liniowych zakonczone!" << endl;
    return 0;
}
