// 10.17's work，in p61 2.4 experiment
#include <iostream>
using namespace std;
#define ElemType int

#define MaxCol 10

// line node structure
typedef struct DNode
{
    ElemType data[MaxCol];
    struct DNode *next;
} DList;

// head node structure
typedef struct HNode
{
    int Row, Col;
    DList *next;
} HList;

// create table with cross methods
void createTable(HList *&h)
{
    // create head node
    h = (HList *)malloc(sizeof(HList));
    cout << "please enter the table's row and column:";
    cin >> h->Row >> h->Col;
    // input table's data
    for (int i = 0; i < h->Row; i++)
    {
        cout << "the " << i + 1 << " row:";
        // create data node and rear node
        DList *s = (DList *)malloc(sizeof(DList)), *r;
        // input column's data
        for (int j = 0; j < h->Col; j++)
        {
            cin >> s->data[j];
            if (h->next == NULL)
            {
                h->next = s;
            }
            else
            {
                r->next = s;
            }
            r = s;
        }
        r->next = NULL;
    }
}

// destroy the table
void destroyTable(HList *&h)
{
    // set pre is head node,p is pre's next node
    DList *pre = h->next, *p = pre->next;
    // free table's nodes
    while (p != NULL)
    {
        free(pre);
        pre = p;
        p = p->next;
    }
    free(pre);
    free(p);
}

// display the table
void dispTable(HList *h)
{
    DList *p = h->next;
    while (p != NULL)
    {
        for (int i = 0; i < h->Col; i++)
        {
            cout << p->data[i] << " ";
        }
        cout << endl;
        p = p->next;
    }
    free(p);
}

// link the table
void linkTable(HList *h1, HList *h2, HList *&h)
{
    DList *p = h1->next, *q, *s, *r;
    int i, j;
    cout << "linked column is:the 1st table's column,the 2nd table's column:";
    cin >> i >> j;
    // initial the new table h
    h = (HList *)malloc(sizeof(HList));
    h->Row = 0;
    h->Col = h1->Col + h2->Col;
    h->next = NULL;
    // link the table
    while (p != NULL)
    {
        q = h2->next;
        while (q != NULL)
        {
            if (p->data[i - 1] == q->data[j - 1])
            {
                s = (DList *)malloc(sizeof(DList));
                for (int k = 0; k < h1->Col; k++)
                {
                    s->data[k] = p->data[k];
                }
                for (int k = 0; k < h2->Col; k++)
                {
                    s->data[h1->Col + k] = q->data[k];
                }

                // there's theory same in create table
                if (h->next == NULL)
                {
                    h->next = s;
                }
                else
                {
                    r->next = s;
                }
                r = s;
                h->Row++;
            }
            q = q->next;
        }
        p = p->next;
    }
    r->next = NULL;
}

int main()
{
    HList *h1, *h2, *h;
    cout << "table 1:" << endl;
    createTable(h1);
    cout << "table 2:" << endl;
    createTable(h2);
    linkTable(h1, h2, h);
    cout << "the linked result is:" << endl;
    dispTable(h);
    destroyTable(h1);
    destroyTable(h2);
    destroyTable(h);
    return 0;
}