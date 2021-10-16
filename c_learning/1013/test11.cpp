#include <iostream>
using namespace std;

#define numbersSize 4

// 此处排序可以采用经典的冒泡排序算法
void bubbleSort(int inputNumbers[])
{
    for (int i = 0; i < numbersSize - 1; i++)
    {
        bool flag = false;
        for (int j = numbersSize - 1; j > i; j--)
        {
            if (inputNumbers[j - 1] > inputNumbers[j])
            {
                int temp = inputNumbers[j - 1];
                inputNumbers[j - 1] = inputNumbers[j];
                inputNumbers[j] = temp;
                flag = true;
            }
        }
        if (flag == false)
            return;
    }
}

int main()
{
    int inputNumbers[numbersSize];
    for (int i = 0; i < numbersSize; i++)
    {
        cout << "please enter the " << i + 1 << " number:";
        cin >> inputNumbers[i];
    }
    bubbleSort(inputNumbers);
    // output the right sort
    cout << "the right sort numbers is:";
    for (int i = 0; i < numbersSize; i++)
    {
        cout << inputNumbers[i] << ",";
    }
    cout << endl;
    return 0;
}