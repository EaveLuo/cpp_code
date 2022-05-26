#include <stdio.h>
int maxSubArray(int *nums, int numsSize) {
  int preValue = 0, maxValue = *nums;
  for (int i = 0; i < numsSize; i++) {
    preValue += nums[i];
    if (preValue > maxValue) {
      maxValue = preValue;
    }
    if (preValue < 0) {
      preValue = 0;
    }
  }
  return maxValue;
}

int main() {
  int nums[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  int nums1[2] = {-2, -1};
  int nums2[4] = {1, -1, -2};
  int nums3[5] = {5, 4, -1, 7, 8};
  int nums4[5] = {8, -19, 5, -4, 20};
  int nums5[2] = {-1, -2};
  int subSum = maxSubArray(nums, 9);
  int subSum1 = maxSubArray(nums1, 2);
  int subSum2 = maxSubArray(nums2, 4);
  int subSum3 = maxSubArray(nums3, 5);
  int subSum4 = maxSubArray(nums4, 5);
  int subSum5 = maxSubArray(nums5, 2);
  printf("%d\n", subSum);
  printf("%d\n", subSum1);
  printf("%d\n", subSum2);
  printf("%d\n", subSum3);
  printf("%d\n", subSum4);
  printf("%d\n", subSum5);
  return 0;
}