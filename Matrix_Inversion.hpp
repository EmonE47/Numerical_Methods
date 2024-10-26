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
bool InverseMatrix(vector<vector<double>> &matrix, vector<vector<double>> &inverse)
{
    int size = matrix.size();

    for (int row = 0; row < size; ++row)
    {
        for (int col = 0; col < size; ++col)
        {
            inverse[row][col] = (row == col) ? 1.0 : 0.0;
        }
    }

    for (int currentRow = 0; currentRow < size; ++currentRow)
    {

        if (fabs(matrix[currentRow][currentRow]) < 1e-9)
        {
            cerr << "Matrix is singular" << endl;
            return false;
        }
        double pivotElement = matrix[currentRow][currentRow];
        for (int col = 0; col < size; ++col)
        {
            matrix[currentRow][col] /= pivotElement;
            inverse[currentRow][col] /= pivotElement;
        }

        for (int otherRow = 0; otherRow < size; ++otherRow)
        {
            if (otherRow != currentRow)
            {
                double factor = matrix[otherRow][currentRow];
                for (int col = 0; col < size; ++col)
                {
                    matrix[otherRow][col] -= factor * matrix[currentRow][col];
                    inverse[otherRow][col] -= factor * inverse[currentRow][col];
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