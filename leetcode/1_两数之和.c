/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
  for (int i = 0; i < numsSize; ++i) {
    for (int j = i + 1; j < numsSize; ++j) {
      if (nums[i] + nums[j] == target) {
        int *ret = malloc(sizeof(int) * 2);
        ret[0] = i, ret[1] = j;
        *returnSize = 2;
        return ret;
      }
    }
  }
  *returnSize = 0;
  return 0;
}

int main() {
  int nums[4] = {2, 7, 11, 15}, *returnSize, *res;
  res = twoSum(nums, 4, 9, returnSize);
  return 0;
}