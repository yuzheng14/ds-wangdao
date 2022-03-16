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