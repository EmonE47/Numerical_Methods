#include "Bisection.hpp"
#include "FalsePosition.hpp"
#include "Secant.hpp"
#include "newtonRaphson.hpp"
using namespace std;

void NonLinearEquation()
{
    int n;
    cout << "Enter the degree of the polynomial: ";
    cin >> n;

    vector<double> co(n + 1);
    cout << "Enter the coefficients (from highest degree to constant term): ";
    for (int i = 0; i <= n; ++i)
    {
        cin >> co[i];
    }
    cout << "Choose a root-finding method:\n";
    cout << "1. Bisection Method\n";
    cout << "2. False Position Method\n";
    cout << "3. Secant Method\n";
    cout << "4. Newton-Raphson Method\n";
    cout << "5. Back" << endl;
    int op;
    cin >> op;
    if (op == 1)
    {
        bisectionBase(co);
    }
    else if (op == 2)
    {
        falsePositionBase(co);
    }
    else if (op == 3)
    {
        secantBase(co);
    }
    else if (op == 4)
    {
        newtonRaphsonBase(co);
    }
}