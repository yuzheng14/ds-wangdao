#include "seqlist.h"
#include <stdlib.h>

void InitList(SeqList *L)
{
    L->data = (ElemType *)malloc(sizeof(ElemType) * InitSize);
    L->MaxSize = InitSize;
    int i;
    for (i = 0; i < L->MaxSize; i++)
        L->data[i] = 0;
    L->length = 0;
}

void IncreaseList(SeqList *L, int len)
{
    ElemType *temp = L->data;
    L->data = (ElemType *)malloc(sizeof(ElemType) * (L->MaxSize + len));
    int i;
    for (i = 0; i < L->length; i++)
        L->data[i] = temp[i];
    L->MaxSize = L->MaxSize + len;
    // 可选for循环
    for (; i < L->MaxSize; i++)
        L->data[i] = 0;
    free(temp);
}