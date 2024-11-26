// problem : ABG print koraite hobe....
// HOW??



#include <bits/stdc++.h>
using namespace std;

  string text2 = "CDABAG";
  string text1 = "ABCDEBAFG";

  int m = text1.size();
  int n = text2.size();

  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));


  vector<string> answers;




string LCS(int m, int n)
{
  int i = m, j = n;
  string lcs;

  while (i > 0 && j > 0)
  {
    if (text1[i - 1] == text2[j - 1])
    {
      lcs = text1[i - 1] + lcs;
      --i;
      --j;
    }
    else if (dp[i - 1][j] > dp[i][j - 1])
      --i;
    else
      --j;
  }

  return lcs;
}


bool isAscending(string str)
{
    for (int i=0; i<str.length()-1; i++)
    {
        if (str[i] > str[i+1])
            return false;
    }
    return true;
}




// Function to find the longest common subsequence
string longestCommonSubsequence(const string &text1, const string &text2)
{


  // Create a 2D vector to store lengths of longest common subsequence


  // Fill dp array
  for (int i = 1; i <= m; ++i)
  {
    for (int j = 1; j <= n; ++j)
    {
      if (text1[i - 1] == text2[j - 1])
      {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      }
      else
      {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }


  // Print DP table

  cout << "DP Table:" << endl;
  for (int i = 0; i <= m; ++i)
  {
    for (int j = 0; j <= n; ++j)
    {
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;


    // CHECK
    int x = m;
    int y = n;
    string res = "";


    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            string newAns = LCS(i, j);

            answers.push_back(newAns);
        }
    }


    for (auto s : answers)
    {
        if (isAscending(s))
        cout << s << endl;
    }

}





int main()
{

  string lcs = longestCommonSubsequence(text1, text2);

  cout << "LCS length : " << lcs.length() << endl;
  cout << "Longest Common Subsequence: " << lcs << endl;

  return 0;
}
