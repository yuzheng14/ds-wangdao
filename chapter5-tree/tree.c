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
        if (T->firstchild)
        {
            CSNode *current = T->firstchild;
            PreOrder(current, visit);
            for (current = current->nextsibling; current; current = current->nextsibling)
                PreOrder(current, visit);
        }
    }
}
// 树的后序遍历和二叉树的中序遍历一样
void PostOrder(CSTree T, void (*visit)(CSNode *))
{
    if (T)
    {
        if (T->firstchild)
        {
            CSNode *current = T->firstchild;
            PostOrder(current, visit);
            for (current = current->nextsibling; current; current = current->nextsibling)
                PostOrder(current, visit);
        }
        visit(T);
    }
}

void LevelOrder(CSTree T,void (*visit)(CSNode *))
{
    LinkQueue Q;
    InitQueue(&Q);
    EnQueue(&Q,T);
    CSNode *current;
    while(!QueueEmpty(Q))
    {
        DeQueue(&Q,&current);
        visit(current);
        for(current=current->firstchild;current;current=current->nextsibling)
            EnQueue(&Q,current);
    }
}