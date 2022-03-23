#include <stdio.h>
#include <stdbool.h>

#if !defined TREE_NODE_H
#define TREE_NODE_H

#if defined ELEMTYPE
#undef ELEMTYPE
#endif

#if !defined MAXSIZE
#define MAXSIZE 100
#endif

#define ELEMTYPE
typedef int ElemType;

typedef struct TreeNode
{
    ElemType value;
    bool isEmpty;
} TreeNode, Tree[MAXSIZE];

#endif