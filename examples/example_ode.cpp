#include "ode_solver.h"
#include <iostream>
using namespace std;

//rozwiazywanie rownania rozniczkowego y'=y-t^2+1
double dydt(double t, double y) {
    return y - t * t + 1;  // y' = y - t^2 + 1
}

int main() {
    auto wynik = rungeKutta4(dydt, 0.5, 0.0, 2.0, 10);
    cout << "Rozwiazanie ODE (RK4) od t=0 do t=2:" << endl;
    for (size_t i = 0; i < wynik.size(); ++i)
        cout << "y[" << i << "] = " << wynik[i] << endl;

    return 0;
}
