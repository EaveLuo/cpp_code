#include <iostream>
using namespace std;

int main()
{
    char a[10];
    cout << "please enter your string:";
    cin >> a;
    for (int i = 0; i < 10; i++)
    {
        if (a[i] >= 'a' && a[i] <= 'z' || a[i] >= 'A' && a[i] <= 'Z')
        {
            a[i] += 5;
            if (a[i] > 'z' || a[i] > 'Z' && a[i] <= 'Z' + 6)
            {
                a[i] -= 26;
            }
        }
    }
    for (int i = 0; i < 10; i++)
    {
        cout << a[i];
    }
    cout << endl;
    return 0;
}