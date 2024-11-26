#include <bits/stdc++.h>
using namespace std;

void makeTable() {
  int space = 15;

  cout << setw(space) << "itr" << setw(space) << "a" << setw(space) << "f(a)" << setw(space) << "b" << setw(space) << "f(b)" << setw(space) << "c" << setw(space) << "f(c)" << setw(space) << "update" << setw(space + 8) << "Relative Error" << endl;
  cout << "======================================================================================================================================================" << endl;
}

void printTable(int i, double a, double fa, double b, double fb, double c, double fc, string update, double relError) {
  int space = 15;

  cout << setw(space) << i << setw(space) << a << setw(space) << fa << setw(space) << b << setw(space) << fb << setw(space) << c << setw(space) << fc << setw(space) << update << setw(space + 5) << relError << endl;
}

double func(double x) {
  return (x*x*x) - (x) - 1;
}

double false_position(double a, double b, double tolerance) {

  if (func(a) * func(b) > 0) {
    cout << "Wrong Guess!" << endl;
    return 0;
  }

  int i = 1;
  double c, relError, absError, fa, fb, fc;
  string update = "";

  do {


    fa = func(a);
    fb = func(b);

    c = a - ( ( (b-a) * fa ) / ( fb - fa ) );
    fc = func(c);

    absError = fabs(c - a);
    relError = fabs( (c-a) / c );

    if (fa * fc < 0) {
      update = "b = c";
      printTable(i, a, fa, b, fb, c, fc, update, relError);
      b = c;
    }
    else  {
      update = "a = c";
      printTable(i, a, fa, b, fb, c, fc, update, relError);
      a = c;
    }

    
    i++;

  } while (relError >= tolerance);
}


int main (void) 
{
  system("cls");

  makeTable();
  false_position(1, 2, 0.01);

}