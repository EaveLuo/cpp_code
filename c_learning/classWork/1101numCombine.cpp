#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int count, lastNum;
    cout << "please enter the number's count:";
    cin >> count;
    int num[count];
    for (int i = 0; i < count; i++)
    {
        cout << "please enter the " << i + 1 << " number:";
        cin >> num[i];
    }
    for (int i = 0; i < count; i++)
    {
        lastNum += num[i] * (pow(10, i));
    }
    cout << "the number is :" << lastNum << endl;
    return 0;
}