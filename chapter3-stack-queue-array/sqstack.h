#include <stdio.h>
#include <stdbool.h>

#if !defined SQSTACK_H
#define SQSTACK_H

#if !defined ELEMTYPE
#define ELEMTYPE
typedef int ElemType;
#endif

#if defined MaxSize
#undef MaxSize
#endif

#define MaxSize 10

#if !defined SQSTACK
#define SQSTACK
typedef struct
{
    ElemType data[MaxSize];
    int top;
} SqStack;
#endif

bool InitStack(SqStack *S);
bool StackEmpty(SqStack S);
bool Push(SqStack *S, ElemType e);
bool Pop(SqStack *S, ElemType *e);

#endif