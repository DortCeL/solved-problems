def mergeSort(arr):
    # <= karon empty array dileo jate kaj kore
    if len(arr) <= 1:
        return arr

    mid = len(arr) // 2
    left = arr[:mid]
    right = arr[mid:]

    # divide
    left, right = mergeSort(left), mergeSort(right)

    # conquer
    i = j = 0
    index = 0

    result = [0] * (len(left) + len(right))
    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            result[index] = left[i]
            index += 1
            i += 1
        else:
            result[index] = right[j]
            index += 1
            j += 1

    while i < len(left):
        result[index] = left[i]
        i += 1
        index += 1
    while j < len(right):
        result[index] = right[j]
        j += 1
        index += 1

    return result


arr = [5, 2, 3, 1, 6, 4]
sortedArr = mergeSort(arr)

print(sortedArr)
