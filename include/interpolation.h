#pragma once
   #include <vector>
      using namespace std;
   
      vector<double> computeNewtonCoefficients(const vector<double>& x, const vector<double>& y);
      double newtonInterpolation(double x_val, const vector<double>& x, const vector<double>& coefficients);