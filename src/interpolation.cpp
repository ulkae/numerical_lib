#include "interpolation.h"
//Oblicza wspolczynniki interpolacji Newtona
vector<double> computeNewtonCoefficients(const vector<double>& x, const vector<double>& y) {
    int n = x.size();
    vector<double> coefficients = y;

    for (int j = 1; j < n; j++) {
        for (int i = n - 1; i >= j; i--) {
            coefficients[i] = (coefficients[i] - coefficients[i - 1]) / (x[i] - x[i - j]);
        }
    }

    return coefficients;

}
//Oblicza wartosc interpolacji w zadanym punkcie uzywajac schematu Hornera
double newtonInterpolation(double x_val, const vector<double>& x, const vector<double>& coefficients) {
    double result = coefficients.back();
    for (int i = coefficients.size() - 2; i >= 0; i--) {
        result = result * (x_val - x[i]) + coefficients[i];
    }
    return result;
}
