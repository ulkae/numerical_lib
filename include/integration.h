#pragma once
      #include <functional>
      using namespace std;
   
      double gaussLegendre(function<double(double)> f, double a, double b, int n);