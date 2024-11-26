#include <bits/stdc++.h>
using namespace std;

double horner(vector<double> &coeff, int n, int x)
{
  double p = coeff[0]; // initialize result
  // evaluate
  for (int i = 1; i <= n; i++)
    p = p * x + coeff[i];
  return p;
}

int main(void)
{
  int n;
  cout << "Degree: ";
  cin >> n;
  vector<double> coeff(n + 1);
  for (int i = n; i >= 0; i--)
  {
    cout << "Coefficient " << i << " : ";
    cin >> coeff[n - i];
  }

  cout << horner(coeff, n, 2) << endl;
}