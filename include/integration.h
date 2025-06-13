#pragma once
      #include <functional>
      using namespace std;

//obliczanie całki funkcji na przedziale [a,b] metodą Gaussa-Legendre'a
      double gaussLegendre(function<double(double)> f, double a, double b, int n);
