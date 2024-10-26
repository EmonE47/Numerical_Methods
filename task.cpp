#include <bits/stdc++.h>
#include "NonLinear.hpp"
#include "Linear.hpp"
#include "Runge-Kutta method.hpp"
#include "Matrix_Inversion.hpp"
using namespace std;

int main()
{
    int test = 1;
    while (test)
    {
        cout << "Select Option :" << endl;
        cout << "1. Linear Equation" << endl;
        cout << "2. Non Linear Equation" << endl;
        cout << "3. Runge Kutta Method" << endl;
        cout << "4. Inverse Matrix" << endl;
        cout << "5. Exit" << endl;
        cin >> test;
        if (test == 1)
        {
            LinearEquation();
        }
        else if (test == 2)
        {
            NonLinearEquation();
        }
        else if (test == 3)
        {
            rungeKutta();
        }
        else if (test == 4)
        {
            Matrix_Inversion();
        }
        else
        {
            cout << "Exiting..." << endl;
        }
    }
}