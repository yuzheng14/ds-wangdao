#include<stdbool.h>
#if !defined AVL_TREE_H
#define AVL_TREE_H

// 左子树高
#define LH 1
// 一样高
#define EH 0
// 右子树高
#define RH -1

typedef struct AVLNode
{
    int key;
    int balance;
    struct AVLNode *lchild, *rchild;
} AVLNode, *AVLTree;

void R_Rotate(AVLTree *P);
void L_Rotate(AVLTree *P);
// 左平衡旋转
void LeftBalance(AVLTree *T);
// 右平衡旋转
void RightBalance(AVLTree *T);
// 向平衡二叉树中插入
bool InsertAVL(AVLTree *T, int key, bool *taller);
void InitAVL(AVLTree *T);
void Traverse(AVLTree T, void (*visit)(AVLNode *));
// 删除平衡二叉树中的结点
bool RemoveAVL(AVLTree *T, int key, bool *shorter);

#endif