#include "bitree.h"
#define ElemType BiTNode *
#include "../chapter3-stack-queue-array/linkqueue.h"
#undef ElemType

void PreOrder(BiTree T, void (*visit)(BiTNode *))
{
    if (T)
    {
        visit(T);
        PreOrder(T->lchild, visit);
        PreOrder(T->rchild, visit);
    }
}

void InOrder(BiTree T, void (*visit)(BiTNode *))
{
    if (T)
    {
        PreOrder(T->lchild, visit);
        visit(T);
        PreOrder(T->rchild, visit);
    }
}

void PostOrder(BiTree T, void (*visit)(BiTNode *))
{
    if (T)
    {
        PreOrder(T->lchild, visit);
        PreOrder(T->rchild, visit);
        visit(T);
    }
}

int treeDepth(BiTree T)
{
    if (!T)
        return 0;
    int l, r;
    l = treeDepth(T->lchild) + 1;
    r = treeDepth(T->rchild) + 1;
    return l > r ? l : r;
}

void LevelOrder(BiTree T, void (*visit)(BiTNode *))
{
    LinkQueue Q;
    BiTNode *current;
    InitQueue(&Q);
    EnQueue(&Q, T);
    while (!QueueEmpty(Q))
    {
        DeQueue(&Q, &current);
        visit(current);
        if (current->lchild)
            EnQueue(&Q, current->lchild);
        if (current->rchild)
            EnQueue(&Q, current->rchild);
    }
}

int main(void)
{
    ElemType a = 5;
    printf("%d\n", a);
    return 0;
}