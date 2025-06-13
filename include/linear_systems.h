#pragma once
  #include <vector>
 using namespace std;

//rozkładanie macierzy A na macierze L (dolna trójkątna) i U (górna trójkątna)
 void luDecomposition(const vector<vector<double>>& A, vector<vector<double>>& L, vector<vector<double>>& U);
//rozwiązuje Lz = b (podstawianie w przód)
 vector<double> forwardSubstitution(const vector<vector<double>>& L, const vector<double>& b);
//rozwiązuje Ux = z (podstawianie wstecz)
 vector<double> backSubstitution(const vector<vector<double>>& U, const vector<double>& z);
