#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef char ElemType;

#define MAXSIZE 100

typedef struct TreeNode
{
    ElemType value;
    bool isEmpty;
} TreeNode, Tree[MAXSIZE];

bool InitTree(Tree *T)
{
    int i;
    for (i = 0; i < MAXSIZE; i++)
        (*T)[i].isEmpty = true;
    return true;
}

bool TreeInsert(Tree *T, int i, ElemType e)
{
    if (i < 1 || i > MAXSIZE || !(*T)[i].isEmpty)
        return false;
    (*T)[i].value = e;
    (*T)[i].isEmpty = false;
    return true;
}

int getLeft(int i)
{
    return 2*i;
}

int getRight(int i)
{
    return 2*i + 1;
}

void preOrderAccess(const Tree *T, int i)
{
    if (i < 1 || i > MAXSIZE || (*T)[i].isEmpty)
        return;
    // putchar((*T)[i].value);
    printf("%c", (*T)[i].value);
    preOrderAccess(T, getLeft(i));
    preOrderAccess(T, getRight(i));
}

int main(void)
{
    Tree T;
    InitTree(&T);
    ElemType e;
    int i = 1;
    while (scanf("%c", &e) != EOF)
        TreeInsert(&T, i++, e);
    preOrderAccess(&T, 1);
    // printf("%d\n", getLeft(1));
    return 0;
}