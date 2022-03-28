#include "bitree.h"

void PreOrder(BiTree T, void (*visit)(ElemType))
{
    if (T)
    {
        (*visit)(T->data);
        PreOrder(T->lchild, visit);
        PreOrder(T->rchild, visit);
    }
}

void InOrder(BiTree T, void (*visit)(ElemType))
{
    if (T)
    {
        PreOrder(T->lchild, visit);
        (*visit)(T->data);
        PreOrder(T->rchild, visit);
    }
}

void PostOrder(BiTree T, void (*visit)(ElemType))
{
    if (T)
    {
        PreOrder(T->lchild, visit);
        PreOrder(T->rchild, visit);
        (*visit)(T->data);
    }
}