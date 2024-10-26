#include <bits/stdc++.h>

using namespace std;

vector<double> gaussJordanElimination(vector<vector<double>> v, vector<double> b)
{
    int n = v.size();
    vector<double> x(n, 0.0);

    for (int i = 0; i < n; ++i)
    {
        int maxRow = i;
        for (int k = i + 1; k < n; ++k)
        {
            if (abs(v[k][i]) > abs(v[maxRow][i]))
            {
                maxRow = k;
            }
        }
        swap(v[i], v[maxRow]);
        swap(b[i], b[maxRow]);

        for (int j = 0; j < n; ++j)
        {
            if (i != j)
            {
                double factor = v[j][i] / v[i][i];
                for (int k = i; k < n; ++k)
                {
                    v[j][k] -= factor * v[i][k];
                }
                b[j] -= factor * b[i];
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        x[i] = b[i] / v[i][i];
    }
    return x;
}