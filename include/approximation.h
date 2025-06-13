#pragma once
    #include <vector>
     using namespace std;

   //obliczanie współczynników wielomianu
      vector<double> computeLeastSquares(const vector<double>& x, const vector<double>& y, int degree);
  //obliczanie wartości wielomianu w danym punkcie
      double evaluatePolynomial(double x, const vector<double>& coeffs);
