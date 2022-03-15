#include "sqlist.h"

void InitList(SqList *L)
{
    int i;
    // for循环可以省略
    for (i = 0; i < L->length; i++)
        L->data[i] = 0;
    L->length = 0;
}

bool ListInsert(SqList *L, int i, ElemType e)
{
    if (i < 1 || i > L->length + 1 || L->length >= MaxSize)
        return false;
    int j;
    for (j = L->length; j > i - 1; j--)
        L->data[j] = L->data[j - 1];
    L->data[i - 1] = e;
    L->length++;
    return true;
}

bool ListDelete(SqList *L, int i, ElemType *e)
{
    if (i < 1 || i > L->length)
        return false;
    int j;
    *e = L->data[i - 1];
    for (j = i; j < L->length; j++)
        L->data[j - 1] = L->data[j];
    L->length--;
    return true;
}

bool GetElem(SqList L, int i, ElemType *e)
{
    if (i > L.length)
        return false;
    else
        *e = L.data[i - 1];
    return true;
}

bool LocateElem(SqList L, int *i, ElemType e)
{
    *i = 0;
    int j;
    for (j = 0; j < L.length; j++)
    {
        if (L.data[j] == e)
        {
            *i = j+1;
            return true;
        }
    }
    return false;
}