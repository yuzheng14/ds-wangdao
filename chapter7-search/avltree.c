#include "avltree.h"

void R_Rotate(AVLTree *P)
{
    AVLTree L;
    L = (*P)->lchild;
    // P 的左子树指向 L 的右子树
    (*P)->lchild = L->rchild;
    // L 的右子树指向 P
    L->rchild = (*P);
    // P 指向 L
    (*P) = L;
}

void L_Rotate(AVLTree *P)
{
    AVLTree R;
    // 参考右旋
    R = (*P)->rchild;
    (*P)->rchild = R->lchild;
    R->lchild = (*P);
    (*P) = R;
}

void LeftBalance(AVLTree *T)
{
    AVLTree L, LR;
    L = (*T)->lchild;
    // 根据左子树的平衡因子做出判断
    switch (L->balance)
    {
        // 如果插入结点位于左子树的左子树
    case LH:
        L->balance = (*T)->balance = EH;
        // 右旋
        R_Rotate(T);
        break;
        // 如果插入结点位于左子树的右子树
    case RH:
        LR = L->rchild;
        // 根据左子树的右子树的平衡因子判断
        switch (LR->balance)
        {
            // 根据插入到左子树的右子树的（左子树还是右子树）进行判断
            // 具体值请画图自行理解
        case LH:
            L->balance = EH;
            (*T)->balance = RH;
            break;
        case RH:
            L->balance = LH;
            (*T)->balance = EH;
            break;
        }
        // 先对左子树左旋，右旋
        L_Rotate(&L);
        R_Rotate(T);
        LR->balance = EH;
    }
}

void RightBalance(AVLTree *T)
{
    // 参考左平衡旋转
    AVLTree R, RL;
    R = (*T)->rchild;
    switch (R->balance)
    {
    case RH:
        R->balance = (*T)->balance = EH;
        L_Rotate(T);
        break;
    case LH:
        RL = R->lchild;
        switch (RL->balance)
        {
        case LH:
            (*T)->balance = EH;
            R->balance = RH;
            break;
        case RH:
            (*T)->balance = LH;
            R->balance = EH;
            break;
        }
        R_Rotate(&R);
        L_Rotate(T);
        RL->balance = EH;
    }
}