#include "nonlinear_solver.h"
#include <cmath>
#include <iostream>

using namespace std;

double newtonAnalytical(function<double(double)> f, function<double(double)> df, double x0, double epsilon, int max_iter) {
    double x = x0;

    for (int i = 0; i < max_iter; ++i) {
        double fx = f(x);
        double dfx = df(x);

        if (abs(dfx) < 1e-14) {
            cerr << "Pochodna bliska zeru. Przerwanie." << endl;
            return NAN;
        }

        double x_new = x - fx / dfx;

        if (abs(x_new - x) < epsilon)
            return x_new;

        x = x_new;
    }

    cerr << "Nie osiagnieto zbieznosci." << endl;
    return NAN;
}
