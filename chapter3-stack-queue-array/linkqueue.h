#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#if !defined LINK_QUEUE_H
#define LINK_QUEUE_H

#if !defined ELEMTYPE
#define ELEMTYPE
typedef int ElemType;
#endif

#if !defined LINK_NODE
#define LINK_NODE
typedef struct LinkNode
{
    ElemType data;
    struct LinkNode *next;
} LinkNode;
#endif

#if !defined LINK_QUEUE
#define LINK_QUEUE
typedef struct
{
    LinkNode *front, *rear;
} LinkQueue;
#endif

bool InitQueue(LinkQueue *Q);
bool EnQueue(LinkQueue *Q, ElemType e);
bool QueueEmpty(LinkQueue Q);
bool DeQueue(LinkQueue *Q, ElemType *e);
// TODO 获取队头元素

#endif