#include "avltree.h"
#include <stdio.h>
#include <stdlib.h>
#define test

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
        // 具体值请画图或参考 README 中的图解自行理解
        case LH:
            L->balance = EH;
            (*T)->balance = RH;
            break;
        // 此种情况为插入的结点是左子树的右孩子的情况
        case EH:
            (*T)->balance = L->balance = EH;
            break;
        case RH:
            L->balance = LH;
            (*T)->balance = EH;
            break;
        }
        // 先对左子树左旋，右旋
        L_Rotate(&(*T)->lchild);
        R_Rotate(T);
        LR->balance = EH;
        break;
    case EH:
        (*T)->balance = LH;
        L->balance = RH;
        R_Rotate(T);
        break;
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
        case EH:
            (*T)->balance = R->balance = EH;
            break;
        case RH:
            (*T)->balance = LH;
            R->balance = EH;
            break;
        }
        R_Rotate(&(*T)->rchild);
        L_Rotate(T);
        RL->balance = EH;
        break;
    // 此种情况为删除结点时特有，插入不会出现此种情况
    case EH:
        (*T)->balance = RH;
        R->balance = LH;
        L_Rotate(T);
        break;
    }
}

bool InsertAVL(AVLTree *T, int key, bool *taller)
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

void InitAVL(AVLTree *T)
{
    (*T) = NULL;
}

void Traverse(AVLTree T, void (*visit)(AVLNode *))
{
    if (T)
    {
        Traverse(T->lchild, visit);
        visit(T);
        Traverse(T->rchild, visit);
    }
}

void print(AVLNode *node)
{
    printf("%-3d", node->key);
}

// 删除的是左子树的节点
void left_remove_balance(AVLTree *T, bool *shorter)
{

    switch ((*T)->balance)
    {
    case LH:
        (*T)->balance = EH;
        *shorter = true;
        break;
    case EH:
        (*T)->balance = RH;
        *shorter = false;
        break;
    case RH:
        RightBalance(T);
        *shorter = false;
        break;
    } // switch ((*T)->balance)
}

// 删除的是右子树的结点
void right_remove_balance(AVLTree *T, bool *shorter)
{
    switch ((*T)->balance)
    {
    case LH:
        LeftBalance(T);
        *shorter = false;
        break;
    case EH:
        (*T)->balance = LH;
        *shorter = false;
        break;
    case RH:
        (*T)->balance = EH;
        *shorter = true;
        break;
    } // switch((*T)->balance)
}

// 递归找到要删除结点的后继结点，用后继结点替代要删除的结点，并自底向上调整平衡
void remove_next_node(AVLTree *T, bool *shorter, AVLNode *remove_node)
{
    // 如果有左孩子，则递归调用传入左孩子。并调整平衡
    if ((*T)->lchild)
    {
        remove_next_node(&(*T)->lchild, shorter, remove_node);
        if (*shorter)
            left_remove_balance(T, shorter);
    } // if ((*T)->lchild)
    // 没有左孩子，即当前结点是后继节点，替换要删除的结点
    else
    {
        AVLNode *previous = (*T);
        remove_node->key = previous->key;
        (*T) = previous->rchild;
        *shorter = true;
        free(previous);
    }
}

// 递归找到要删除的结点，并自底向上调整平衡
bool RemoveAVL(AVLTree *T, int key, bool *shorter)
{
    // 如果当前结点不存在，即树中无要删除结点，返回 false
    if (!(*T))
        return false;
    // 找到要删除结点，则进行删除操作
    if ((*T)->key == key)
    {
        // 如果该结点没有左孩子，直接用右孩子替代该节点
        if (!(*T)->lchild)
        {
            *shorter = true;
            (*T) = (*T)->rchild;
        } // if (!(*T)->lchild)
        // 如果该节点没有右孩子，直接用左孩子替代该节点
        else if (!(*T)->rchild)
        {
            (*T) = (*T)->lchild;
            *shorter = true;
        } // if (!(*T)->rchild)
        // 否则，调用 remove_next_node() 来删除当前节点
        else
        {
            *shorter = false;
            remove_next_node(&(*T)->rchild, shorter, (*T));
        }
    } // if ((*T)->key == key)
    // 如果 当前结点的 key 小于 key，则递归调用传入右子树，并处理平衡
    else if ((*T)->key < key)
    {
        if (!RemoveAVL(&(*T)->rchild, key, shorter))
            return false;
        if (*shorter)
            left_remove_balance(T, shorter);
    } // if ((*T)->key < key)
    // 如果 当前结点的 key 大于 key，则递归调用传入左子树，并处理平衡
    else
    {
        if (!RemoveAVL(&(*T)->lchild, key, shorter))
            return false;
        if (*shorter)
            right_remove_balance(T, shorter);
    } // else
    return true;
}

#if defined test

int main(void)
{
    AVLTree T;
    InitAVL(&T);
    bool taller;
    InsertAVL(&T, 5, &taller);
    InsertAVL(&T, 2, &taller);
    InsertAVL(&T, 1, &taller);
    InsertAVL(&T, 3, &taller);
    InsertAVL(&T, 4, &taller);
    InsertAVL(&T, 5, &taller);
    InsertAVL(&T, 8, &taller);
    InsertAVL(&T, 7, &taller);
    InsertAVL(&T, 6, &taller);
    InsertAVL(&T, 9, &taller);
    InsertAVL(&T, 18, &taller);
    InsertAVL(&T, 10, &taller);
    InsertAVL(&T, 15, &taller);
    InsertAVL(&T, 17, &taller);
    InsertAVL(&T, 13, &taller);
    InsertAVL(&T, 20, &taller);
    InsertAVL(&T, 19, &taller);
    Traverse(T, print);
    putchar('\n');
    RemoveAVL(&T, 5, &taller);
    Traverse(T, print);
    putchar('\n');
    RemoveAVL(&T, 7, &taller);
    Traverse(T, print);
    putchar('\n');
    RemoveAVL(&T, 3, &taller);
    Traverse(T, print);
    putchar('\n');
    return 0;
}

#endif