/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

int **generate(int numRows, int *returnSize, int **returnColumnSizes) {
  *returnSize = numRows;

  // 已知行数，可以将二维数组的第一维长度定义并分配内存
  int **res = (int **)malloc((*returnSize) * sizeof(int *));
  *returnColumnSizes = (int *)malloc(*returnSize * sizeof(int));
  for (int i = 0; i < *returnSize; i++) {
    res[i] = (int *)malloc((i + 1) * sizeof(int));
    (*returnColumnSizes)[i] = i + 1;
    res[i][0] = res[i][i] = 1;
    for (int j = 1; j < i; j++) {
      res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
    }
  }
  return res;
}