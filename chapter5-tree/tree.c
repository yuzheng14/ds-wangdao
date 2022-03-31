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

void PostOrder(CSTree T, void (*visit)(CSNode *))
{
    if (T)
    {
        if (T->firstchild)
        {
            CSNode *current = T->firstchild;
            PreOrder(current, visit);
            for (current = current->nextsibling; current; current = current->nextsibling)
                PreOrder(current, visit);
        }
        visit(T);
    }
}