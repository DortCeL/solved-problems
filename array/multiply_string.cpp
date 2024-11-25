#include <bits/stdc++.h>
using namespace std;

string multiply(string num1, string num2)
{
  int m = num1.length();
  int n = num2.length();
  int power = 0;
  int sum = 0;

  for (int i = m - 1; i >= 0; i--)
  {
    for (int j = n - 1; j >= 0; j--)
    {
      sum += (int)num2[i] * (int)num1[j] * pow(10, i + j);
    }
    power = 0;
  }

  cout << sum;
  return "";
}

int main(void)
{
  string a = "123";
  string b = "456";
  cout << multiply(a, b) << endl;
}