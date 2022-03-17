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
    return S->next == NULL || !S;
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

bool Pop(LiStack *S, ElemType *e)
{
    if (StackEmpty(*S))
        return false;
    if (e)
        *e = (*S)->next->data;
    (*S)->next = (*S)->next->next;
    return true;
}

bool GetTop(LiStack S, ElemType *e)
{
    if (StackEmpty(S))
        return false;
    if (e)
        *e = S->next->data;
    return true;
}

int main(void)
{
    LiStack S;
    InitStack(&S);
    if (StackEmpty(S))
        puts("当前栈为空");
    else
        puts("当前栈不为空");
    Push(&S, 1);
    Push(&S, 2);
    Push(&S, 3);
    Push(&S, 4);
    Push(&S, 5);
    Push(&S, 6);
    int e;
    while (!StackEmpty(S))
    {
        Pop(&S, &e);
        printf("%-3d", e);
    }
    putchar('\n');
    return 0;
}