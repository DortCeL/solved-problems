////////////////////////////////////////////Sum of subsets
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void findCombination(int ind, int target, vector<int> &ds, vector<vector<int>> &ans, vector<int> &arr)
{
  if (target == 0)
  {
    ans.push_back(ds);
    return;
  }
  for (int i = ind; i < arr.size(); i++)
  {
    if (i > ind && arr[i] == arr[i - 1])
      continue;
    if (arr[i] > target)
      break;
    ds.push_back(arr[i]);
    findCombination(i + 1, target - arr[i], ds, ans, arr);
    ds.pop_back();
  }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
  sort(candidates.begin(), candidates.end());
  vector<vector<int>> ans;
  vector<int> ds;
  findCombination(0, target, ds, ans, candidates);
  return ans;
}

int main()
{
  int n, target;
  cout << "Enter the number of candidates: ";
  cin >> n;

  vector<int> candidates(n);
  cout << "Enter the candidates: ";
  for (int i = 0; i < n; i++)
  {
    cin >> candidates[i];
  }

  cout << "Enter the target sum: ";
  cin >> target;

  vector<vector<int>> result = combinationSum2(candidates, target);

  cout << "Combinations that sum to " << target << " are: " << endl;
  for (auto &comb : result)
  {
    cout << "[ ";
    for (int num : comb)
    {
      cout << num << " ";
    }
    cout << "]" << endl;
  }

  return 0;
}
/////////////////////////////////////////////////////////////////N-Queens
#include <bits/stdc++.h>
using namespace std;
// implemented assuming we will place queen no n in row n
int n;
vector<int> x(100); // store the column number for each queen. The index represents the queen/row number
int cnt = 0;

bool Place(int k, int i) // checks if a queen can be placed in a given row k and column i without conflicting with other queens.
{
  for (int j = 1; j <= k - 1; j++)
  { // k no row te/queen bosabo tai k-1 porjonto queen/row number check korte hbe
    if ((x[j] == i) || (abs(x[j] - i) == abs(j - k)))
      return false;
  }
  return true;
}

void N_Queens(int k, int n) // k diye row borarbor jaite thakbo then prottek row er prottek column e kaj korbo
{
  for (int i = 1; i <= n; i++)
  { // iterates over all column i in the current row k
    if (Place(k, i) == true)
    {
      x[k] = i; // saving column no i in the kth row/ placing kth queen in colum i
      if (k == n)
      { // then write
        cnt++;
        cout << "Way no  " << cnt << "  is :" << endl;
        for (int q = 1; q <= n; q++)
          cout << "Queen [" << q << "]  sits in Row " << q << " , column " << x[q] << "  " << endl;
        cout << endl;
      }
      else
        N_Queens(k + 1, n); // else go to next row/queen
    }
  }
}

int main()
{
  cout << "Enter the Number of Queens : " << endl;
  cin >> n;
  N_Queens(1, n);
  return 0;
}
