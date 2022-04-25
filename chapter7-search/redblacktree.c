#include "redblacktree.h"
#include <stdlib.h>

void InitRBT(RBTree *T)
{
    (*T) = NULL;
}

void R_Rotate(RBTree *T)
{
    RBTree L;
    L = (*T)->lchild;
    L->parent = (*T)->parent;
    (*T)->lchild = L->rchild;
    (*T)->parent = L;
    L->rchild = (*T);
    if ((*T)->lchild)
        (*T)->lchild->parent = (*T);
    (*T) = L;
}

void L_Rotate(RBTree *T)
{
    RBTree R;
    R = (*T)->rchild;
    R->parent = (*T)->parent;
    (*T)->rchild = R->lchild;
    (*T)->parent = R;
    R->lchild = (*T);
    if ((*T)->rchild)
        (*T)->rchild->parent = (*T);
    (*T) = R;
}

void insert_fixup(RBTree *P)
{
    RBNode *cur = (*P);
    // 只要 cur 非根节点并且 cur 的父节点的颜色为 red，则循环
    // cur 的父节点颜色为 red 时，违反了红黑树的性质，所以需要调整
    while (cur->parent && cur->parent->color == RED)
    {
        RBNode *uncle;
        // 如果当前结点在爷爷结点的左子树
        if (cur->parent == cur->parent->parent->lchild)
        {
            // 叔叔结点为爷爷结点的右孩子
            uncle = cur->parent->parent->rchild;
            // 如果叔叔节点为红色，则将叔叔节点和父节点设为 balck，爷爷结点设为 red
            // cur 设置为爷爷结点，一遍向上寻找违反性质的点（红红）
            if (uncle->color == RED)
            {
                cur->parent->color = uncle->color = BLACK;
                cur = cur->parent->parent;
                cur->color = RED;
            }
            // 如果叔叔结点的颜色为 black，调整的旋转方式同 avl
            else
            {
                // avl 的 LR 型
                if (cur == cur->parent->rchild)
                {
                    cur = cur->parent;
                    L_Rotate(&cur);
                }
                // 通过巧妙设计，将 LL 和 LR 型通用的部分抽取出来，简化代码
                cur->parent->color = BLACK;
                cur->parent->parent->color = RED;
                R_Rotate(&(cur->parent->parent));
            }
        }
        // 思路同爷爷结点的左子树
        else
        {
            uncle = cur->parent->parent->lchild;
            if (uncle->color == RED)
            {
                uncle->color = cur->parent->color = BLACK;
                cur = cur->parent->parent;
                cur->color = RED;
            }
            else
            {
                if (cur == cur->parent->lchild)
                {
                    cur = cur->parent;
                    R_Rotate(&cur);
                }
                cur->parent->color = BLACK;
                cur->parent->parent->color = RED;
                L_Rotate(&cur->parent->parent);
            }
        }
    }
    if (!cur->parent)
        cur->color = BLACK;
}

bool insertRBT(RBTree *T, int key)
{
    // 如果当前树为空，则初始化结点，并染色为 black
    if (!(*T))
    {
        (*T) = (RBNode *)malloc(sizeof(RBNode));
        (*T)->color = BLACK;
        (*T)->lchild = (*T)->rchild = (*T)->parent = NULL;
        (*T)->key = key;
    }
    // 树非空的情况
    else
    {
        RBNode *pre, *cur = NULL;
        cur = (*T);
        // 找到要插入的位置及其父结点
        while (cur)
        {
            pre = cur;
            if (key == cur->key)
                return false;
            else if (key < cur->key)
                cur = cur->lchild;
            else
                cur = cur->rchild;
        } // while (cur)
        // 初始化结点并连接到父结点
        cur = (RBNode *)malloc(sizeof(RBNode));
        cur->color = RED;
        cur->key = key;
        cur->parent = pre;
        cur->lchild = cur->rchild = NULL;
        if (key < pre->key)
            pre->lchild = cur;
        else
            pre->rchild = cur;
        // 对红黑树进行调整
        insert_fixup(&cur);
    }
    return true;
}