#include <bits/stdc++.h>
using namespace std;

vector<double> gaussSeidelMethod(vector<vector<double>> v, vector<double> b, int mx, double tol)
{
    int n = v.size();
    vector<double> x(n, 0.0);

    for (int iter = 0; iter < mx; ++iter)
    {
        double err= 0.0;
        for (int i = 0; i < n; ++i)
        {
            double sum = 0.0;
            for (int j = 0; j < n; ++j)
            {
                if (j != i)
                {
                    sum += v[i][j] * x[j];
                }
            }
            double x_new = (b[i] - sum) / v[i][i];
            err += abs(x_new - x[i]);
            x[i] = x_new;
        }
        if (err< tol)
        {
            return x;
        }
    }
    return x;
}