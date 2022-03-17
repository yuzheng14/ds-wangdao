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