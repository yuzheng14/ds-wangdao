#include "threadtree.h"

void InOrder(ThreadTree T, void (*visit)(ThreadNode *))
{
    if (T)
    {
        InOrder(T->lchild, visit);
        visit(T);
        InOrder(T->rchild, visit);
    }
}

void PreOrder(ThreadTree T, void (*visit)(ThreadNode *))
{
    if (T)
    {
        visit(T);
        if (T->ltag == Link)
            PreOrder(T->lchild, visit);
        PreOrder(T->rchild, visit);
    }
}

bool CreateThreadTree(ThreadTree *T)
{
    ElemType ch;
    if (scanf("%c", &ch) != EOF)
    {
        if (ch == '#')
            (*T) = NULL;
        else
        {
            (*T) = (ThreadNode *)malloc(sizeof(ThreadNode));
            if (!(*T))
                return false;
            (*T)->data = ch;
            (*T)->ltag = (*T)->rtag = Link;
            return CreateThreadTree(&(*T)->lchild) && CreateThreadTree(&(*T)->rchild);
        }
    }
    return true;
}

ThreadNode *pre;

void thread(ThreadNode *current)
{
    if (!current->lchild)
    {
        current->lchild = pre;
        current->ltag = Thread;
    }
    if (pre && !pre->rchild)
    {
        pre->rchild = current;
        pre->rtag = Thread;
    }
    pre = current;
}

void InThread(ThreadTree T)
{
    InOrder(T, thread);
}

void PreThread(ThreadTree T)
{
    PreOrder(T, thread);
}

void CreateInThread(ThreadTree *T)
{
    if (*T)
    {
        pre = NULL;
        InThread(*T);
        if (!pre->rchild)
            pre->rtag = Thread;
    }
}

void CreatePreThread(ThreadTree *T)
{
    if (*T)
    {
        pre = NULL;
        PreThread(*T);
        if (!pre->rchild)
            pre->rtag = Thread;
    }
}

int main(void)
{
    ThreadTree T;
    CreateThreadTree(&T);
    CreateInThread(&T);
    return 0;
}