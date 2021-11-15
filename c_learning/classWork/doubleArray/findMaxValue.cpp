#include <iostream>
using namespace std;

int main()
{
    int a[3][5] = {{11, 22, 33, 44, 55}, {13, 24, 57, 91, 28}, {50, 60, 70, 80, 90}};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }

    int maxValue = a[0][0], row, col;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (a[i][j] > maxValue)
            {
                maxValue = a[i][j];
                row = i;
                col = j;
            }
        }
    }

    cout << "the max value is : " << maxValue << ", the row is : " << row + 1 << ", the column is : " << col + 1 << endl;

    return 0;
}