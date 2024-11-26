#include <bits/stdc++.h>
using namespace std;

double coeff[100][100];
int itr = 0;

void gauss_jordan(int n)

{
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (i == j)
        continue;

      double factor = coeff[j][i] / coeff[i][i];
      for (int k = 1; k <= n + 1; k++)
        coeff[j][k] -= factor * coeff[i][k];

      // print matrix
      cout << ++itr;
      for (int i = 1; i <= n; i++)
      {
        for (int j = 1; j <= n + 1; j++)
        {
          cout << coeff[i][j] << " ";
        }
        cout << endl;
      }
    }
  }
}

solution(int n)
{
  for (int i = 1; i <= n; i++)
  {
    res[i] = coeff[i][n + 1] / coeff[i][i];
  }
}