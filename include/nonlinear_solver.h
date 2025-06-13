#pragma once
#include <functional>
using namespace std;
//znajdowanie pierwiastka równania f(x)=0 metodą Newtona-Raphsona
double newtonAnalytical(function<double(double)> f, function<double(double)> df, double x0, double epsilon = 1e-8, int max_iter = 100);
