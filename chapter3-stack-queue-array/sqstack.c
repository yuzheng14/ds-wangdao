#include "sqstack.h"

bool InitStack(SqStack *S)
{
    S->top=-1;
    return true;
}

bool StackEmpty(SqStack S)
{
    return S.top==-1;
}

bool Push(SqStack *S, ElemType e)
{
    if(S->top==MaxSize)
        return false;
    S->data[++(S->top)]=e;
    return true;
}