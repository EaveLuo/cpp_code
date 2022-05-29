#include <stdlib.h>

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

int *intersect(int *nums1, int nums1Size, int *nums2, int nums2Size,
               int *returnSize) {
  quick_sort(nums1, 0, nums1Size - 1);
  quick_sort(nums2, 0, nums2Size - 1);
  *returnSize = 0;
  int *returnNum = malloc(
      sizeof(int *) *
      (nums1Size < nums2Size
           ? nums1Size
           : nums2Size)); // 仅需分配两者最小的那一个即可，因为交集最大不会超过最小的那一个
  int a = 0, b = 0;
  while (a < nums1Size && b < nums2Size) {
    if (nums1[a] < nums2[b]) {
      a++;
    } else if (nums1[a] > nums2[b]) {
      b++;
    } else {
      returnNum[(*returnSize)++] = nums1[a];
      a++;
      b++;
    }
  }
  return returnNum;
}