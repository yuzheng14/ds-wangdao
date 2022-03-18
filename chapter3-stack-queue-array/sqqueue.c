#include "sqqueue.h"

bool InitQueue(SqQueue *Q)
{
    Q->font = Q->rear = 0;
    return true;
}

bool QueueEmpty(SqQueue Q)
{
    return Q.font == Q.rear;
}

bool EnQueue(SqQueue *Q, ElemType e)
{
    if (!Q || (Q->rear + 1) % MaxSize == Q->font)
        return false;
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MaxSize;
    return true;
}

bool DeQueue(SqQueue *Q, ElemType *e)
{
    if (!Q || QueueEmpty(*Q))
        return false;
    if (e)
        *e = Q->data[Q->font];
    Q->font = (Q->font + 1) % MaxSize;
    return true;
}

bool GetHead(SqQueue Q, ElemType *e)
{
    if (QueueEmpty(Q))
        return false;
    if (e)
        *e = Q.data[Q.rear];
    return true;
}

int main(void)
{
    SqQueue Q;
    InitQueue(&Q);
    EnQueue(&Q, 1);
    EnQueue(&Q, 2);
    EnQueue(&Q, 3);
    EnQueue(&Q, 4);
    EnQueue(&Q, 5);
    EnQueue(&Q, 6);
    EnQueue(&Q, 7);
    EnQueue(&Q, 8);
    EnQueue(&Q, 9);
    EnQueue(&Q, 10);
    int e;
    while (!QueueEmpty(Q))
    {
        DeQueue(&Q, &e);
        printf("%-3d", e);
    }
    putchar('\n');
    return 0;
}