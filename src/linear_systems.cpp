#include "linear_systems.h"
//Dekompozycja LU macierzy A na macierz dolna trojkatna L i gorna trojkatna U
void luDecomposition(const vector<vector<double>>& A, vector<vector<double>>& L, vector<vector<double>>& U) {
    int n = A.size();
    L.assign(n, vector<double>(n, 0));
    U.assign(n, vector<double>(n, 0));

    for (int k = 0; k < n; ++k) {
        //obliczanie elementow macierzy U w k-tym wierszu
        for (int j = k; j < n; ++j) {
            double sum = 0;
            for (int s = 0; s < k; ++s)
                sum += L[k][s] * U[s][j];
            U[k][j] = A[k][j] - sum;
        }
       //obliczanie elementow macierzy L w k-tej kolumnie
        for (int i = k; i < n; ++i) {
            if (i == k)
                L[i][k] = 1.0;
            else {
                double sum = 0;
                for (int s = 0; s < k; ++s)
                    sum += L[i][s] * U[s][k];
                L[i][k] = (A[i][k] - sum) / U[k][k];
            }
        }
    }
}

vector<double> forwardSubstitution(const vector<vector<double>>& L, const vector<double>& b) {
    int n = L.size();
    vector<double> z(n);
    //rozwiazywanie od pierwszego do ostatniego elementu
    for (int i = 0; i < n; ++i) {
        z[i] = b[i];
        //odejmowanie wczesniej obliczonych wartosci
        for (int j = 0; j < i; ++j)
            z[i] -= L[i][j] * z[j];
        z[i] /= L[i][i]; //dzielenie przez element przekatny
    }
    return z;
}

vector<double> backSubstitution(const vector<vector<double>>& U, const vector<double>& z) {
    int n = U.size();
    vector<double> x(n);
    for (int i = n - 1; i >= 0; --i) {
        x[i] = z[i];
        for (int j = i + 1; j < n; ++j)
            x[i] -= U[i][j] * x[j];
        x[i] /= U[i][i];
    }
    return x;
}
