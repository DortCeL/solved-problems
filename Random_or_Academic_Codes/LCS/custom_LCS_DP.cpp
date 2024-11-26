// CHALLENGE was : LCS ber korbo but has to be in ascending order; so table ta ke fill up korar time e oi onujayi fillup korsi
// complexity = O(mn)

#include <bits/stdc++.h>
using namespace std;

string result = "";

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
      if (text1[i - 1] == text2[j - 1] and (result == "" || result[result.length() - 1] < text1[i - 1]))
      {
        dp[i][j] = dp[i - 1][j - 1] + 1;
        result += text1[i - 1];
      }
      else
      {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  return result;
}

int main()
{
  string text1 = "CDABAG";
  string text2 = "ABCDEBAFG";

  string lcs = longestCommonSubsequence(text1, text2);

  cout << "LCS length : " << lcs.length() << endl;
  cout << "Longest Common Subsequence: " << lcs << endl;

  return 0;
}
