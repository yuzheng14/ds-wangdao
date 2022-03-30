#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void InOrder(BiTree T, void (*visit)(BiTNode *));
void PostOrder(BiTree T, void (*visit)(BiTNode *));
void LevelOrder(BiTree T, void (*visit)(BiTNode *));
void CreateBiTree(BiTree *T);

typedef struct LinkNode
{
    BiTNode **data;
    struct LinkNode *next;
} LinkNode;

typedef struct
{
    LinkNode *front, *rear;
} LinkQueue;

bool InitQueue(LinkQueue *Q);
bool EnQueue(LinkQueue *Q, BiTNode **e);
bool QueueEmpty(LinkQueue Q);
bool DeQueue(LinkQueue *Q, BiTNode ***e);

void InOrder(BiTree T, void (*visit)(BiTNode *))
{
    if (T)
    {
        InOrder(T->lchild, visit);
        visit(T);
        InOrder(T->rchild, visit);
    }
}

void PostOrder(BiTree T, void (*visit)(BiTNode *))
{
    if (T)
    {
        PostOrder(T->lchild, visit);
        PostOrder(T->rchild, visit);
        visit(T);
    }
}

void LevelOrder(BiTree T, void (*visit)(BiTNode *))
{
    LinkQueue Q;
    BiTNode **current;
    InitQueue(&Q);
    EnQueue(&Q, &T);
    while (!QueueEmpty(Q))
    {
        DeQueue(&Q, &current);
        visit(*current);
        if ((*current)->lchild)
            EnQueue(&Q, &(*current)->lchild);
        if ((*current)->rchild)
            EnQueue(&Q, &(*current)->rchild);
    }
}

void CreateBiTree(BiTree *T)
{
    char ch;
    LinkQueue Q;
    InitQueue(&Q);
    EnQueue(&Q, T);
    BiTNode **current;
    while (scanf("%c", &ch) != EOF)
    {
        DeQueue(&Q, &current);
        (*current) = (BiTNode *)malloc(sizeof(BiTNode));
        (*current)->lchild=(*current)->rchild=NULL;
        (*current)->data = ch;
        EnQueue(&Q, &(*current)->lchild);
        EnQueue(&Q, &(*current)->rchild);
    }
}

bool InitQueue(LinkQueue *Q)
{
    Q->rear = Q->front = (LinkNode *)malloc(sizeof(LinkNode));
    if (!Q->front)
        return false;
    Q->front->next = NULL;
    return true;
}

bool EnQueue(LinkQueue *Q, BiTNode **e)
{
    if (!Q)
        return false;
    LinkNode *new_node = (LinkNode *)malloc(sizeof(LinkNode));
    if (!new_node)
        return false;
    new_node->data = e;
    new_node->next = NULL;
    Q->rear->next = new_node;
    Q->rear = new_node;
    return true;
}

bool QueueEmpty(LinkQueue Q)
{
    return Q.front == Q.rear;
}

bool DeQueue(LinkQueue *Q, BiTNode ***e)
{
    if (!Q || QueueEmpty(*Q))
        return false;
    LinkNode *current = Q->front->next;
    if (e)
        *e = current->data;
    Q->front->next = current->next;
    // 如果要删除的结点是最后一个结点则需要单独处理
    if (Q->rear == current)
        Q->rear = Q->front;
    free(current);
    return true;
}

void print(BiTNode *p)
{
    printf("%c", p->data);
}

int main(void)
{
    BiTree T;
    CreateBiTree(&T);
    InOrder(T, print);
    putchar('\n');
    PostOrder(T, print);
    putchar('\n');
    LevelOrder(T, print);
    putchar('\n');
    return 0;
}