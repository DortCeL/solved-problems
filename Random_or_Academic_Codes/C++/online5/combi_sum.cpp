#include <bits/stdc++.h>
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