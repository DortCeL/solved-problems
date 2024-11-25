from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        num_to_index = {}
        res = []
        # memoize each element with index
        for i in range(n):
            rem = target - nums[i]
            if rem in num_to_index:
                return [i, num_to_index.get(rem)]
            else:
                num_to_index.update({nums[i]: i})
        return []


solution = Solution()


nums = [2, 7, 11, 15]
target = 9

print(solution.twoSum(nums, target))
