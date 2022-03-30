#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#if !defined THREAD_TREE_H
#define THREAD_TREE_H

#if !defined ELEMTYPE
#define ELEMTYPE
typedef char ElemType;
#endif

#define Thread true
#define Link false

typedef struct ThreadNode
{
    ElemType data;
    struct ThreadNode *lchild, *rchild;
    bool ltag, rtag;
} ThreadNode, *ThreadTree;

void InOrder(ThreadTree T, void (*visit)(ThreadNode *));
void PreOrder(ThreadTree T, void (*visit)(ThreadNode *));
void PostOrder(ThreadTree T, void (*visit)(ThreadNode *));
bool CreateThreadTree(ThreadTree *T);
// void InThread(ThreadTree T);
void CreateInThread(ThreadTree *T);
void CreatePreThread(ThreadTree *T);
void CreatePostThread(ThreadTree *T);
void InOrderTraverse_Thr(ThreadTree T, void (*visit)(ThreadNode *));
// 逆序中序遍历
void RevInOrder(ThreadTree T, void (*visit)(ThreadNode *));

#endif