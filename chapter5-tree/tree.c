#include "tree.h"
#define ELEMTYPE
#define ElemType CSNode *
#include "../chapter3-stack-queue-array/linkqueue.h"
#undef ElemType

void PreOrder(CSTree T, void (*visit)(CSNode *))
{
    if (T)
    {
        visit(T);
        CSNode *current;
        for (current = T->firstchild; current; current = current->nextsibling)
            PreOrder(current, visit);
    }
}
// 树的后序遍历和二叉树的中序遍历一样
void PostOrder(CSTree T, void (*visit)(CSNode *))
{
    if (T)
    {
        CSNode *current;
        for (current = T->firstchild; current; current = current->nextsibling)
            PostOrder(current, visit);
        visit(T);
    }
}

void LevelOrder(CSTree T, void (*visit)(CSNode *))
{
    LinkQueue Q;
    InitQueue(&Q);
    EnQueue(&Q, T);
    CSNode *current;
    while (!QueueEmpty(Q))
    {
        DeQueue(&Q, &current);
        visit(current);
        for (current = current->firstchild; current; current = current->nextsibling)
            EnQueue(&Q, current);
    }
}