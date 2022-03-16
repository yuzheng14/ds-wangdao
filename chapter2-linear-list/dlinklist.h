#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#if !defined DLINKLIST_H
#define DLINKLIST_H

#if !defined ELEMTYPE
#define ELEMTYPE
typedef int ElemType;
#endif

typedef struct DNode
{
    ElemType data;
    struct DNode *next, *piror;
} DNode, *DLinklist;

bool InitDLinkList(DLinklist *L);
bool Empty(DLinklist L);
bool InsertNextNode(DNode *p, DNode *s);
bool DeleteNextNode(DNode *p);

#endif