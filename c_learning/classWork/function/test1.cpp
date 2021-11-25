#include <iostream>
#include <math.h>
using namespace std;

double fact(int n)
{
    double res = 0, fenMu = 1;
    for (int i = 1; (n > 0 ? pow(n, i) : pow(-n, i)) / fenMu >= pow(10, -5); i++)
    {
        fenMu *= i;
        res += pow(n, i) / fenMu;
    }
    return res;
}

int main()
{
    double res = fact(2);
    cout << "res:" << res << endl;
    return 0;
}