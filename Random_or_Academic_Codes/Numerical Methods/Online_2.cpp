#include <bits/stdc++.h>
using namespace std;

double pi = 3.1416;
double r = 10;
double v = 800;

double f(double h)
{
  return 3 * pi * r * h * h - pi * h * h * h - 3 * v;
}

double ff(double h)
{
  return 2 * pi * h * r - 3 * pi * h * h;
}

double newton_Raphson(double x0)
{
  double x1, check;
  int i = 0;
  do
  {
    i++;
    x1 = x0 - (f(x0) / ff(x0));
    check = fabs(x1 - x0);
    x0 = x1;
  } while (check >= 0.000001);
  cout << i << endl;
  return x1;
}

double g(double h)
{
  return cbrt(((3 * pi * r * h * h) - 3 * v) / pi);
}

double fixed_point(double x0)
{
  double x1, check;
  int i = 0;
  do
  {
    i++;
    x1 = g(x0);
    check = (fabs(x1 - x0));
    x0 = x1;
  } while (check >= 0.000001);
  cout << i << endl;
  return x1;
}

double secant(double a, double b)
{
  double x3;
  double check = -101;
  int i = 0;
  do
  {
    i++;
    x3 = a - ((f(a) * (b - a)) / (f(b) - f(a)));
    if (check == -101)
      check = x3;
    else
      check = fabs(x3 - b);
    a = b;
    b = x3;
  } while (check >= 0.000001);
  cout << i << endl;
  return x3;
}
int main()
{
  double root;
  // root=newton_Raphson(16);
  // root=fixed_point(16);
  root = secant(1, 18);
  cout << root << endl;
  return 0;
}