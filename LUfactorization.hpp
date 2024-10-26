#include <bits/stdc++.h>

using namespace std;

pair<vector<vector<double>>, vector<vector<double>>> luDecomposition(vector<vector<double>> v)
{
    int n = v.size();
    vector<vector<double>> L(n, vector<double>(n, 0.0));
    vector<vector<double>> U(v);

    for (int i = 0; i < n; ++i)
    {
        L[i][i] = 1.0;
        for (int j = i + 1; j < n; ++j)
        {
            double factor = U[j][i] / U[i][i];
            L[j][i] = factor;
            for (int k = i; k < n; ++k)
            {
                U[j][k] -= factor * U[i][k];
            }
        }
    }
    return {L, U};
}

vector<double> luSolve(vector<vector<double>> L, vector<vector<double>> U,vector<double> b)
{
    int n = L.size();
    vector<double> y(n, 0.0), x(n, 0.0);

    for (int i = 0; i < n; ++i)
    {
        y[i] = b[i];
        for (int j = 0; j < i; ++j)
        {
            y[i] -= L[i][j] * y[j];
        }
        y[i] /= L[i][i];
    }

    for (int i = n - 1; i >= 0; --i)
    {
        x[i] = y[i];
        for (int j = i + 1; j < n; ++j)
        {
            x[i] -= U[i][j] * x[j];
        }
        x[i] /= U[i][i];
    }
    return x;
}
