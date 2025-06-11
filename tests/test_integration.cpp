#include "integration.h"
#include <cassert>
#include <cmath>
#include <iostream>

using namespace std;

int main() {
    auto f = [](double x) { return x * x; }; // ca³ka z x^2 od 0 do 1 = 1/3
    double result = gaussLegendre(f, 0.0, 1.0, 3);

    assert(abs(result - 1.0 / 3.0) < 1e-6);
    cout << "Test przeszedl pomyslnie. Wynik: " << result << endl;

    return 0;
}
