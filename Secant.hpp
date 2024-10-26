#include <bits/stdc++.h>

using namespace std;


pair<int, double> secantMethod(vector<double> &co, double x0, double x1, double tol, int mx)
{
    double x2;
    for (int i = 0; i < mx; ++i)
    {
        double f_x0 = getval(co, x0);
        double f_x1 = getval(co, x1);
        if ((f_x1 - f_x0) == 0)
        {
            return {0, 0};
        }
        x2 = x1 - f_x1 * (x1 - x0) / (f_x1 - f_x0);

        if (fabs(x2 - x1) < tol)
        {
            return {1, x2};
        }
        x0 = x1;
        x1 = x2;
    }
    return {1, x2};
}
void secantBase(vector<double> &co)
{
    double x0, x1, tol;
    int mx;
    cout << "Enter the first guess : " << endl;
    cin >> x0;
    cout << "Enter the second guess : " << endl;
    cin >> x1;
    cout << "Tolerance : " << endl;
    cin >> tol;
    cout << "Max Iteration : " << endl;
    cin >> mx;
    pair<int, double> ans = secantMethod(co, x0, x1, tol, mx);
    if (ans.first == 0)
    {
        cout << "Can't Calculate For this Input" << endl;
    }
    else
    {
        cout << "x = " << ans.second << endl;
    }
}
