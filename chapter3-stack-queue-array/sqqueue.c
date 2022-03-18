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