#include <bits/stdc++.h>

using namespace std;

vector<double> jacobiMethod(vector<vector<double>> &A, const vector<double> &b, int maxIterations, double tolerance)
{
    int n = A.size();
    vector<double> x(n, 0.0);
    vector<double> x_new(n, 0.0);

    for (int iter = 0; iter < maxIterations; ++iter)
    {
        for (int i = 0; i < n; ++i)
        {
            double sum = 0.0;
            for (int j = 0; j < n; ++j)
            {
                if (j != i)
                {
                    sum += A[i][j] * x[j];
                }
            }
            x_new[i] = (b[i] - sum) / A[i][i];
        }

        double error = 0.0;
        for (int i = 0; i < n; ++i)
        {
            error += abs(x_new[i] - x[i]);
        }
        if (error < tolerance)
        {
            return x_new;
        }
        x = x_new;
    }
    return x;
}