#include <iostream>
using namespace std;

int arrayLength = 5;

// 验证输入数据格式
bool verifyNumber(int num, int numSize)
{
    bool res = true;
    if (numSize > 5 || num <= 0)
    {
        res = false;
    }
    return res;
}

// 计算此数位数
int countNumber(int num)
{
    int n;
    while (num >= 1)
    {
        num /= 10;
        n++;
    }
    return n;
}

// 按个十百千万顺序取出每位数字存入数组中，方便正向与反向输出
void getEveryNumber(int num, int everyNum[])
{
    for (int i = 0; i < arrayLength; i++)
    {
        everyNum[i] = num % 10;
        num /= 10;
    }
}

// 按个十百千万输出每位
void outputEveryNumber(int everyNum[])
{
    cout << "out put every number:";
    for (int i = 0; i < arrayLength; i++)
    {
        cout << everyNum[i] << ",";
    }
    cout << endl;
}

// 按万千百十个输出每位
void outputEveryNumberReverse(int everyNum[])
{
    cout << "reversely out put every number:";
    for (int i = arrayLength - 1; i >= 0; i--)
    {
        cout << everyNum[i] << ",";
    }
    cout << endl;
}

int main()
{
    int num, everyNum[arrayLength];
    cout << "please enter the number:";
    cin >> num;
    int numSize = countNumber(num);
    arrayLength = numSize;
    bool res = verifyNumber(num, numSize);
    if (!res)
    {
        cout << "please enter the right format number!" << endl;
    }
    else
    {
        cout << "the number's Size is:" << numSize << endl;
        getEveryNumber(num, everyNum);
        outputEveryNumber(everyNum);
        outputEveryNumberReverse(everyNum);
    }
    return 0;
}