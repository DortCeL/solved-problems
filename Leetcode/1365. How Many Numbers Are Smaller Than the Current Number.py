def solve(nums):
    nums.sort(reverse=True)
    res = []
    for i in range(1, len(nums)):
        if nums[i] != nums[i-1]:
            res.append(len(nums) - i)
            continue
        res.append(0)

    return res


nums = [8, 1, 2, 2, 3]
print(solve(nums))
