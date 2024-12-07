
def solve(intervals):

    arr = sorted(intervals)

    start = arr[0][0]
    end = arr[0][1]

    res = []

    for x, y in arr[1:]:
        if x <= end:
            end = max(y, end)
        else:
            res.append([start, end])
            start = x
            end = y
    res.append([start, end])

    return res


intervals = [[1, 4], [2, 3], [5, 6]]
res = solve(intervals)
print(res)


# def merge(self, intervals: List[List[int]]) -> List[List[int]]:
#     ret = []
#     intervals.sort()
#     for interval in intervals:
#         if not ret or ret[-1][1] < interval[0]:
#             ret.append(interval)
#         else:
#             ret[-1][1] = max(interval[1], ret[-1][1])
#     return ret
