#if !defined RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <stdbool.h>

// 根节点，叶节点（外部结点、Null结点、失败结点）均是黑色
// 对每个结点来说，从该结点到任一叶结点的简单路径上，所含黑结点的数目相同
#define BLACK 0
// （路径上）不存在两个相邻的红结点（即红节点的父结点和孩子结点均是黑色）
#define RED 1

typedef struct RBNode {
    int key;
    struct RBNode *parent;
    struct RBNode *lchild;
    struct RBNode *rchild;
    int color;
} RBNode, *RBTree;

// 初始化
void InitRBT(RBTree *T);
// 右转，与 avl 类似
void R_Rotate(RBNode *p, RBTree *T);
// 左转，与 avl类似
void L_Rotate(RBNode *p, RBTree *T);
// 插入算法
bool InsertRBT(RBTree *T, int key);
// 遍历
void Traverse(RBTree T, void (*visit)(RBNode *p));

#endif