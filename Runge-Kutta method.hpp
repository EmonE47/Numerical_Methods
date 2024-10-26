// 2107093
#include <bits/stdc++.h>
using namespace std;

double dydx(double x, double y)
{
    return sin(x) + 1;
}
double dydx2(double x, double y)
{
    return x + y;
}

void rungeKutta()
{

    double x = 0.0;
    double y = 1.0;
    double h = 0.1;
    double xEnd = 5.0;
    cout << fixed << setprecision(6);
    cout << "1.For dy/dx=sin(x)+1  " << endl;
    cout << "2.For dy/dx=x+y  " << endl;
    int m;
    cin >> m;
    if (m == 1)
    {
        cout << "x" << "\t\t" << "y" << endl;
        while (x < xEnd)
        {
            cout << x << "\t" << y << endl;
            double k1 = h * dydx(x, y);
            double k2 = h * dydx(x + h / 2.0, y + k1 / 2.0);
            double k3 = h * dydx(x + h / 2.0, y + k2 / 2.0);
            double k4 = h * dydx(x + h, y + k3);

            y = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;
            x = x + h;

            cout << x << "\t" << y << endl;
        }
    }
    else
    {
        cout << "x" << "\t" << "y" << endl;
        while (x < xEnd)
        {
            cout << x << "\t" << y << endl;
            double k1 = h * dydx2(x, y);
            double k2 = h * dydx2(x + h / 2.0, y + k1 / 2.0);
            double k3 = h * dydx2(x + h / 2.0, y + k2 / 2.0);
            double k4 = h * dydx2(x + h, y + k3);

            y = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;
            x = x + h;

            cout << x << "\t" << y << endl;
        }
    }
}