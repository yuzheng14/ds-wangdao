#include "linkqueue.h"

bool InitQueue(LinkQueue *Q)
{
    Q->rear = Q->front = (LinkNode *)malloc(sizeof(LinkNode));
    if (!Q->front)
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
    Q->rear = new_node;
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

int main(void)
{
    LinkQueue Q;
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
    printf("%d\n", GetHead(Q, NULL));
    int e;
    printf("%d\n", GetHead(Q, &e));
    while (!QueueEmpty(Q))
    {
        DeQueue(&Q, &e);
        printf("%-3d", e);
    }
    putchar('\n');
    return 0;
}