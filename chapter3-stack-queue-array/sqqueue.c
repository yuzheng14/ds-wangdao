#include "sqqueue.h"

bool InitQueue(SqQueue *Q)
{
    Q->font = 0;
    Q->rear = 0;
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
    Q->data[Q->rear++] = e;
    return true;
}

bool DeQueue(SqQueue *Q, ElemType *e)
{
    if (!Q || QueueEmpty(*Q))
        return false;
    if (e)
        *e = Q->data[Q->rear];
    Q->rear--;
    return true;
}

bool GetHead(SqQueue Q, ElemType *e)
{
    if (!Q || QueueEmpty(Q))
        return false;
    if (e)
        *e = Q.data[Q.rear];
    return true;
}