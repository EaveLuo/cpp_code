#include <iostream>
using namespace std;

int main()
{
    double score;
    char grade;
    cout << "please enter your score: ";
    cin >> score;
    if (score < 60)
    {
        grade = 'E';
    }
    else if (score < 70)
    {
        grade = 'D';
    }
    else if (score < 80)
    {
        grade = 'C';
    }
    else if (score < 90)
    {
        grade = 'B';
    }
    else
    {
        grade = 'A';
    }
    cout << "your score is " << score << ",and your grade is " << grade << endl;
    return 0;
}