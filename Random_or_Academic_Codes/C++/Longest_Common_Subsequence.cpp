#include <bits/stdc++.h>
using namespace std;

string A = "AGGTAB";
string B = "GXTXAYB";
int m = A.length();
int n = B.length();

int lcs(int m = A.length(), int n = B.length())
{
  if (m == 0 or n == 0)
    return 0;
  if (A[m - 1] == B[n - 1])
    return 1 + lcs(m - 1, n - 1);
  else
    return max(lcs(m, n - 1), lcs(m - 1, n));
}

int main(void)
{
  cout << lcs() << endl;
}
