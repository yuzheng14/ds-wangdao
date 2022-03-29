#include "threadtree.h"

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

ThreadNode *FirstNode(ThreadNode *p)
{
    while (p->ltag == Link)
        p = p->lchild;
    return p;
}

ThreadNode *NextNode(ThreadNode *p)
{
    if (p->rtag == Link)
        return FirstNode(p->rchild);
    else
        return p->rchild;
}

void InOrder(ThreadTree T, void (*visit)(ThreadNode *))
{
    ThreadNode *current;
    for (current = FirstNode(T); current; current = NextNode(current))
        visit(current);
}

void InOrderTraverse_Thr(ThreadTree T, void (*visit)(ThreadNode *))
{
    ThreadNode *current;
    current = T;
    while (current)
    {
        while (current->ltag == Link)
            current = current->lchild;
        visit(current);
        while (current->rtag == Thread && current->rchild)
        {
            current = current->rchild;
            visit(current);
        }
        current = current->rchild;
    }
}

void print(ThreadNode *current)
{
    printf("%c", current->data);
}

int main(void)
{
    ThreadTree T;
    CreateThreadTree(&T);
    CreateInThread(&T);
    InOrder(T, print);
    putchar('\n');
    InOrderTraverse_Thr(T, print);
    putchar('\n');
    return 0;
}