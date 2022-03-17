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
bool LocateElem(SqList L, int *i, ElemType e);

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
    if (e)
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
            *i = j + 1;
            return true;
        }
    }
    return false;
}

#endif

void printList(SqList L);

int main(void)
{
    SqList L;
    InitList(&L);
    ListInsert(&L, 1, 1);
    ListInsert(&L, 2, 2);
    ListInsert(&L, 3, 3);
    int auxiliary;
    if (scanf("%d", &auxiliary) != EOF)
        ListInsert(&L, 2, auxiliary);
    printList(L);
    if (scanf("%d", &auxiliary) != EOF)
    {
        if (ListDelete(&L, auxiliary, NULL))
            printList(L);
        else
        {
            puts("false");
        }
    }
    return 0;
}

void printList(SqList L)
{
    int i;
    for (i = 0; i < L.length; i++)
        printf("%3d", L.data[i]);
    putchar('\n');
}