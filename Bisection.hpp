#include <bits/stdc++.h>

using namespace std;

double getval(vector<double> &co, double x)
{
    double result = 0;
    int n = co.size() - 1;
    for (int i = 0; i <= n; i++)
    {
        result = result * x + co[i];
    }
    return result;
}
double largestRoot(vector<double> &co)
{
    int n = co.size() - 1;
    double a_n = co[0];
    double a_n_1 = co[1];
    double a_n_2 = co[2];
    return (a_n_1 / a_n) * 2 - (a_n_2 / a_n);
}

pair<long long, long long> calculate(vector<double> &co)
{
    double x = largestRoot(co);
    long long x_max = abs(ceil(x));
    return {-x_max, x_max};
}
pair<int, double> bisectionMethod(vector<double> &co, double a, double b, double tol)
{
    if (getval(co, a) * getval(co, b) > 0)
    {
        return {0, 0};
    }
    double c = a;
    while ((b - a) >= tol)
    {
        c = (a + b) / 2;
        if (getval(co, c) == 0.0)
        {
            return {1, c};
        }
        else if (getval(co, c) * getval(co, a) < 0)
        {
            b = c;
        }
        else
            a = c;
    }
    return {1, c};
}
void bisectionBase(vector<double> &co)
{
    pair<long long, long long> mx = calculate(co);
    cout << "Tolarence value :" << endl;
    double tol;
    cin >> tol;
    for (int i = mx.first; i <= mx.second; i++)
    {
        pair<int, double> res = bisectionMethod(co, i, i + 1, tol);
        if (res.first == 1)
        {
            cout << "x = " << res.second << endl;
            break;
        }
    }
}
