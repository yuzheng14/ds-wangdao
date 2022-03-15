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
        if (e)
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

bool LocateElem(LinkList L, ElemType e, LNode **p)
{
    if (!L)
        return false;
    LNode *current_node = L;
    while (current_node->next && current_node->next->data != e)
        current_node = current_node->next;
    if (current_node->next && current_node->next->data == e)
    {
        *p = current_node->next;
        return true;
    }
    else
        return false;
}

int Length(LinkList L)
{
    if (!L)
        return 0;
    LNode *current = L;
    int len = 0;
    while (++len && current->next)
        current = current->next;
    return len - 1;
}

bool ListTailInsert(LinkList *L)
{
    ElemType e;
    InitList(L);
    LNode *tail = *L;
    while (scanf("%d", &e) != EOF)
    {
        tail->next = (LNode *)malloc(sizeof(LNode));
        tail = tail->next;
        tail->data = e;
    }
    tail->next = NULL;
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