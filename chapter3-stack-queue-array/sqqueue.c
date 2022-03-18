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