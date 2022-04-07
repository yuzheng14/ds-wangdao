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

bool ListTailInsert(LinkList *L);
void PrintList(LinkList L);
bool GetElem(LinkList L, int i, LNode **p);
bool ListInsert(LinkList *L, int i, ElemType e);
bool ListDelete(LinkList *L,int i, ElemType *e);
bool InitList(LinkList *L);

#endif

void PrintList(LinkList L)
{
    L = L->next;
    while (L != NULL)
    {
        printf("%3d", L->data); //打印当前结点数据
        L = L->next;            //指向下一个结点
    }
    printf("\n");
}

bool ListTailInsert(LinkList *L)
{
    ElemType e;
    InitList(L);
    LNode *tail=*L;
  	scanf("%d",&e);
    while(e!=9999)
    {
        tail->next=(LNode *)malloc(sizeof(LNode));
        tail=tail->next;
        tail->data=e;
      	scanf("%d",&e);
    }
    tail->next=NULL;
    return true;
}
bool GetElem(LinkList L, int i, LNode **p)
{
    if (!L || i < 0)
        return false;
    int j = 0;
    LNode *current_node = L;
    while (++j < i && current_node->next)
        current_node = current_node->next;
    if (j == i && current_node->next)
    {
        (*p) = current_node->next;
        return true;
    }
    else
        return false;
}
bool ListInsert(LinkList *L, int i, ElemType e)
{
    if (i < 1)
        return false;
    int j = 0;
    LNode *current_node = *L;
    while (++j < i && current_node->next)
        current_node = current_node->next;
    if (j == i)
    {
        LNode *new_node = (LNode *)malloc(sizeof(LNode));
        new_node->data = e;
        new_node->next = current_node->next;
        current_node->next = new_node;
        return true;
    }
    else
        return false;
}
bool ListDelete(LinkList *L, int i, ElemType *e)
{
    if (i < 1 || !(*L))
        return false;
    LNode *current_node = (*L);
    int j = 0;
    while (++j < i && current_node->next)
        current_node = current_node->next;
    if (j == i && current_node->next)
    {
        LNode *temp = current_node->next;
      	if(e)
        	*e = temp->data;
        current_node->next = temp->next;
        free(temp);
        return true;
    }
    else
        return false;
}
bool InitList(LinkList *L)
{
    *L = (LNode *)malloc(sizeof(LNode));
    if (*L == NULL)
        return false;
    (*L)->next = NULL;
    return true;
}

int main(void)
{
    LinkList L;
    ListTailInsert(&L);
    LNode *p;
    GetElem(L, 2, &p);
    printf("%d\n", p->data);
    ListInsert(&L, 2, 99);
    PrintList(L);
    ListDelete(&L, 4, NULL);
    PrintList(L);
}