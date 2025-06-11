#include "linear_systems.h"
#include <iostream>
using namespace std;

int main() {
    vector<vector<double>> A = {
        {2, 1, -1},
        {-3, -1, 2},
        {-2, 1, 2}
    };
    vector<double> b = { 8, -11, -3 };

    vector<vector<double>> L, U;
    luDecomposition(A, L, U);

    auto z = forwardSubstitution(L, b);
    auto x = backSubstitution(U, z);

    cout << "Rozwi¹zanie uk³adu 3x3:" << endl;
    for (double val : x) cout << val << " ";
    cout << endl;

    return 0;
}
