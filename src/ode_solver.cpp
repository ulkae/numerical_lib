#include "ode_solver.h"
//rozwiazuje rownanie rozniczkowe y'(t) = f(t,y) metoda Runge-Kutta 4. rzedu
vector<double> rungeKutta4(double (*f)(double, double), double y0, double t0, double t_end, int steps) {
    vector<double> result;
    double h = (t_end - t0) / steps;
    double y = y0;
    double t = t0;

    for (int i = 0; i <= steps; ++i) {
        result.push_back(y);
//obliczanie wspolczynnikow k1, k2, k3, k4 metody RK4
        double k1 = h * f(t, y);
        double k2 = h * f(t + h / 2, y + k1 / 2);
        double k3 = h * f(t + h / 2, y + k2 / 2);
        double k4 = h * f(t + h, y + k3);

        y += (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;
        t += h;
    }

    return result;
}
