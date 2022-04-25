#if !defined RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

// 根节点，叶节点（外部结点、Null结点、失败结点）均是黑色
// 对每个结点来说，从该结点到任一叶结点的简单路径上，所含黑结点的数目相同
#define BLACK 0
// （路径上）不存在两个相邻的红结点（即红节点的父结点和孩子结点均是黑色）
#define RED 1

typedef struct RBNode
{
    int key;
    RBNode *parent;
    RBNode *lchild;
    RBNode *rchild;
    int color;
} RBNode, *RBTree;

#endif