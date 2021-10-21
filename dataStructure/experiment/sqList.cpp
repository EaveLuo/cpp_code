#include <iostream>
using namespace std;

typedef char ElemType;

typedef struct LinearList
{
    ElemType *data;
    int length, maxSize;
} * SqList;

// Initialize SqList
void InitList(SqList &L, int initSize)
{
    L = new LinearList;
    // L->data = (ElemType *)malloc(sizeof(ElemType) * initSize);
    L->data = new ElemType[initSize];
    L->maxSize = initSize;
    L->length = 0;
}

// Insert data at the end of SqList
void ListInsertAtEnd(SqList &L, ElemType e)
{
    if (L->length == L->maxSize)
    {
        cout << "\'" << e << "\'"
             << " is insert failed,maybe your SqList is 1"
             << "full,you should expand your SqList!" << endl;
        return;
    }
    L->data[L->length] = e;
    L->length++;
}

// Insert element
void ListInsert(SqList &L, ElemType e, int location)
{
    if (L->length == L->maxSize)
    {
        cout << "\'" << e << "\'"
             << " is insert failed,maybe your SqList is 1"
             << "full,you should expand your SqList!" << endl;
        return;
    }
    if (location <= L->length + 1 && location > 0)
    {
        for (int i = L->length; i > location - 1; i--)
        {
            L->data[i] = L->data[i - 1];
        }
        L->data[location - 1] = e;
        L->length++;
    }
    else
    {
        cout << "insert failed,the location \'"
             << location << "\' is illegal" << endl;
    }
}

// Delete element
void ListDelete(SqList &L, int location)
{
    if (location <= L->length && location > 0)
    {
        for (int i = location - 1; i < L->length; i++)
        {
            L->data[i] = L->data[i + 1];
        }
        L->length--;
    }
    else
    {
        cout << "delete failed,the location \'" << location << "\' is illegal" << endl;
    }
}

// Is SqList Empty?
bool IsSqListEmpty(SqList L)
{
    if (L->length == 0)
    {
        return true;
    }
    return false;
}

// Output SqList
void OutputSqList(SqList L)
{
    if (IsSqListEmpty(L))
    {
        cout << "the SqList is empty" << endl;
        return;
    }
    cout << "Output SqList:";
    for (int i = 0; i < L->length; i++)
    {
        cout << L->data[i] << " ";
    }
    cout << endl;
}

// Output SqList by location
void OutputSqListByLocate(SqList L, int location)
{
    if (IsSqListEmpty(L))
    {
        cout << "the SqList is empty" << endl;
        return;
    }
    if (location > L->length || location <= 0)
    {
        cout << "the location is illegal" << endl;
        return;
    }
    cout << "Output the " << location
         << " element is :" << L->data[location - 1] << endl;
}

// Locate the element
void LocateElem(SqList L, ElemType e)
{
    int location = -1;
    if (IsSqListEmpty(L))
    {
        cout << "the SqList is empty" << endl;
        return;
    }
    for (int i = 0; i < L->length; i++)
    {
        if (L->data[i] == e)
        {
            location = i + 1;
        }
    }
    if (location == -1)
    {
        cout << "don't find "
             << "the element " << e << endl;
    }
    else
    {
        cout << "the element " << e << " located in " << location << endl;
    }
}

// Destroy SqList
void DestroyList(SqList &L)
{
    if (L)
    {
        delete (L->data);
        delete (L);
    }
}

int main()
{
    SqList L;
    InitList(L, 10);
    ListInsertAtEnd(L, 'a');
    ListInsertAtEnd(L, 'b');
    ListInsertAtEnd(L, 'c');
    ListInsertAtEnd(L, 'd');
    OutputSqList(L);
    cout << "the SqList L's length is:" << L->length << endl;
    OutputSqListByLocate(L, 3);
    LocateElem(L, 'c');
    ListInsert(L, 'f', 4);
    OutputSqList(L);
    ListDelete(L, 3);
    OutputSqList(L);
    DestroyList(L);
    // Test after destruction
    ListInsertAtEnd(L, 'a');
    return 0;
}