/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */

#include <stdlib.h>

// 暴力解法，思路：两个for循环一行一行的处理
// int **matrixReshape(int **mat, int matSize, int *matColSize, int r, int c,
//                     int *returnSize, int **returnColumnSizes) {

//   // 判断新矩阵参数是否合法
//   if (r * c != matSize * *matColSize) {
//     *returnSize = matSize;
//     *returnColumnSizes = matColSize;
//     return mat;
//   }

//   *returnSize = r;
//   *returnColumnSizes = (int *)malloc(sizeof(int) * r);

//   // 分配内存
//   int **returnMat = (int **)malloc(sizeof(int *) * r);
//   int row = 0, col = 0;
//   for (int i = 0; i < r; i++) {
//     (*returnColumnSizes)[i] = c;
//     returnMat[i] = (int *)malloc(sizeof(int) * c);
//     // 一行一行往里塞
//     for (int j = 0; j < c; j++) {
//       returnMat[i][j] = mat[row][col++];
//       if (col == (*matColSize)) {
//         row++;
//         col = 0;
//       }
//     }
//   }
//   return returnMat;
// }

int **matrixReshape(int **mat, int matSize, int *matColSize, int r, int c,
                    int *returnSize, int **returnColumnSizes) {

  // 判断新矩阵参数是否合法
  if (r * c != matSize * *matColSize) {
    *returnSize = matSize;
    *returnColumnSizes = matColSize;
    return mat;
  }

  *returnSize = r;
  *returnColumnSizes = (int *)malloc(sizeof(int) * r);

  // 分配内存
  int **returnMat = (int **)malloc(sizeof(int *) * r);
  for (int i = 0; i < r; i++) {
    (*returnColumnSizes)[i] = c;
    returnMat[i] = (int *)malloc(sizeof(int) * c);
  }

  // 利用计算特性来解题，减少一个嵌套，时间复杂度降到o(m*n)
  for (int i = 0; i < matSize * (*matColSize); ++i) {
    returnMat[i / c][i % c] = mat[i / *matColSize][i % *matColSize];
  }
  return returnMat;
}