#include <bits/stdc++.h>
using namespace std;

double fx(double coeff[], int n, double x)
{
  double p = coeff[0];
  for (int i = 1; i <= n; i++)
  {
    p = p * x + coeff[i];
  }
  return p;
}
double deffx(double poly[], int n, double x)
{
  double value = 0;
  int i;
  for (i = 0; i < n; i++)
  {
    value = value * x + (n - i) * poly[i];
  }
  return value;
}

int main()
{
  double a[10], b[10];
  double x = 0, x0, prev = 0.0, curr, x1, x2, x4, x5 = 0.0, er, f1, f2;
  int n, itr = 0;

  cout << "enter the value of degree" << endl;
  cin >> n;
  cout << "enter the value of coefficient" << endl;
  for (int i = 0; i <= n; i++)
  {
    cout << endl
         << "coefficientx x[" << n - i << "]=";
    cin >> a[i];
  }

  cout << "enter the value of x0" << endl;
  cin >> x0;
  cout << "enter the value of x1" << endl;
  cin >> x1;

  while (n > 0)
  {

    do
    {
      prev = x1;
      f1 = fx(a, n, x0);
      f2 = fx(a, n, x1);

      x2 = x0 - ((f1 * (x1 - x0)) / (f2 - f1));
      x0 = x1;
      x1 = x2;
      curr = x2;

      er = ((fabs(prev - curr) / curr) * 100);
    } while (fabs(prev - curr) >= 0.00000000001);
    cout << "root at drgee " << n << "= " << x2 << endl;
    cout << endl;

    b[0] = a[0];
    for (int i = 1; i <= n; i++)
    {
      b[i] = (b[i - 1] * x2) + a[i];
    }
    n = n - 1;

    cout << "Quotient polymial of degree " << n << endl;

    for (int i = 0; i <= n; i++)
    {
      cout << "b[" << i << "]=" << b[i] << endl;
    }

    for (int i = 0; i < n; i++)
    {
      a[i] = b[i];
    }
  }

  return 0;
}