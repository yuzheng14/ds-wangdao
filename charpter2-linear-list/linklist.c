#include "linklist.h"

bool InitList(LinkList *L)
{
    *L = (LNode *)malloc(sizeof(LNode));
    if (*L == NULL)
        return false;
    (*L)->next = NULL;
    return true;
}

bool Empty(LinkList L)
{
    return L->next == NULL;
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
        // LNode *new_node = (LNode *)malloc(sizeof(LNode));
        // new_node->data = e;
        // new_node->next = current_node->next;
        // current_node->next = new_node;
        // return true;
        return InsertNextNode(current_node, e);
    }
    else
        return false;
}

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

bool InsertNextNode(LNode *p, ElemType e)
{
    if (!p)
        return false;
    LNode *new_node = (LNode *)malloc(sizeof(LNode));
    if (!new_node)
        return false;
    new_node->data = e;
    new_node->next = p->next;
    p->next = new_node;
    return true;
}

// 时间复杂度为 O(n)
// bool InsertPriorNode(LinkList L, LNode *p, ElemType e)
// {
//     if (!p)
//         return false;
//     LNode *current_node = L;
//     while (current_node->next && current_node->next != p)
//         ;
//     if (current_node->next == p)
//     {
//         InsertNextNode(p, e);
//         return true;
//     }
//     else
//         return false;
// }

bool InsertPriorNode(LNode *p, ElemType e)
{
    if (!p)
        return false;
    LNode *new_node = (LNode *)malloc(sizeof(LNode));
    if (!new_node)
        return false;
    new_node->next = p->next;
    new_node->data = p->data;
    p->next = new_node;
    p->data = e;
    return true;
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
        *e = temp->data;
        current_node->next = temp->next;
        free(temp);
        return true;
    }
    else
        return false;
}

bool DeleteNode(LNode *p)
{
    if (!p)
        return false;
    LNode *temp = p->next;
    p->data = temp->data;
    p->next = temp->next;
    free(temp);
    return true;
}

bool GetElem(LinkList L, int i, LNode **p)
{
    if (!L)
        return false;
    int j = 0;
    LNode *current_node = L;
    while (++j < i && current_node->next)
        current_node = current_node->next;
    if (j == i && current_node->next)
    {
// #define debug
#if defined debug
        printf("i:%d\np:%p\ncurrent_node->next:%p\n", i, p, current_node->next);
#endif
        (*p) = current_node->next;
#if defined debug
        printf("i:%d\np:%p\ncurrent_node->next:%p\n", i, p, current_node->next);
#endif
        return true;
    }
    else
        return false;
}