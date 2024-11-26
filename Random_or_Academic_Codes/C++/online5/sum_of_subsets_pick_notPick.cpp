#include <bits/stdc++.h>
using namespace std;

void findCombination(int ind, int target, vector<int> &ds, vector<vector<int>> &ans, vector<int> &arr, vector<int> &selection)
{
  if (target == 0)
  {
    ans.push_back(selection);
    return;
  }
  for (int i = ind; i < arr.size(); i++)
  {
    if (i > ind && arr[i] == arr[i - 1])
      continue;

    // sort na korle eitao delete korte hobe. karon oitar porer kono ta ans hoitei pare.
    // if (arr[i] > target)
    //   break;
    ds.push_back(arr[i]);
    selection[i] = 1;
    findCombination(i + 1, target - arr[i], ds, ans, arr, selection);
    ds.pop_back();
    selection[i] = 0;
  }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
  // sort(candidates.begin(), candidates.end());
  vector<vector<int>> ans;
  vector<int> ds;
  vector<int> selection(candidates.size(), 0);
  findCombination(0, target, ds, ans, candidates, selection);
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
    for (int pick : comb)
    {
      cout << pick << " ";
    }
    cout << "]" << endl;
  }

  return 0;
}
