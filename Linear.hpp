
#include "gaussElimination.hpp"
#include "gaussJordanElimination.hpp"
#include "Jacobi.hpp"
#include "gaussSeidel.hpp"
#include "LUfactorization.hpp"

using namespace std;
using Matrix = vector<vector<double>>;

bool makeDiagonallyDominant(Matrix &matrix, vector<double> &value) {
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        int maxRow = i;
        double maxElement = abs(matrix[i][i]);

        for (int j = i + 1; j < n; ++j) {
            if (abs(matrix[j][i]) > maxElement) {
                maxElement = abs(matrix[j][i]);
                maxRow = j;
            }
        }
        if (maxRow != i) {
            swap(matrix[i], matrix[maxRow]);
            swap(value[i], value[maxRow]);
        }

        double rowSum = 0.0;
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                rowSum += abs(matrix[i][j]);
            }
        }
        if (abs(matrix[i][i]) < rowSum) {
            return false; 
        }
    }
    return true; 
}

void LinearEquation() {
    cout << setprecision(6) << fixed;
    int n;
    cout << "Enter the number of variables (n): ";
    cin >> n;
    Matrix mat(n, vector<double>(n));
    vector<double> value(n), res;

    cout << "Enter the coefficients of the equations:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> mat[i][j];
        }
        cin >> value[i];
    }
    if (!makeDiagonallyDominant(mat, value)) {
        cout << "Warning: Could not achieve diagonal dominance by row swapping.\n";
    }
    cout << "Enter the method:\n";
    cout << "1. Jacobi iterative method\n";
    cout << "2. Gauss-Seidel iterative method\n";
    cout << "3. Gauss elimination\n";
    cout << "4. Gauss-Jordan elimination\n";
    cout << "5. LU factorization\n";
    cout << "6. Back\n";
    int op;
    cin >> op;
    if (op == 1) {
        cout << "Max Iteration for the method:\n";
        int maxIter;
        cin >> maxIter;
        cout << "Tolerance for the method:\n";
        double tol;
        cin >> tol;
        res = jacobiMethod(mat, value, maxIter, tol);
    }
    else if (op == 2) {
        cout << "Max Iteration for the method:\n";
        int maxIter;
        cin >> maxIter;
        cout << "Tolerance for the method:\n";
        double tol;
        cin >> tol;
        res = gaussSeidelMethod(mat, value, maxIter, tol);
    }
    else if (op == 3) {
        res = gaussElimination(mat, value);
        }
    else if (op == 4) {
        res = gaussJordanElimination(mat, value);
    }
    else if (op == 5) {
        pair<Matrix,Matrix>pr = luDecomposition(mat);
        res = luSolve(pr.first, pr.second, value);
    }
    else {
        return;
    }

    cout << "Solution:\n";
    for (int i = 0; i < n; ++i) {
        cout << "x[" << i + 1 << "] = " << res[i] << "\n";
    }
}
