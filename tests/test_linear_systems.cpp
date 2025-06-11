#include "linear_systems.h"
#include <cassert>
#include <cmath>
#include <iostream>

using namespace std;

int main() {
    vector<vector<double>> A = {
        {2, 1},
        {8, 7}
    };
    vector<double> b = { 3, 23 };

    vector<vector<double>> L, U;
    luDecomposition(A, L, U);
    vector<double> z = forwardSubstitution(L, b);
    vector<double> x = backSubstitution(U, z);

    assert(abs(x[0] - 1) < 1e-6);
    assert(abs(x[1] - 1) < 1e-6);
    cout << "Test przeszedl pomyslnie. x = [1, 1]" << endl;

    return 0;
}
