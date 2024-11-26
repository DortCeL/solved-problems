#include <bits/stdc++.h>
using namespace std;

vector<int> coeff;

int signVariations(const vector<int> &coeffs)
{
  int variations = 0;
  int prev_sign = coeffs[0] > 0 ? 1 : -1;

  for (int i = 1; i < coeffs.size(); ++i)
  {
    int curr_sign = coeffs[i] > 0 ? 1 : -1;
    if (curr_sign != prev_sign && coeffs[i] != 0)
    {
      ++variations;
      prev_sign = curr_sign;
    }
  }

  return variations;
}

int main()
{
  int degree;
  cin >> degree;
  coeff.resize(degree + 1);
  for (int i = degree; i >= 0; --i)
  {
    cin >> coeff[i];
  }

  int variations = signVariations(coeff);

  cout << "Number of sign variations: " << variations << endl;

  return 0;
}