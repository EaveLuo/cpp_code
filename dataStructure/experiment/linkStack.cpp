#include <iostream>
using namespace std;

typedef char ElemType;

typedef struct LinkNode
{
    ElemType data;
    struct LinkNode *next;
} * LinkStack;

// Initialize LinkStack(set a headnode)
void InitStack(LinkStack &S)
{
    S = new LinkNode;
    S->next = NULL;
}

// Is Stack empty?
bool StackIsEmpty(LinkStack S)
{
    if (S->next == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Push a element
void Push(LinkStack &S, ElemType e)
{
    LinkStack insertNode = new LinkNode;
    insertNode->data = e;
    insertNode->next = S->next;
    S->next = insertNode;
}

// Output the top element in SqStack
void OutPutPopElem(ElemType e)
{
    cout << "SqStack pop:" << e << endl;
}

// Pop a element
void Pop(LinkStack &S)
{
    ElemType e;
    if (StackIsEmpty(S))
    {
        cout << "pop failed,the SqStack is empty" << endl;
        return;
    }
    LinkStack p = S->next;
    e = p->data;
    S->next = p->next;
    delete (p);
    OutPutPopElem(e);
}

// Destroy LinkStack
void DestroyStack(LinkStack &S)
{
    LinkStack pre = S, p = S->next;
    while (p != NULL)
    {
        delete (pre);
        pre = p;
        p = p->next;
    }
    delete (pre);
}

int main()
{
    LinkStack S;
    InitStack(S);
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
    Push(S, 't');
    return 0;
}