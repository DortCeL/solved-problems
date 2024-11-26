#include <bits/stdc++.h>
using namespace std;

string g_path = "";

void LCS(string x, string y, int i, int j, string path)
{
  if (i == x.size() or j == y.size())
    return;
  if (x[i] == y[j] and (path == "" || path[path.size() - 1] < x[i]))
  {
    path += x[i];
    if (path.size() > g_path.size())
    {
      g_path = path;
    }
    LCS(x, y, i + 1, j + 1, path);
    path.pop_back();
  }
  else
  {
    LCS(x, y, i, j + 1, path);
    LCS(x, y, i + 1, j, path);
  }
}

int main(void)
{
  string x = "CDABAG";
  string y = "ABCDEBAFG";

  LCS(x, y, 0, 0, "");
  cout << g_path << endl;
}