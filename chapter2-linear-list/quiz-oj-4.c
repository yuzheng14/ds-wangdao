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
#endif

bool InitList(LinkList *L)
{
    *L = (LNode *)malloc(sizeof(LNode));
    if (*L == NULL)
        return false;
    (*L)->next = NULL;
    return true;
}
bool ListTailInsert(LinkList *L)
{
    ElemType e;
    InitList(L);
    LNode *tail = *L;
  	scanf("%d", &e);
    while ( e!= 9999)
    {
        tail->next = (LNode *)malloc(sizeof(LNode));
        tail = tail->next;
        tail->data = e;
      	scanf("%d", &e);
    }
    tail->next = NULL;
    return true;
}

bool ListHeadInsert(LinkList *L)
{
    ElemType e;
    InitList(L);
  	scanf("%d", &e);
    while(e!=9999)
    {
        LNode *new=(LNode *)malloc(sizeof(LNode));
        new->data=e;
        new->next=(*L)->next;
        (*L)->next=new;
      	scanf("%d", &e);
    }
    return true;
}

void PrintList(LinkList L)

{

L=L->next;

while(L!=NULL)

{

printf("%d",L->data);//打印当前结点数据

L=L->next;//指向下一个结点

if(L!=NULL)

{

printf(" ");

}

}

printf("\n");

}

int main(void)
{
    LinkList L;
    ListHeadInsert(&L);
    PrintList(L);
    ListTailInsert(&L);
    PrintList(L);
    return 0;
}