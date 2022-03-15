#include <stdio.h>

#if !defined SEQLIST_H
#define SEQLIST_H

#define InitSize 10

typedef int ElemType;

typedef struct
{
    ElemType *data;
    int MaxSize;
    int length;
} SeqList;

void InitList(SeqList *L);

void IncreaseList(SeqList *L, int len);

#endif