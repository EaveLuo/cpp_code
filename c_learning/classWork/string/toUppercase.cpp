#include <iostream>
using namespace std;

int main()
{
    int num = 0;
    char str[10];
    cout << "please enter string :";
    for (int i = 0; (str[i] = getchar())!='\n'; i++)
    {
        // count the lowercase numbers
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            num++;
            str[i] -= 32;
        }
    }
    cout << "lowercase' number is : " << num<<endl;
    cout<<"string's content : ";
    for (int i = 0; i < 10; i++)
    {
        cout<<str[i];
    }
    cout<<endl;
    return 0;
}