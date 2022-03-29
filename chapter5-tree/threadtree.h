#include <stdbool.h>

#if !defined THREAD_TREE_H
#define THREAD_TREE_H

#if !defined ELEMTYPE
#define ELEMTYPE
typedef char ElemType;
#endif

#define Thread true;
#define Link false;

typedef struct ThreadNode
{
    ElemType data;
    struct ThreadNode *lchild, *rchild;
    bool ltag, rag;
} ThreadNode, *ThreadTree;

#endif