#include "integration.h"
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

double gaussLegendre(function<double(double)> func, double a, double b, int n) {
    vector<double> x, w;

    if (n == 2) {
        x = { -1.0 / sqrt(3), 1.0 / sqrt(3) };
        w = { 1.0, 1.0 };
    }
    else if (n == 3) {
        x = { -sqrt(3.0 / 5.0), 0.0, sqrt(3.0 / 5.0) };
        w = { 5.0 / 9.0, 8.0 / 9.0, 5.0 / 9.0 };
    }
    else if (n == 4) {
        x = {
            -sqrt((3.0 + 2.0 * sqrt(6.0 / 5.0)) / 7.0),
            -sqrt((3.0 - 2.0 * sqrt(6.0 / 5.0)) / 7.0),
             sqrt((3.0 - 2.0 * sqrt(6.0 / 5.0)) / 7.0),
             sqrt((3.0 + 2.0 * sqrt(6.0 / 5.0)) / 7.0)
        };
        w = {
            (18.0 - sqrt(30.0)) / 36.0,
            (18.0 + sqrt(30.0)) / 36.0,
            (18.0 + sqrt(30.0)) / 36.0,
            (18.0 - sqrt(30.0)) / 36.0
        };
    }
    else {
        cerr << "Nieobslugiwany stopien n (tylko 2, 3, 4)." << endl;
        return 0.0;
    }

    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        double xi = ((b - a) / 2.0) * x[i] + ((b + a) / 2.0);
        sum += w[i] * func(xi);
    }

    return ((b - a) / 2.0) * sum;
}
