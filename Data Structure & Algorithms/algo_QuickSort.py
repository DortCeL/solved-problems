def quickSort(arr):
    if len(arr) <= 1:
        return arr

    pivot = arr[0]

    smaller = [x for x in arr[1:] if x < pivot]
    bigger = [x for x in arr[1:] if x >= pivot]

    return quickSort(smaller) + quickSort(bigger) + pivot


arr = [5, 2, 3, 1, 6, 4]


print(arr)
