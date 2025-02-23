

# nums = [1, 1]
# # nums = [4, 3, 2, 7, 8, 2, 3, 1]

# n = len(nums)
# my_set = set(nums)

# res = []

# for i in range(1, n+1):
#     if i not in my_set:
#         res.append(i)

# print(res)


#! how to do it in place? space complexity O(1)

nums = [4, 3, 2, 7, 8, 2, 3, 1]


def findMissingNumbers(nums):
    for num in nums:
        foundIndex = abs(num) - 1
        if nums[foundIndex] > 0:
            nums[foundIndex] *= -1

    res = []

    for idx, num in enumerate(nums):
        if num > 0:
            res.append(idx+1)

    return res


print(findMissingNumbers(nums))
