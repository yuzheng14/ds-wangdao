#include "linkqueue.h"

bool InitQueue(LinkQueue *Q)
{
    Q->rear = Q->front = (LinkNode *)malloc(sizeof(LinkNode));
    if (!Q)
        return false;
    Q->front->next = NULL;
    return true;
}
