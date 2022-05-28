#include <stdio.h>

void print(int *nums, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d\t", nums[i]);
  }
  printf("\n");
}

int partition(int arr[], int low, int high) {
  int key;
  key = arr[low];
  while (low < high) {
    while (low < high && arr[high] >= key)
      high--;
    if (low < high)
      arr[low++] = arr[high];
    while (low < high && arr[low] <= key)
      low++;
    if (low < high)
      arr[high--] = arr[low];
  }
  arr[low] = key;
  return low;
}
void quick_sort(int arr[], int start, int end) {
  int pos;
  if (start < end) {
    pos = partition(arr, start, end);
    quick_sort(arr, start, pos - 1);
    quick_sort(arr, pos + 1, end);
  }
  return;
}

void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n) {
  // insert nums2 to nums1
  for (int i = 0; i < n; i++) {
    nums1[i + m] = nums2[i];
  }
  print(nums1, n + m);
  // sort
  quick_sort(nums1, 0, n + m - 1);
}

int main() {
  int nums1[6] = {1, 2, 3}, nums1Size = 3, n = 3, nums2[3] = {2, 5, 6},
      nums2Size = 3, m = 3;
  merge(nums1, nums1Size, m, nums2, nums2Size, n);
  print(nums1, n + m);
  return 0;
}