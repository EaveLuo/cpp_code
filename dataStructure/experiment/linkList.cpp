#include <iostream>
using namespace std;

typedef char ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LinkNode, *LinkList;

// Initialize LinkList
void InitList(LinkList &L)
{
    L = new LinkNode;
    L->next = NULL;
}

// Insert using tail interpolation
void ListInsertAtEnd(LinkList &L, ElemType e)
{
    // Create a Node;p:temporary pointer
    LinkList insertNode = new LinkNode;
    insertNode->data = e;
    insertNode->next = NULL;
    LinkList p = L;
    while (p->next)
    {
        p = p->next;
    }
    p->next = insertNode;
}

// Is LinkList Empty?
bool IsLinkListEmpty(LinkList L)
{
    if (L->next == NULL)
    {
        return true;
    }
    return false;
}

// Output LinkList
void OutputLinkList(LinkList L)
{
    if (IsLinkListEmpty(L))
    {
        cout << "the LinkList is empty" << endl;
        return;
    }
    cout << "Output LinkList:";
    L = L->next;
    while (L)
    {
        cout << L->data << " ";
        L = L->next;
    }
    cout << endl;
}

// Count the list length
int ListLength(LinkList L)
{
    // Because there is a HeadNode in LinkList,so start on 0
    int length = 0;
    L = L->next;
    while (L)
    {
        L = L->next;
        length++;
    }
    return length;
}

// Output LinkList by location
void OutputLinkListByLocate(LinkList L, int location)
{
    if (IsLinkListEmpty(L))
    {
        cout << "the LinkList is empty" << endl;
        return;
    }
    if (location > ListLength(L) || location <= 0)
    {
        cout << "the location is illegal" << endl;
        return;
    }
    for (int i = 1; i <= location; i++)
    {
        L = L->next;
    }
    cout << "Output the " << location
         << " element is :" << L->data << endl;
}

// Locate the element
void LocateElem(LinkList L, ElemType e)
{
    int location = 1;
    if (IsLinkListEmpty(L))
    {
        cout << "the LinkList is empty" << endl;
        return;
    }
    L = L->next;
    while (L)
    {
        if (L->data == e)
        {
            break;
        }
        L = L->next;
        location++;
    }

    if (!L)
    {
        cout << "don't find "
             << "the element " << e << endl;
    }
    else
    {
        cout << "the element " << e << " located in " << location << endl;
    }
}

// Insert element
void ListInsert(LinkList &L, ElemType e, int location)
{
    if (location > ListLength(L) + 1 || location <= 0)
    {
        cout << "insert failed,the location \'"
             << location << "\' is illegal" << endl;
        return;
    }
    LinkList insertNode = new LinkNode;
    insertNode->data = e;
    LinkList p = L;
    for (int i = 1; i < location; i++)
    {
        p = p->next;
    }
    insertNode->next = p->next;
    p->next = insertNode;
}

// Delete element
void ListDelete(LinkList &L, int location)
{
    if (location > ListLength(L) || location <= 0)
    {
        cout << "delete failed,the location \'"
             << location << "\' is illegal" << endl;
        return;
    }
    LinkList p = L, tempNode;
    for (int i = 1; i < location; i++)
    {
        p = p->next;
    }
    tempNode = p->next;
    p->next = tempNode->next;
    delete (tempNode);
}

// Destroy LinkList
void DestroyList(LinkList &L)
{
    LinkList pre = L, p = L->next;
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
    LinkList L;
    InitList(L);
    ListInsertAtEnd(L, 'a');
    ListInsertAtEnd(L, 'b');
    ListInsertAtEnd(L, 'c');
    ListInsertAtEnd(L, 'd');
    OutputLinkList(L);
    int length = ListLength(L);
    cout << "the LinkList L's length is:" << length << endl;
    OutputLinkListByLocate(L, 4);
    LocateElem(L, 'a');
    ListInsert(L, 'f', 4);
    OutputLinkList(L);
    ListDelete(L, 3);
    OutputLinkList(L);
    DestroyList(L);
    return 0;
}