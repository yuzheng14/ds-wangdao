#include <stdio.h>
#include <stdlib.h>

#include "chapter2-linear-list/linklist.h"

int main(void)
{
    LinkList L;
    InitList(&L);
    ListInsert(&L, 1, 1);
    ListInsert(&L, 2, 2);
    ListInsert(&L, 4, 3);
    PrintList(L);
    LNode *p;
    if (LocateElem(L, 2, &p))
        printf("get successfully! the value is %d.\n", p->data);
    else
        puts("error occurs!");
    if (LocateElem(L, 3, &p))
        printf("get successfully! the value is %d.\n", p->data);
    else
        puts("error occurs!");
    return 0;
}