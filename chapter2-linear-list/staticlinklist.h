#include <stdio.h>

#if !defined STATICLINKLIST_H
#define STATICLINKLIST_H

#if !defined ELEMTYPE
#define ELEMTYPE
typedef int ElemType;
#endif

#if !defined MAXSIZE
#define MAXSIZE 100
#endif

typedef struct SNode{
    ElemType data;
    int next;
} SNode, SLinkList[MAXSIZE];

#endif