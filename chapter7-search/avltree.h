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
    struct AVLNode *lchild,*rchild;
}AVLNode, *AVLTree;

#endif