int maxProfit(int *prices, int pricesSize) {

  // 暴力法超时，思路简单
  // int res = 0;
  // for (int i = 0; i < pricesSize - 1; i++) {
  //   for (int j = i + 1; j < pricesSize; j++) {
  //     if (prices[j] - prices[i] > res) {
  //       res = prices[j] - prices[i];
  //     }
  //   }
  // }
  // return res;

  // 一次遍历法，遍历选最小值，再算利润
  int minValue = *prices, res = 0;
  for (int i = 1; i < pricesSize; i++) {
    minValue = (minValue > prices[i] ? prices[i] : minValue);
    res = (res > (prices[i] - minValue) ? res : (prices[i] - minValue));
  }
  return res;
}
