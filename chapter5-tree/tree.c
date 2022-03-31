#include "tree.h"

void PreOrder(CSTree T, void (*visit)(CSNode *))
{
    if (T)
    {
        visit(T);
        if (T->firstchild)
        {
            CSNode *current = T->firstchild;
            visit(current);
            for (current = current->nextsibling; current; current = current->nextsibling)
                visit(current);
        }
    }
}