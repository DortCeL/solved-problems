#include <bits/stdc++.h>
using namespace std;

vector<int> prices = {7, 1, 5, 3, 6, 4};
// vector<int> prices = {1, 2, 3, 4, 5};
// vector<int> prices = {7, 6, 4, 3, 1};

int len = prices.size();

void recursion(int index, int mini, int maxProfit, vector<int> results = vector<int>())
{
  if (index == len - 1)
    return;
}

int maxProfit(vector<int> &prices)
{
  recursion(0, prices[0], 0);
}

int main(void)
{
  cout << maxProfit(prices);
}