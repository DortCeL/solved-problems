#include <bits/stdc++.h>
using namespace std;

int main(void)
{
}

//! This is my initial solution which was accepted but its not the best one...
// class Solution {
// public:
//     int firstMissingPositive(vector<int>& nums) {
//         int n = nums.size();

//         if (n == 1) {
//             return nums[0] == 1 ? 2 : 1;
//         }

//         sort (nums.begin(), nums.end());

//         bool found = false;
//         int last_positive;

//         int i = 0;
//         for (i = 0; i<n; i++)
//         {
//             if (nums[i] > 0) break;
//         }

//         if (i == n) return 1;

//         if (nums[i] > 1) return 1;

//         last_positive = nums[i];
//         i++;
//         for (; i<n; i++)
//         {
//             if (nums[i] - last_positive > 1) return last_positive + 1;
//             last_positive = nums[i];
//         }

//         return nums[n-1] + 1;

//     }
// };