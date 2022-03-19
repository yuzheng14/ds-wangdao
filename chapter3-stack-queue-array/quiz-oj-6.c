#include <stdio.h>
#include <stdbool.h>

typedef int ElemType;
#define MaxSize 5
typedef struct
{
    ElemType data[MaxSize];
    int top;
} SqStack;

typedef struct
{
    ElemType data[MaxSize];
    int font, rear;
} SqQueue;

bool InitQueue(SqQueue *Q);
bool QueueEmpty(SqQueue Q);
bool EnQueue(SqQueue *Q, ElemType e);
bool DeQueue(SqQueue *Q, ElemType *e);
bool GetHead(SqQueue Q, ElemType *e);

bool InitStack(SqStack *S);
bool StackEmpty(SqStack S);
bool Push(SqStack *S, ElemType e);
bool Pop(SqStack *S, ElemType *e);
bool GetTop(SqStack S, ElemType *e);


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
    if (!S || S->top == MaxSize - 1)
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

bool GetTop(SqStack S, ElemType *e)
{
    if (StackEmpty(S))
        return false;
    if (e)
        *e = S.data[S.top];
    return true;
}

bool InitQueue(SqQueue *Q)
{
    Q->font = Q->rear = 0;
    return true;
}

bool QueueEmpty(SqQueue Q)
{
    return Q.font == Q.rear;
}

bool EnQueue(SqQueue *Q, ElemType e)
{
    if (!Q || (Q->rear + 1) % MaxSize == Q->font)
        return false;
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MaxSize;
    return true;
}

bool DeQueue(SqQueue *Q, ElemType *e)
{
    if (!Q || QueueEmpty(*Q))
        return false;
    if (e)
        *e = Q->data[Q->font];
    Q->font = (Q->font + 1) % MaxSize;
    return true;
}

bool GetHead(SqQueue Q, ElemType *e)
{
    if (QueueEmpty(Q))
        return false;
    if (e)
        *e = Q.data[Q.rear];
    return true;
}

int main(void)
{
    SqQueue Q;
    SqStack S;
    InitQueue(&Q);
    InitStack(&S);
    int i;
    int e;
    for(i=0;i<3;i++)
    {
        scanf("%d",&e);
        Push(&S,e);
    }
    while(!StackEmpty(S))
    {
        Pop(&S,&e);
        printf("%2d",e);
    }
    putchar('\n');

    for(i=0;i<5;i++)
    {
        scanf("%d",&e);
        if(!EnQueue(&Q,e))
            puts("false");
    }
    while(!QueueEmpty(Q))
    {
        DeQueue(&Q,&e);
        printf("%2d",e);
    }
    putchar('\n');
    return 0;
        
}