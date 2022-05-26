#include <stdio.h>

void swap(int *x, int *y) {
  int t = *x;
  *x = *y;
  *y = t;
}
void quick_sort(int arr[], int start, int end) {
  if (start >= end)
    return;
  int mid = arr[end];
  int left = start, right = end - 1;
  while (left < right) {
    while (arr[left] < mid && left < right)
      left++;
    while (arr[right] >= mid && left < right)
      right--;
    swap(&arr[left], &arr[right]);
  }
  if (arr[left] >= arr[end])
    swap(&arr[left], &arr[end]);
  else
    left++;
  if (left) {
    quick_sort(arr, start, left - 1);
  }
  quick_sort(arr, left + 1, end);
}
int containsDuplicate(int *nums, int numsSize) {
  quick_sort(nums, 0, numsSize - 1);
  for (int i = 0; i < numsSize - 1; i++) {
    if (nums[i] == nums[i + 1]) {
      return 1;
    }
  }
  return 0;
}
int main() {
  int nums[10] = {1, 2, 3, 5, 5, 6, 7, 8, 9, 10};
  printf("%d\n", containsDuplicate(nums, 10));
  return 0;
}