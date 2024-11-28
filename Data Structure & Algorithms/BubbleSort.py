def bubbleSort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(n - i - 1):
            if arr[j+1] < arr[j]:
                arr[j], arr[j+1] = arr[j+1], arr[j]


arr = [5, 2, 3, 1, 6, 4]
bubbleSort(arr)

print(arr)
