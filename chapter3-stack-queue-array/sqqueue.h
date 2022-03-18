#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#if !defined SQ_QUEUE_H
#define SQ_QUEUE_H

#if !defined ELEMTYPE
#define ELEMTYPE
typedef int ElemType;
#endif

#ifdef MaxSize
#undef MaxSize
#endif
#define MaxSize 10

#if !defined SQ_QUEUE
#define SQ_QUEUE
typedef struct
{
    ElemType data[MaxSize];
    int font, rear;
} SqQueue;
#endif

bool InitQueue(SqQueue *Q);
bool QueueEmpty(SqQueue Q);
bool EnQueue(SqQueue *Q, ElemType e);

#endif