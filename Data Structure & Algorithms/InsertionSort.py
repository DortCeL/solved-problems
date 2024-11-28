def insertionSort(arr):
    for i in range(1, len(arr)):
        j = i - 1
        key = arr[i]

        while j >= 0 and key < arr[j]:
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = key


arr = [5, 2, 3, 1, 6, 4]
insertionSort(arr)

print(arr)
