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
    return Q.front == Q.rear;
}

bool DeQueue(LinkQueue *Q, ElemType *e)
{
    if (!Q || QueueEmpty(*Q))
        return false;
    LinkNode *current = Q->front->next;
    if (e)
        *e = current->data;
    Q->front->next = current->next;
    // 如果要删除的结点是最后一个结点则需要单独处理
    if (Q->rear == current)
        Q->rear = Q->front;
    free(current);
    return true;
}

bool GetHead(LinkQueue Q, ElemType *e)
{
    if (QueueEmpty(Q) || !e)
        return false;
    *e = Q.front->next->data;
    return true;
}