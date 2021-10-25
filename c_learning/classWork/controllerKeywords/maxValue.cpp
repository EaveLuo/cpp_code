#include <iostream>
using namespace std;
#define numSize 10

int main()
{
    float maxValue = 0, n;
    for (int i = 0; i < numSize; i++)
    {
        cout << "please enter the " << i + 1 << " number:";
        cin >> n;
        n > maxValue ? maxValue = n : 0;
    }
    cout << "the max value is:" << maxValue << endl;
    return 0;
}