#include <stdio.h>

int main()
{
    int a, b, c, temp;
    scanf("%d", &a);
    c = a;
    while (a)
    {
        temp = a % 10;
        b = b * 10 + temp;
        a /= 10;
    }
    c == b
        ? printf("yes\n")
        : printf("no\n");
    return 0;
}