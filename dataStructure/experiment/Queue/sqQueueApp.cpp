#include <iostream>
using namespace std;

typedef char ElemType;
typedef struct
{
    ElemType *data;
    int front, rear, maxSize;
} QueQue, *SqQueQue;

// initialize queque
void InitQueue(SqQueQue &Q, int initSize)
{
    Q = new QueQue;
    Q->data = new ElemType[initSize];
    Q->front = Q->rear = 0;
    Q->maxSize = initSize;
}

// is Queue empty?
bool IsQueueEmpty(SqQueQue Q)
{
    return Q->front == Q->rear ? true : false;
}

// input a element in queue
void EnQueue(SqQueQue &Q, ElemType e)
{
    if ((Q->rear + 1) % Q->maxSize != Q->front)
    {
        Q->rear = (Q->rear + 1) % Q->maxSize;
        Q->data[Q->rear] = e;
    }
    else
    {
        cout << "Enqueue faild,the queue is full" << endl;
    }
}

// output a element from queue
void DeQueue(SqQueQue &Q)
{
    if (!IsQueueEmpty(Q))
    {
        Q->front = ++Q->front % Q->maxSize;
        cout << "DeQueue,the output element is:" << Q->data[Q->front] << endl;
    }
    else
    {
        cout << "Dequeue faild,the Queue is empty." << endl;
    }
}

// destroy the queue
void DestroyQueue(SqQueQue &Q)
{
    delete[](Q->data);
    delete (Q);
}

// if enter a number just enqueue,
// and if enter a lowercase letters just dequeue,
// anyone else just return this function
void ExamApp(SqQueQue &Q)
{
    char input;
    while (true)
    {
        cout << "please enter a char:";
        cin >> input;
        if (input >= 'a' && input <= 'z')
        {
            DeQueue(Q);
        }
        else if (input >= '0' && input <= '9')
        {
            EnQueue(Q, input);
        }
        else
        {
            cout << "----------end----------" << endl;
            break;
        }
    }
}

int main()
{
    SqQueQue Q;
    InitQueue(Q, 100);
    if (IsQueueEmpty(Q))
    {
        cout << "the queue is empty" << endl;
    }
    ExamApp(Q);
    DestroyQueue(Q);
    return 0;
}