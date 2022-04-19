#include "avltree.h"
#include <stdlib.h>

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

bool InsertAVL(AVLTree *T, int key, int *taller)
{
    // 如果当前结点不存在，则创建结点
    if (!*T)
    {
        (*T) = (AVLNode *)malloc(sizeof(AVLNode));
        (*T)->key = key;
        (*T)->lchild = (*T)->rchild = NULL;
        (*T)->balance = EH;
        *taller = true;
    }
    else
    {
        // 如果存在同值结点，返回 false
        if (key == (*T)->key)
        {
            *taller = false;
            return false;
        }
        // 如果比当前结点的值小，则在左子树插入
        if (key < (*T)->key)
        {
            // 如果插入错误直接返回 false
            if (!InsertAVL(&(*T)->lchild, key, taller))
                return false;
            // 如果左子树变高，根据当前结点的平衡因子做出决定
            if (*taller)
            {
                switch ((*T)->balance)
                {
                    // 如果左子树的高度高，则插入后不平衡，所以需要一次左平衡旋转
                    // 平衡旋转后高度和未插入前相同，所以 taller 设为 false
                case LH:
                    LeftBalance(T);
                    *taller = false;
                    break;
                    // 如果左子树高度和右子树一样高，则插入后左子树高
                    // 左子树变高，所以 taller 设为 true
                case EH:
                    (*T)->balance = LH;
                    *taller = true;
                    break;
                    // 如果右子树高，则插入后变为一样高
                    // 此时右子树高度和左子树相同，原高度不变，所以 taller 设为 false
                case RH:
                    (*T)->balance = EH;
                    *taller = false;
                    break;
                }
            }
        }
        else
        {
            // 参考左子树的情况
            if (!InsertAVL(&(*T)->rchild, key, taller))
                return false;
            if (*taller)
            {
                switch ((*T)->balance)
                {
                case LH:
                    (*T)->balance = EH;
                    *taller = false;
                    break;
                case EH:
                    (*T)->balance = RH;
                    *taller = true;
                    break;
                case RH:
                    RightBalance(T);
                    *taller = false;
                    break;
                }
            }
        }
    }
    return true;
}