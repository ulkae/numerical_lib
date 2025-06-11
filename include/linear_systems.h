#pragma once
  #include <vector>
 using namespace std;

 void luDecomposition(const vector<vector<double>>& A, vector<vector<double>>& L, vector<vector<double>>& U);
 vector<double> forwardSubstitution(const vector<vector<double>>& L, const vector<double>& b);
 vector<double> backSubstitution(const vector<vector<double>>& U, const vector<double>& z);