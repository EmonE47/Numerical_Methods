#include <bits/stdc++.h>

using namespace std;

vector<double> gaussElimination(vector<vector<double>> v, vector<double> b)
{
    int n = v.size();
    vector<double> x(n, 0.0);

    for (int i = 0; i < n; ++i)
    {
        for (int k = i + 1; k < n; ++k)
        {
            double factor = v[k][i] / v[i][i];
            for (int j = i; j < n; ++j)
            {
                v[k][j] -= factor * v[i][j];
            }
            b[k] -= factor * b[i];
        }
    }
    for (int i = n - 1; i >= 0; --i)
    {
        x[i] = b[i];
        for (int j = i + 1; j < n; ++j)
        {
            x[i] -= v[i][j] * x[j];
        }
        x[i] /= v[i][i];
    }
    return x;
}