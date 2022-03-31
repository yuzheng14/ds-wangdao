#include "tree.h"

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