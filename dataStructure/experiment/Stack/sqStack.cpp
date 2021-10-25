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

// Output the top element in SqStack
void OutPutPopElem(ElemType e)
{
    cout << "SqStack pop:" << e << endl;
}

// Pop a element
void Pop(SqStack &S)
{
    ElemType e;
    if (StackIsEmpty(S))
    {
        cout << "pop failed,the SqStack is empty" << endl;
        return;
    }
    e = S->data[S->top--];
    OutPutPopElem(e);
}

// Destroy SqStack
void DestroyStack(SqStack &S)
{
    delete (S->data);
    delete (S);
}

int main()
{
    SqStack S;
    InitStack(S, 20);
    if (StackIsEmpty(S))
    {
        cout << "the SqStack is empty" << endl;
    }
    else
    {
        cout << "the SqStack isn't empty" << endl;
    }
    Push(S, 'a');
    Push(S, 'b');
    Push(S, 'c');
    Push(S, 'd');
    Push(S, 'e');
    if (StackIsEmpty(S))
    {
        cout << "the SqStack is empty" << endl;
    }
    else
    {
        cout << "the SqStack isn't empty" << endl;
    }
    ElemType e;
    Pop(S);
    Pop(S);
    Pop(S);
    Pop(S);
    Pop(S);
    if (StackIsEmpty(S))
    {
        cout << "the SqStack is empty" << endl;
    }
    else
    {
        cout << "the SqStack isn't empty" << endl;
    }
    DestroyStack(S);
    // Test after destruction
    // Push(S,'t');
    return 0;
}