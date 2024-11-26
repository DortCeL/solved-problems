#include <bits/stdc++.h>
using namespace std;

void makeTable()
{
  int space = 15;

  cout << setw(space) << "itr" << setw(space) << "x1" << setw(space) << "f(x1)" << setw(space) << "x2" << setw(space) << "f(x2)" << setw(space) << "x3" << setw(space) << "f(x3)" << setw(space) << "update" << setw(space + 8) << "Relative Error" << endl;
  cout << "======================================================================================================================================================" << endl;
}

void printTable(int i, double a, double fa, double b, double fb, double c, double fc, string update, double relError)
{
  int space = 15;

  cout << setw(space) << i << setw(space) << a << setw(space) << fa << setw(space) << b << setw(space) << fb << setw(space) << c << setw(space) << fc << setw(space) << update << setw(space + 5) << relError << endl;
}

double func(double x)
{
  return x * x * x - x - 1;
}

double secant(double x1, double x2, double tolerance)
{
  int i = 1;
  double x3, relError, absError, fa, fb, fc;
  string update = "";

  do
  {

    fa = func(x1);
    fb = func(x2);

    x3 = x2 - (((x2 - x1) * fb) / (fb - fa));
    fc = func(x3);

    absError = fabs(x3 - x2);
    relError = fabs((x3 - x2) / x3);

    update = "x2=x3, x3=x3";
    printTable(i, x1, fa, x2, fb, x3, fc, update, relError);
    x1 = x2;
    x2 = x3;

    i++;

  } while (absError >= tolerance);

  return x3;
}

int main(void)
{
  system("clear");

  makeTable();
  double root = secant(1, 2, 0.01);
  cout << "Root = " << root << endl;
}