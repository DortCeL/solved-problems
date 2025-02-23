# nums = [9, 6, 4, 2, 3, 5, 7, 0, 1]
nums = [3, 0, 1]

n = len(nums)
actualSum = n * (n+1) // 2
sumOfTheArray = 0
for num in nums:
    sumOfTheArray += num

print(actualSum - sumOfTheArray)
