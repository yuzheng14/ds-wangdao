#include <stdio.h>
#include <stdbool.h>

#if !defined SQLIST_H
#define SQLIST_H

#define MaxSize 50

typedef int ElemType;

typedef struct
{
    ElemType data[MaxSize];
    int length;
} SqList;

void InitList(SqList *L);
bool ListInsert(SqList *L, int i, ElemType e);
bool ListDelete(SqList *L, int i, ElemType *e);
bool GetElem(SqList L, int i, ElemType *e);
bool LocateElem(SqList L,int *i, ElemType e);

#endif