#include "linkqueue.h"

bool InitQueue(LinkQueue *Q)
{
    Q->rear = Q->front = (LinkNode *)malloc(sizeof(LinkNode));
    if (!Q)
        return false;
    Q->front->next = NULL;
    return true;
}

bool EnQueue(LinkQueue *Q, ElemType e)
{
    if (!Q)
        return false;
    LinkNode *new_node = (LinkNode *)malloc(sizeof(LinkNode));
    if (!new_node)
        return false;
    new_node->data = e;
    new_node->next = NULL;
    Q->rear->next = new_node;
    return true;
}

bool QueueEmpty(LinkQueue Q)
{
    return Q.front==Q.rear;
}