#include <iostream>
using namespace std;

// 两个操作都由于没有大括号指定范围，故else会自动匹配最近的if，导致与预期出现差错
void test1(int &x, int &y)
{
    y = -1;
    if (x != 0)
        if (x > 0)
            y = 1;
        else
            y = 0;
}

void test2(int &x, int &y)
{
    y = 0;
    if (x >= 0)
        if (x > 0)
            y = 1;
        else
            y = -1;
}

int main()
{
    int x, y;
    cout << "enter x:";
    cin >> x;
    // test1
    // test1(x, y);
    test2(x, y);
    cout << "x=" << x << ",y=" << y << endl;
    return 0;
}