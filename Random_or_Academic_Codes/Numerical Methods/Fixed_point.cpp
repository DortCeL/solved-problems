#include <bits/stdc++.h>
using namespace std;

void makeTable()
{
  int space = 15;
  cout << setw(space) << "itr" << setw(space) << "x" << setw(space) << "f(x)" << setw(space) << "g(x)" << endl;
  cout << "====================================================================" << endl;
}

void printTable(int i, double x, double fx, double gx)
{
  int space = 15;
  cout << setw(space) << i << setw(space) << x << setw(space) << fx << setw(space) << gx << endl;
}

double f(double x)
{
  return pow(x, 4) - 4; // Function f(x) = x^4 - 4
}

double g(double x)
{
  return ((2 / x) + x) / 2; // Function g(x) = (4 / x)^(1/4)
}

double fixed_point(double x0, double tolerance)
{
  int i = 1;
  double x = x0;
  double fx, gx;

  while (1)
  {
    fx = f(x);
    gx = g(x);

    printTable(i, x, fx, gx);
    if (abs(x - gx) < tolerance)
      break;
    x = gx; // Update x for the next iteration
    i++;
  }

  return x; // Return the approximate root
}

int main()
{
  makeTable();
  double root = fixed_point(1, 0.0001); // Starting with an initial guess of 1.5
  cout << "Root: " << root << endl;
  return 0;
}
