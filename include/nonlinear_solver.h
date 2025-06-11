#pragma once
#include <functional>
using namespace std;
double newtonAnalytical(function<double(double)> f, function<double(double)> df, double x0, double epsilon = 1e-8, int max_iter = 100);