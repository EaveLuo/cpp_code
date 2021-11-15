#include <iostream>
using namespace std;

int main()
{
    int a[11][11];
    for (int i = 1; i < 11; i++)
    {
        a[i][1] = a[i][i] = 1;
        for (int j = 2; j <= i - 1; j++)
        {
            a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
        }
    }

    for (int i = 1; i < 11; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}