#include <stdio.h>
// 宏定义问题规模
#define weightSize 3 // weight数组的⼤⼩ 就是物品个数
#define valueSize 3
#define bagWeight 4 // 背包重量

// 比较最大值
int max(int a, int b) { return a > b ? a : b; }

// 打印表格
void printTable(int dp[weightSize + 1][bagWeight + 1]) {
  for (int i = 0; i < weightSize; i++) {
    for (int j = 0; j <= bagWeight; j++) {
      printf("%d\t", dp[i][j]);
    }
    printf("\n");
  }
}

void zrbag_problem() {
  int weight[weightSize] = {1, 3, 4};
  int value[valueSize] = {15, 20, 30};

  // 二维数组
  int dp[weightSize + 1][bagWeight + 1];
  // 初始化dp[i][0]
  for (int i = 0; i < weightSize; i++) {
    dp[i][0] = 0;
  }
  // 初始化dp[0][j]
  for (int j = 0; j < weight[0]; j++) {
    dp[0][j] = 0;
  }
  for (int j = weight[0]; j <= bagWeight; j++) {
    dp[0][j] = value[0];
  }
  // 填表格
  for (int i = 1; i < weightSize; i++) {   // 遍历物品
    for (int j = 0; j <= bagWeight; j++) { // 遍历背包容量
      if (j < weight[i])
        dp[i][j] = dp[i - 1][j];
      else
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
    }
  }
  printf("%d\n", dp[weightSize - 1][bagWeight]);
  printTable(dp);
}

int main() { zrbag_problem(); }