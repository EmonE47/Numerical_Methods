#include <bits/stdc++.h>

using namespace std;


pair<int, double> falsePositionMethod(vector<double> &co, double a, double b, double tol)
{
    if (getval(co, a) * getval(co, b) > 0)
    {
        return {0, 0};
    }

    double c = a;
    while (fabs(b - a) >= tol)
    {
        c = (a * getval(co, b) - b * getval(co, a)) / (getval(co, b) - getval(co, a));

        if (getval(co, c) == 0.0)
        {
            return {1, c};
        }
        else if (getval(co, c) * getval(co, a) < 0)
        {
            b = c;
        }
        else
        {
            a = c;
        }
    }
    return {1, c};
}

void falsePositionBase(vector<double> &co)
{
    pair<long long, long long> mx = calculate(co);
    cout << "Tolarence value :" << endl;
    double tol;
    cin >> tol;
    for (int i = mx.first; i <= mx.second; i++)
    {
        pair<int, double> res = falsePositionMethod(co, i, i + 1, tol);
        if (res.first == 1)
        {
            cout << "x = " << res.second << endl;
            break;
        }
    }
}