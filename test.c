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
    printf("Length of List is %d\n", Length(L));
    printf("Length of null is %d\n", Length(NULL));
    printf("Length of null list is %d\n", Length((LinkList)malloc(sizeof(LNode))));
    return 0;
}