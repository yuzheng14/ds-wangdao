#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#if !defined LINKLIST_H
#define LINKLIST_H

typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

bool InitList(LinkList *L);
bool Empty(LinkList L);
bool ListInsert(LinkList *L, int i, ElemType e);
void PrintList(LinkList L);
bool InsertNextNode(LNode *p, ElemType e);
bool InsertPriorNode(LNode *p, ElemType e);
bool ListDelete(LinkList *L,int i, ElemType *e);
bool DeleteNode(LNode *p);
bool GetElem(LinkList L, int i, LNode **p);
bool LocateElem(LinkList L, ElemType e, LNode **p);

#endif