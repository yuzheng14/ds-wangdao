#include "dlinklist.h"

bool InitDLinkList(DLinklist *L)
{
    (*L) = (DNode *)malloc(sizeof(DNode));
    if (!(*L))
        return false;
    (*L)->next = NULL;
    (*L)->piror = NULL;
    return true;
}

bool Empty(DLinklist L)
{
    return L->next == NULL;
}

bool InsertNextNode(DNode *p, DNode *s)
{
    if (!p || !s)
        return false;
    s->next = p->next;
    if (p->next)
        p->next->piror = s;
    p->next = s;
    s->piror = p;
    return true;
}

bool DeleteNextNode(DNode *p)
{
    if (!p||!p->next)
        return false;
    DNode *next_node=p->next;
    p->next = next_node->next;
    if (next_node->next)
        next_node->next->piror = p;
    free(p);
    return true;
}