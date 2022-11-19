/*
 * @Author: Eave Luo
 * @Date: 2022-11-19 13:06:58
 * @LastEditors: Eave Luo
 * @LastEditTime: 2022-11-19 13:15:25
 * @Description: 关于贪心算法的纸币找零问题
 */
#include <stdio.h>

// 纸币面值
int Value[7] = {1, 2, 5, 10, 20, 50, 100};

int solve(int money)
{
    int count = 0;
    for (int i = 6; i >= 0; i--)
    {
        while (money >= Value[i])
        {
            money -= Value[i];
            count++;
        }
    }
    return count;
}

int main()
{
    printf(solve(20));
    return 0;
}
