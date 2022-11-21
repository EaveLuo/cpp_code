/*
 * @Author: Eave Luo
 * @Date: 2022-11-19 13:31:30
 * @LastEditors: Eave Luo
 * @LastEditTime: 2022-11-19 14:03:42
 * @Description: 贪心算法的乘船问题
 */
#include <stdio.h>

void Quick_Sort(int a[], int l, int r)
{
    if (l < r)
    {
        int i, j, x;
        i = l;
        j = r;
        x = a[i];
        while (i < j)
        {
            while (i < j && a[j] > x)
            {
                j--; // 从右向左找第一个小于x的数
            }
            if (i < j)
            {
                a[i++] = a[j]; // 将小于x的值放在左边
            }
            while (i < j && a[i] < x)
            {
                i++; // 从左向右找第一个大于x的数
            }
            if (i < j)
            {
                a[j--] = a[i]; // 将大于x的值放在右边
            }
        }
        a[i] = x;
        Quick_Sort(a, l, i - 1);
        Quick_Sort(a, i + 1, r);
    }
}

int solve()
{
    int n, c;
    int w[9999];
    printf("请输入人数：");
    scanf("%d", &n);
    printf("请输入船的载重：");
    scanf("%d", &c);
    printf("请输入每个人的重量：");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &w[i]);
    }
    // 利用快速排序对权重进行排序
    Quick_Sort(w, 0, n - 1);

    // 遍历数组，每次取最重的和最轻的，如果两者之和小于等于c，则两人一起上船，否则最重的人单独上船
    int i = 0, j = n - 1; // i指向最轻的人，j指向最重的人
    int count = 0;        // 记录船的数量
    while (i <= j)
    {
        if (w[i] + w[j] <= c)
        {
            i++;
            j--;
        }
        else
        {
            j--;
        }
        count++;
    }
    return count;
}

int main()
{
    printf("需要%d条船",solve());

    return 0;
}
