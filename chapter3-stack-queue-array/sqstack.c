#include "sqstack.h"

bool InitStack(SqStack *S)
{
    S->top = -1;
    return true;
}

bool StackEmpty(SqStack S)
{
    return S.top == -1;
}

bool Push(SqStack *S, ElemType e)
{
    if (S->top == MaxSize - 1)
        return false;
    S->data[++(S->top)] = e;
    return true;
}

bool Pop(SqStack *S, ElemType *e)
{
    if (StackEmpty(*S))
        return false;
    if (e)
        *e = S->data[S->top];
    S->top--;
    return true;
}

int main(void)
{
    SqStack S;
    InitStack(&S);
    Push(&S, 1);
    printf("top:%d\ndata:%d\n", S.top, S.data[S.top]);
    Pop(&S,NULL);
    printf("top:%d\n",S.top);
    Push(&S, 2);
    int e;
    Pop(&S,&e);
    printf("top:%d\n",S.top);
    return 0;
}