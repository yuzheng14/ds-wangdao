#if !defined BITREE_H
#define BITREE_H

#if defined ELEMTYPE
#undef ELEMTYPE
#endif

#define ELEMTYPE
typedef int ElemType;

typedef struct BiTNode
{
    ElemType data;
    struct BiNode *lchild, *rchild;
} BiTNode, *BiTree;

void PreOrder(BiTree T);

#endif