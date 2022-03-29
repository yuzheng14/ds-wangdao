#include "threadtree.h"

void InOrder(ThreadTree T, void (*visit)(ThreadNode *))
{
}

void PreOrder(ThreadTree T, void (*visit)(ThreadNode *))
{
}

void PostOrder(ThreadTree T, void (*visit)(ThreadNode *))
{
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
    if (T)
    {
        InThread(T->lchild);
        thread(T);
        InThread(T->rchild);
    }
}

void PreThread(ThreadTree T)
{
    if (T)
    {
        thread(T);
        if (T->ltag == Link)
            PreThread(T->lchild);
        PreThread(T->rchild);
    }
}

void PostThread(ThreadTree T)
{
    if (T)
    {
        PostThread(T->lchild);
        PostThread(T->rchild);
        thread(T);
    }
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

void CreatePostThread(ThreadTree *T)
{
    if (*T)
    {
        pre = NULL;
        PostThread(*T);
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