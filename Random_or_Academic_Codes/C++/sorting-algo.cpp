#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &arr, int n) {
  for (int i=0; i<n; i++) {
    int j = i;
    while ( j > 0 and arr[j-1] > arr[j] ) {
      swap(arr[j-1], arr[j]);
      j--;
    }
  }
}

void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; 
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high)
        if (arr[left] <= arr[right])
            temp.push_back(arr[left++]);
        else 
            temp.push_back(arr[right++]);

    while (left <= mid)
        temp.push_back(arr[left++]);

    while (right <= high)
        temp.push_back(arr[right++]);

    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &arr, int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2 ;
    mergeSort(arr, low, mid); 
    mergeSort(arr, mid + 1, high); 
    merge(arr, low, mid, high); 
}

int partition(vector<int> &arr, int low, int high) {
  int pivot = arr[low];
  int left = low;
  int right = high;
  while (left < right) {
    while (arr[left] <= pivot and left < right)
      left++;

    while (arr[right] > pivot and right > low)
      right--;

    if (left < right) 
      swap(arr[left], arr[right]);

  }
  swap(arr[low], arr[right]);
  return right;
}

void quickSort(vector<int>& arr, int low, int high) {
  if (low < high) {
    int pIndex = partition(arr, low, high);
    quickSort(arr, low, pIndex-1);
    quickSort(arr, pIndex+1, high);
  }
}

int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;

        if (arr[m] == x)
            return m;
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

int main (void)
{
  system("cls");

  vector<int> arr = {2,1,4,10,0,7,8,3};
  int n = arr.size();

  // insertion_Sort(arr, n);
  // mergeSort (arr, 0, n-1);
  // quickSort(arr, 0, n-1);

  for (auto &e : arr) {
    cout << e << " ";
  }
  cout << endl;
}
