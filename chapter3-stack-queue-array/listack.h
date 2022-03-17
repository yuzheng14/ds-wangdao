#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#if !defined LISTACK_H
#define LISTACK_H

#if !defined ELEMTYPE
#define ELEMTYPE
typedef int ElemType;
#endif

#define MaxSize 10

#if !defined LISTACK && !defined LINKNODE
#define LISTACK
typedef struct LinkNode
{
    ElemType data;
    struct LinkNode *next;
} LinkNode,*LiStack;
#endif

bool InitStack(LiStack *S);
bool StackEmpty(LiStack S);
bool Push(LiStack *S,ElemType e);

#endif