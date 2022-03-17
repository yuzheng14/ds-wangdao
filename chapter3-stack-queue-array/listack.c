#include "listack.h"

bool InitStack(LiStack *S)
{
    (*S) = NULL;
    return true;
}

bool StackEmpty(LiStack S)
{
    return S == NULL;
}

bool Push(LiStack *S, ElemType e)
{
    LinkNode *new = (LinkNode *)malloc(sizeof(LinkNode));
    if(!new)
        return false;
    new->data = e;
    new->next = (*S);
    (*S) = new;
    return true;
}

bool Pop(LiStack *S, ElemType *e)
{
    if (StackEmpty(*S))
        return false;
    if (e)
        *e = (*S)->data;
    LinkNode *current = (*S);
    (*S) = current->next;
    free(current);
    return true;
}

bool GetTop(LiStack S, ElemType *e)
{
    if (StackEmpty(S))
        return false;
    if (e)
        *e = S->data;
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