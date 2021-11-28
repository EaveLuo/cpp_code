#include <iostream>
using namespace std;
typedef char ElemType;

typedef struct BNode
{
    ElemType data;
    struct BNode *lchild, *rchild;
} BinNode, *BinTree;

// Create the tree
void CreateBinTree(BinTree &T, char *str)
{
    BinNode *St[100], *p = NULL;
    int top = -1, k, j = 0;
    char ch;
    T = NULL;
    ch = str[j];
    while (ch != '\0')
    {
        switch (ch)
        {
        case '(':
            top++;
            St[top] = p;
            k = 1;
            break;
        case ')':
            top--;
            break;
        case ',':
            k = 2;
            break;
        default:
            p = new BinNode;
            p->data = ch;
            p->lchild = p->rchild = NULL;
            if (T == NULL)
                T = p;
            else
            {
                switch (k)
                {
                case 1:
                    St[top]->lchild = p;
                    break;
                case 2:
                    St[top]->rchild = p;
                    break;
                }
            }
        }
        j++;
        ch = str[j];
    }
}

// Destroy the tree
void DestroyBinTree(BinTree &T)
{
    if (T != NULL)
    {
        DestroyBinTree(T->lchild);
        DestroyBinTree(T->rchild);
        delete (T);
    }
}

// PreOrder print the tree
void PreOrder(BinTree T, int &num)
{
    if (T != NULL)
    {
        num++;
        cout << T->data << " ";
        PreOrder(T->lchild, num);
        PreOrder(T->rchild, num);
    }
}

// InOrder print the tree
void InOrder(BinTree T, int &num)
{
    if (T != NULL)
    {
        if (T->lchild == NULL && T->rchild == NULL)
        {
            num++;
        }
        InOrder(T->lchild, num);
        cout << T->data << " ";
        InOrder(T->rchild, num);
    }
}

// Count the BinTree's node that using PreOrder
int CountBinTreeNode(BinTree T)
{
    int num = 0;
    PreOrder(T, num);
    return num;
}

// Count the BinTree's leafNode that using InOrder
int CountBinTreeLeafNode(BinTree T)
{
    int num = 0;
    InOrder(T, num);
    return num;
}

// Get the element x's level
int Level(BinTree T, ElemType x, int h = 1) // Initialize h's value: 1
{
    int l;
    if (T == NULL)
        return (0);
    else if (T->data == x)
        return (h);
    else
    {
        l = Level(T->lchild, x, h + 1); // Find x in lchild
        if (l != 0)
            return (l);
        else // No lchild,just find in rchild
            return (Level(T->rchild, x, h + 1));
    }
}

// Get BinTree's width by travelOrder
int BinTreeWidth(BinTree T)
{
    struct
    {
        int lno;
        BinTree p;
    } Qu[100];
    int front, rear;
    int lnum, max, i, n;
    front = rear = 0;
    if (T != NULL)
    {
        rear++;
        Qu[rear].p = T;
        Qu[rear].lno = 1;
        while (rear != front)
        {
            front++;
            T = Qu[front].p;
            lnum = Qu[front].lno;
            if (T->lchild != NULL)
            {
                rear++;
                Qu[rear].p = T->lchild;
                Qu[rear].lno = lnum + 1;
            }
            if (T->rchild != NULL)
            {
                rear++;
                Qu[rear].p = T->rchild;
                Qu[rear].lno = lnum + 1;
            }
        }
        max = 0;
        lnum = 1;
        i = 1;
        while (i <= rear)
        {
            n = 0;
            while (i <= rear && Qu[i].lno == lnum)
            {
                n++;
                i++;
            }
            lnum = Qu[i].lno;
            if (n > max)
                max = n;
        }
        return max;
    }
    else
        return 0;
}

int main()
{
    BinTree T;
    char str[] = "A(B(D,E(H(J,K(L,M(,N))),)),C(F,G(,I)))";
    CreateBinTree(T, str);
    cout << "BinTree's node number is: "
         << CountBinTreeNode(T) << endl; // (1)
    cout << "BinTree's leafNode number is:  "
         << CountBinTreeLeafNode(T) << endl; // (2)
    cout << "The element \'N\' in BinTree's level is: "
         << Level(T, 'N') << endl; // (3)
    cout << "BinTree's width is: "
         << BinTreeWidth(T) << endl; // (4)
    DestroyBinTree(T);
    return 0;
}