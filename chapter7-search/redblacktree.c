#include "redblacktree.h"

#include <stdlib.h>

void InitRBT(RBTree *T) { (*T) = NULL; }

void R_Rotate(RBNode *p, RBTree *T) {
    // 思路同 avl 的右旋
    RBTree L;
    L = p->lchild;
    L->parent = p->parent;
    p->lchild = L->rchild;
    if (p->parent) {
        if (p == L->parent->lchild)
            p->parent->lchild = L;
        else
            p->parent->rchild = L;
    } else
        // 如果 p 的父节点为空，则需对红黑树的根结点进行调整
        (*T) = L;
    p->parent = L;
    L->rchild = p;
    if (p->lchild) p->lchild->parent = p;
}

void L_Rotate(RBNode *p, RBTree *T) {
    RBTree R;
    R = p->rchild;
    R->parent = p->parent;
    p->rchild = R->lchild;
    if (p->parent) {
        if (p == R->parent->lchild)
            p->parent->lchild = R;
        else
            p->parent->rchild = R;
    } else {
        (*T) = R;
    }
    p->parent = R;
    R->lchild = p;
    if (p->rchild) p->rchild->parent = p;
}

void insert_fixup(RBTree *P, RBTree *T) {
    RBNode *cur = (*P);
    // 只要 cur 非根节点并且 cur 的父节点的颜色为 red，则循环
    // cur 的父节点颜色为 red 时，违反了红黑树的性质，所以需要调整
    while (cur->parent && cur->parent->color == RED) {
        RBNode *uncle;
        // 如果当前结点在爷爷结点的左子树
        if (cur->parent == cur->parent->parent->lchild) {
            // 叔叔结点为爷爷结点的右孩子
            uncle = cur->parent->parent->rchild;
            // 如果叔叔节点为红色，则将叔叔节点和父节点设为 balck，爷爷结点设为
            // red cur 设置为爷爷结点，一遍向上寻找违反性质的点（红红）
            if (uncle && uncle->color == RED) {
                cur->parent->color = uncle->color = BLACK;
                cur = cur->parent->parent;
                cur->color = RED;
            }
            // 如果叔叔结点的颜色为 black，调整的旋转方式同 avl
            // uncle 不存在即为黑色
            else {
                // avl 的 LR 型
                if (cur == cur->parent->rchild) {
                    cur = cur->parent;
                    L_Rotate(cur, T);
                }
                // 通过巧妙设计，将 LL 和 LR 型通用的部分抽取出来，简化代码
                cur->parent->color = BLACK;
                cur->parent->parent->color = RED;
                R_Rotate(cur->parent->parent, T);
            }
        }
        // 思路同爷爷结点的左子树
        else {
            uncle = cur->parent->parent->lchild;
            if (uncle && uncle->color == RED) {
                uncle->color = cur->parent->color = BLACK;
                cur = cur->parent->parent;
                cur->color = RED;
            } else {
                if (cur == cur->parent->lchild) {
                    cur = cur->parent;
                    R_Rotate(cur, T);
                }
                cur->parent->color = BLACK;
                cur->parent->parent->color = RED;
                L_Rotate(cur->parent->parent, T);
            }
        }
    }
    if (!cur->parent) cur->color = BLACK;
}

bool InsertRBT(RBTree *T, int key) {
    // 如果当前树为空，则初始化结点，并染色为 black
    if (!(*T)) {
        (*T) = (RBNode *)malloc(sizeof(RBNode));
        (*T)->color = BLACK;
        (*T)->lchild = (*T)->rchild = (*T)->parent = NULL;
        (*T)->key = key;
    }
    // 树非空的情况
    else {
        RBNode *pre, *cur = NULL;
        cur = (*T);
        // 找到要插入的位置及其父结点
        while (cur) {
            pre = cur;
            if (key == cur->key)
                return false;
            else if (key < cur->key)
                cur = cur->lchild;
            else
                cur = cur->rchild;
        }  // while (cur)
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
        insert_fixup(&cur, T);
    }
    return true;
}

void Traverse(RBTree T, void (*visit)(RBNode *p)) {
    if (T) {
        Traverse(T->lchild, visit);
        visit(T);
        Traverse(T->rchild, visit);
    }
}

#define test

#if defined test

#include <stdio.h>

void print(RBNode *p) { printf("%-3d", p->key); }

int main(void) {
    RBTree T;
    InitRBT(&T);
    InsertRBT(&T, 20);
    InsertRBT(&T, 10);
    InsertRBT(&T, 5);
    InsertRBT(&T, 30);
    InsertRBT(&T, 40);
    InsertRBT(&T, 57);
    InsertRBT(&T, 3);
    InsertRBT(&T, 2);
    InsertRBT(&T, 4);
    InsertRBT(&T, 35);
    InsertRBT(&T, 25);
    InsertRBT(&T, 18);
    InsertRBT(&T, 22);
    InsertRBT(&T, 23);
    InsertRBT(&T, 24);
    InsertRBT(&T, 19);
    InsertRBT(&T, 18);
    Traverse(T, print);
    putchar('\n');
    return 0;
}

#endif