#include <stdio.h>
#include <math.h>
int main(int argc, const char *argv[])
{
    int sc[10][5];
    void input_score(int score[10][5]);    //输入函数
    void average_st(int score[10][5]);     //求学生成绩平均数函数
    void average_course(int score[10][5]); //求每门课的平均分函数
    void max_course(int score[10][5]);     //求最大数函数
    void vari_course(int score[10][5]);    //求方差函数

    input_score(sc); //调用输入函数
    average_st(sc);  //调用求学生成绩平均数函数
    printf("\n");
    average_course(sc); //调用求每门课的平均分函数
    printf("\n");
    max_course(sc); //调用求最大数函数
    printf("\n");
    vari_course(sc); //调用求方差函数
    return 0;
}

// 输入函数
void input_score(int score[10][5])
{
    int i, j;
    for (i = 0; i < 10; i++)
    {
        printf("第%d个学生的成绩：\n", i + 1);
        for (j = 0; j < 5; j++)
        {
            printf("成绩%d：", j + 1);
            scanf("%d", &score[i][j]);
        }
        printf("\n");
    }
}

//求学生成绩平均数函数
void average_st(int score[10][5])
{
    int i, j;
    double sum;
    for (i = 0; i < 10; i++)
    {
        for (j = 0, sum = 0; j < 5; j++)
            sum = sum + score[i][j];
        printf("第%d个学生的成绩平均数为:%lf\n", i + 1, sum / 5);
    }
}

//求每门课的平均分函数
void average_course(int score[10][5])
{
    int i, j;
    double sum;
    for (j = 0; j < 5; j++)
    {
        for (i = 0, sum = 0; i < 10; i++)
            sum = sum + score[i][j];
        printf("第%d门课的平均数为:%lf\n", j + 1, sum / 10);
    }
}

//求最大数函数
void max_course(int score[10][5])
{
    int i, j, max = 0, stu = 0, cour = 0;
    for (i = 0; i < 10; i++)
        for (j = 0; j < 5; j++)
            if (score[i][j] > max)
            {
                max = score[i][j];
                stu = i + 1;
                cour = j + 1;
            }
    printf("第%d个学生的第%d门课获得了%d的最高分\n", stu, cour, max);
}

//求平均分方差函数
void vari_course(int score[10][5])
{
    int i, j, sum;
    float average[10], var, x1 = 0, x2 = 0;
    for (i = 0; i < 10; i++)
    {
        for (j = 0, sum = 0; j < 5; j++)
            sum = sum + score[i][j];
        average[i] = sum / 5;
    }
    for (i = 0; i < 10; i++)
    {
        x1 = x1 + pow(average[i], 2);
        x2 = x2 + average[i];
    }
    var = x1 / 10 - pow(x2 / 10, 2);
    printf("方差为 %f\n", var);
}