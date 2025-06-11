#include "approximation.h"
#include <cmath>

vector<double> computeLeastSquares(const vector<double>& x, const vector<double>& y, int degree) {
    int n = x.size();
    int m = degree + 1;
    vector<vector<double>> A(m, vector<double>(m, 0.0));
    vector<double> B(m, 0.0);
    vector<double> coeffs(m, 0.0);

    // Macierz A (iloczyny potêg x)
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < n; ++k)
                A[i][j] += pow(x[k], i + j);
        }
    }

    // Wektor B (iloczyny f(x)*x^i)
    for (int i = 0; i < m; ++i) {
        for (int k = 0; k < n; ++k)
            B[i] += y[k] * pow(x[k], i);
    }

    // Rozwi¹zywanie uk³adu równañ A * coeffs = B (eliminacja Gaussa)
    for (int i = 0; i < m; ++i) {
        // Maksymalny element w kolumnie
        int maxRow = i;
        for (int k = i + 1; k < m; ++k) {
            if (fabs(A[k][i]) > fabs(A[maxRow][i]))
                maxRow = k;
        }
        swap(A[i], A[maxRow]);
        swap(B[i], B[maxRow]);

        for (int k = i + 1; k < m; ++k) {
            double factor = A[k][i] / A[i][i];
            for (int j = i; j < m; ++j)
                A[k][j] -= factor * A[i][j];
            B[k] -= factor * B[i];
        }
    }

    for (int i = m - 1; i >= 0; --i) {
        coeffs[i] = B[i];
        for (int j = i + 1; j < m; ++j)
            coeffs[i] -= A[i][j] * coeffs[j];
        coeffs[i] /= A[i][i];
    }

    return coeffs;
}

double evaluatePolynomial(double x, const vector<double>& coeffs) {
    double result = 0.0;
    double xi = 1.0;
    for (double c : coeffs) {
        result += c * xi;
        xi *= x;
    }
    return result;
}
