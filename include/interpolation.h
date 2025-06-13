#pragma once
   #include <vector>
      using namespace std;

   //obliczanie współczynników interpolacji Newtona
      vector<double> computeNewtonCoefficients(const vector<double>& x, const vector<double>& y);
  //obliczanie interpolowanej wartości w punkcie x_val
      double newtonInterpolation(double x_val, const vector<double>& x, const vector<double>& coefficients);
