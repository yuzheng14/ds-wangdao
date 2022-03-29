#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#if !defined BITREE_H
#define BITREE_H

#if !defined ELEMTYPE
#define ELEMTYPE
typedef int ElemType;
#endif

typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void PreOrder(BiTree T, void (*visit)(BiTNode *));
void InOrder(BiTree T, void (*visit)(BiTNode *));
void PostOrder(BiTree T, void (*visit)(BiTNode *));
int treeDepth(BiTree T);
void LevelOrder(BiTree T, void (*visit)(BiTNode *));
bool CreateBiTree(BiTree *T);

#endif