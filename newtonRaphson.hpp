#include <bits/stdc++.h>

using namespace std;


vector<double> computeDer(vector<double> &co)
{
    int n = co.size() - 1;
    vector<double> der(n);
    for (int i = 0; i < n; ++i)
    {
        der[i] = co[i] * (n - i);
    }
    return der;
}
pair<int, double> newtonRaphsonMethod(vector<double> &co, vector<double> &der, double x0, double tol, int mx)
{
    for (int i = 0; i < mx; ++i)
    {
        double f_x0 = getval(co, x0);
        double f_prime_x0 = getval(der, x0);
        if (f_prime_x0 == 0)
        {
            return {0, 0};
        }
        double x1 = x0 - f_x0 / f_prime_x0;

        if (fabs(x1 - x0) < tol)
        {
            return {1, x1};
        }
        x0 = x1;
    }
    return {1, x0};
}

void newtonRaphsonBase(vector<double> &co)
{
    vector<double> der = computeDer(co);
    double x0, tol;
    int mx;
    cout << "Enter the guess : " << endl;
    cin >> x0;
    cout << "Tolerance : " << endl;
    cin >> tol;
    cout << "Max Iteration : " << endl;
    cin >> mx;
    pair<int, double> ans = newtonRaphsonMethod(co, der, x0, tol, mx);
    if (ans.first == 0)
    {
        cout << "Can't Calculate For this Input" << endl;
    }
    else
    {
        cout << "x = " << ans.second << endl;
    }
}