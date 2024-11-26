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
  double x, x0 = 0, prev = 0.0, curr, x1, x2, x4, x5 = 0.0, er;
  int n, itr = 0;
  cout << "Enter the value of degree " << endl;
  cin >> n;
  cout << "Enter the value of coefficients" << endl;
  for (int i = 0; i <= n; i++)
  {
    cout << "Coefficient x^" << n - i << " =";
    cin >> a[i];
  }
  cout << "Enter the value of x0" << endl;
  cin >> x0;
  while (n > 0)
  {
    do
    {
      prev = x;
      x = x0 - (fx(a, n, x0) / deffx(a, n, x0));
      x0 = x;
      curr = x;
      er = (fabs(prev - curr) / curr) * 100;

    } while (fabs(prev - curr) >= 0.0001);
    cout << "Root at degree" << n << " = " << x << endl
         << endl;

    b[0] = a[0];
    for (int i = 1; i <= n; i++)
    {
      b[i] = (b[i - 1] * x) + a[i];
    }
    n = n - 1;

    cout << "Quotient polynomial of degree " << n;

    for (int i = 0; i <= n; i++)
    {
      printf("b[%d]=%f\n", i, b[i]);
    }
    for (int i = 0; i <= n; i++)
    {

      a[i] = b[i];
    }
  }

  return 0;
}