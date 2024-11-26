//? MUST CHECK COMMENTS.....

#include <bits/stdc++.h>
using namespace std;

// Function to find the longest common subsequence
string longestCommonSubsequence(const string &text1, const string &text2)
{
  int m = text1.size();
  int n = text2.size();

  // Create a 2D vector to store lengths of longest common subsequence
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

  // Fill dp array
  for (int i = 1; i <= m; ++i)
  {
    for (int j = 1; j <= n; ++j)
    {
      if (text1[i - 1] == text2[j - 1])
      {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      }
      else
      {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  // print dp table

  for (int i = 0; i <= m; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      cout << dp[i][j] << "  ";
    }
    cout << endl;
  }

  //! no reconstruction from dp table
  //* eitay error dibe for some inputs probably. so reconstruct kora dorkar must
  int i = m;
  int j = n;
  string result = "";

  while (i > 0 and j > 0)
  {
    if (text1[i - 1] == text2[j - 1])
    {
      result += text1[i - 1];
      i--;
      j--;
    }
    else if (dp[i - 1][j] > dp[i][j - 1])
      i--;
    else
      j--;
  }

  return result;
}

int main()
{
  string text2 = "ezupkr";
  string text1 = "ubmrapg";

  // ? UPR keno ans ashtese AJOB!

  string lcs = longestCommonSubsequence(text1, text2);

  // !ULTA KORTE HOBE!
  // * ALSO, JODI JOTOGULA LCS ASHE SHOB DEKHAITE BOLE???!!!! IDK MAN
  reverse(lcs.begin(), lcs.end());

  cout << "LCS length : " << lcs.length() << endl;
  cout << "Longest Common Subsequence: " << lcs << endl;

  return 0;
}
