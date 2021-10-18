#include <iostream>
using namespace std;

int main()
{
    int sum = 0, i = 1;
    // while (i <= 100)
    // {
    //     sum += i;
    //     i++;
    // }
    do
    {
        sum += i;
        i++;
    } while (i <= 100);
    cout << sum << endl;
    return 0;
}