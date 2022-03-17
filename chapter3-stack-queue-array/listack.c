#include "listack.h"

bool InitStack(LiStack *S)
{
    *S = (LinkNode *)malloc(sizeof(LinkNode));
    if (!S)
        return false;
    (*S)->next = NULL;
    return true;
}

bool StackEmpty(LiStack S)
{
    if (!S)
        return false;
    return S->next == NULL;
}

bool Push(LiStack *S, ElemType e)
{
    if (!(*S))
        return false;
    LinkNode *new = (LinkNode *)malloc(sizeof(LinkNode));
    new->data = e;
    new->next = (*S)->next;
    (*S)->next = new;
    return true;
}