#include <stdbool.h>
#include <stdlib.h>
bool isValidSudoku(char **board, int boardSize, int *boardColSize) {

  // 创建一个0-9的空数组，先初始化都为0
  int *dic = malloc(sizeof(int) * 10);
  for (int i = 0; i < 10; i++) {
    dic[i] = 0;
  }

  // 先判断行
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      // 用原值与新数组的序号匹配
      if (board[i][j] != '.') {
        if (dic[board[i][j] - '0'] == 0) {
          dic[board[i][j] - '0'] = 1;
        } else {
          return false;
        }
      }
    }
    for (int k = 0; k < 10; k++) {
      dic[k] = 0;
    }
  }

  // 再判断列
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      // 用原值与新数组的序号匹配
      if (board[j][i] != '.') {
        if (dic[board[j][i] - '0'] == 0) {
          dic[board[j][i] - '0'] = 1;
        } else {
          return false;
        }
      }
    }
    for (int k = 0; k < 10; k++) {
      dic[k] = 0;
    }
  }

  // 再判断3*3
  for (int a = 0; a < 9; a++) {
    int r = (a % 3) * 3;
    int c = (a / 3) * 3;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        // 用原值与新数组的序号匹配
        if (board[r + i][c + j] != '.') {
          if (dic[board[r + i][c + j] - '0'] == 0) {
            dic[board[r + i][c + j] - '0'] = 1;
          } else {
            return false;
          }
        }
      }
    }
    for (int k = 0; k < 10; k++) {
      dic[k] = 0;
    }
  }
  return true;
}