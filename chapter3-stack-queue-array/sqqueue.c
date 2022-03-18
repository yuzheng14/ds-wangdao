#include "sqqueue.h"

bool InitQueue(SqQueue *Q)
{
    Q->font = 0;
    Q->rear = 0;
    return true;
}