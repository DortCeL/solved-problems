#include <bits/stdc++.h>
using namespace std;

void makeTable()
{
  int space = 15;

  cout << setw(space) << "itr" << setw(space) << "x1" << setw(space) << "f(x)" << setw(space) << "f'(x)" << setw(space) << "x0" << setw(space + 5) << "Relative Error" << setw(space) << "update" << setw(space + 8) << endl;
  cout << "===============================================================================================================" << endl;
}

void printTable(int i, double x1, double f, double f_prime, double x0, double absError, string update)
{
  int space = 15;

  cout << setw(space) << i << setw(space) << x1 << setw(space) << f << setw(space) << f_prime << setw(space) << x0 << setw(space) << absError << setw(space) << update << endl;
}

double fx(double x)
{
  return (x * x * x) - (x)-1;
}

double dfx(double x)
{
  return 3 * pow(x, 2) - 1;
}

double newton_raphson(double x, double tolerance)
{
  int i = 1;
  string update = "x0 = x1";
  double absError, relError;
  double x1, x0 = x;

  do
  {
    x1 = x - (fx(x0) / dfx(x0));
    absError = fabs(x1 - x0);
    relError = fabs((x1 - x0) / x1);
    printTable(i, x, fx(x0), dfx(x0), x1, relError, update);
    if (fx(x1) == 0)
      break;

    x0 = x1;
    i++;

  } while (relError >= tolerance);
}

int main(void)
{
  system("clear");

  makeTable();
  newton_raphson(1.5, 0.01);
}