// 2107093
#include <bits/stdc++.h>
using namespace std;

void DisplayMatrix(const vector<vector<double>> &mat)
{
    int n = mat.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << mat[i][j] << "    ";
        }
        cout << endl;
        cout << endl;
    }
}
bool InverseMatrix(vector<vector<double>> &mat, vector<vector<double>> &inv)
{
    int n = mat.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            inv[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if (fabs(mat[i][i]) < 1e-9)
        {
            cerr << "Matrix is singular " << endl;
            return false;
        }
        double Pivot = mat[i][i];
        for (int j = 0; j < n; ++j)
        {
            mat[i][j] /= Pivot;
            inv[i][j] /= Pivot;
        }
        for (int k = 0; k < n; ++k)
        {
            if (k != i)
            {
                double Factor = mat[k][i];
                for (int j = 0; j < n; ++j)
                {
                    mat[k][j] = mat[k][j] - Factor * mat[i][j];
                    inv[k][j] = inv[k][j] - Factor * inv[i][j];
                }
            }
        }
    }
    return true;
}
void Matrix_Inversion()
{
    int n;
    cout << "Enter the size    :";
    cin >> n;
    vector<vector<double>> mat(n, vector<double>(n));
    vector<vector<double>> inv(n, vector<double>(n));
    cout << "Enter the elements   :" << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> mat[i][j];
        }
    }
    cout << "Original Matrix    :" << endl;
    DisplayMatrix(mat);
    if (InverseMatrix(mat, inv))
    {
        cout << "Inverted Matrix   :" << endl;
        DisplayMatrix(inv);
    }
    else
    {
        cout << "Not invertible...." << endl;
    }
}