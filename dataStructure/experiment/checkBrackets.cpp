#include <iostream>
using namespace std;

typedef char ElemType;

typedef struct sqStack
{
    ElemType *data;
    int top, maxSize;
} * SqStack;

// Initialize sqStack
void InitStack(SqStack &S, int initSize)
{
    S = new sqStack;
    S->data = new ElemType[initSize];
    S->top = -1;
    S->maxSize = initSize;
}

// Is Stack empty?
bool StackIsEmpty(SqStack S)
{
    if (S->top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Push a element
void Push(SqStack &S, ElemType e)
{
    if (S->top == S->maxSize - 1)
    {
        cout << "push failed,the sqStack is full" << endl;
        return;
    }
    S->data[++S->top] = e;
}

// Pop a element
void Pop(SqStack &S)
{
    if (StackIsEmpty(S))
    {
        cout << "pop failed,the SqStack is empty" << endl;
        return;
    }
    S->top--;
}

// Destroy SqStack
void DestroyStack(SqStack &S)
{
    delete (S->data);
    delete (S);
}

// chech out the expression's brackets
bool checkOut(SqStack &S, ElemType exp[])
{

    for (int i = 0; exp[i] != '\0'; i++)
    {
        switch (exp[i])
        {
        case '(':
        case '[':
        case '{':
            Push(S, exp[i]);
            break;
        case ')':
            if ((S->top[S->data] == '(') && !StackIsEmpty(S))
            {
                Pop(S);
            }
            else
            {
                return false;
            }
            break;
        case ']':
            if ((S->top[S->data] == '[') && !StackIsEmpty(S))
            {
                Pop(S);
            }
            else
            {
                return false;
            }
            break;
        case '}':
            if ((S->top[S->data] == '{') && !StackIsEmpty(S))
            {
                Pop(S);
            }
            else
            {
                return false;
            }
            break;
        default:
            break;
        }
    }
    return StackIsEmpty(S);
}

int main()
{
    // set a array storage the expression
    char exp[1000];
    // input an expression
    cout << "please enter an expression:";
    cin >> exp;
    SqStack S;
    InitStack(S, 100);
    bool checkOutResult = checkOut(S, exp);
    if (checkOutResult)
    {
        cout << "expression's brackets is right!" << endl;
    }
    else
    {
        cout << "expression's brackets is error!" << endl;
    }
    DestroyStack(S);
    return 0;
}