#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 辅助队列的定义
typedef int ElemType;

typedef struct LinkNode
{
    int data;
    struct LinkNode *next;
} LinkNode;

typedef struct
{
    LinkNode *front, *rear;
} LinkQueue;

// 邻接表的定义
#define MaxVertexNum 7

typedef struct ArcNode
{
    int adjvex;
    struct ArcNode *next;
} ArcNode;

typedef struct
{
    char data;
    ArcNode *first;
} Vnode, AdjList[MaxVertexNum];

typedef struct
{
    AdjList vertices;
    int vexnum, arcnum;
} ALGraph, Graph;

// 辅助队列的函数实现
bool InitQueue(LinkQueue *Q)
{
    Q->rear = Q->front = (LinkNode *)malloc(sizeof(LinkNode));
    if (!Q->front)
        return false;
    Q->front->next = NULL;
    return true;
}

bool EnQueue(LinkQueue *Q, ElemType e)
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

bool DeQueue(LinkQueue *Q, ElemType *e)
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

// 邻接表图的函数实现
void InitGraph(ALGraph *G)
{
    G->arcnum = 0;
    G->vexnum = 0;
}

bool VextexFull(ALGraph G)
{
    return G.vexnum == MaxVertexNum;
}

int InsertVertex(ALGraph *G, char data)
{
    if (VextexFull(*G))
        return -1;
    G->vertices[G->vexnum].data = data;
    G->vertices[G->vexnum].first = NULL;
    G->vexnum++;
    return G->vexnum - 1;
}

bool AddEdge(ALGraph *G, int x, int y)
{
    // 边界检查
    if (x < 0 || y < 0 || x > G->vexnum - 1 || x > G->vexnum - 1)
        return false;
    ArcNode *current;
    // 若已存在此条边
    for (current = G->vertices[x].first; current; current = current->next)
        if (current->adjvex == y)
            return false;

    if (!G->vertices[x].first)
    {
        current = (ArcNode *)malloc(sizeof(ArcNode));
        current->adjvex = y;
        current->next = NULL;
        G->vertices[x].first = current;
    }
    else
    {
        for (current = G->vertices[x].first; current->next; current = current->next)
            ;
        ArcNode *new = (ArcNode *)malloc(sizeof(ArcNode));
        new->adjvex = y;
        new->next = NULL;
        current->next = new;
    }
    G->arcnum++;
    return true;
}

bool visited[MaxVertexNum];

void BFSTraverse(ALGraph G, void (*visit)(Vnode))
{
    LinkQueue Q;
    InitQueue(&Q);
    int i;
    for (i = 0; i < G.vexnum; i++)
        visited[i] = false;

    for (i = 0; i < G.vexnum; i++)
        if (!visited[i])
        {
            visit(G.vertices[i]);
            visited[i] = true;
            EnQueue(&Q, i);
            while (!QueueEmpty(Q))
            {
                int j;
                DeQueue(&Q, &j);
                ArcNode *current;
                for (current = G.vertices[j].first; current; current = current->next)
                    if (!visited[current->adjvex])
                    {
                        visit(G.vertices[current->adjvex]);
                        visited[current->adjvex] = true;
                        EnQueue(&Q, current->adjvex);
                    };
            }
        }
}

void DFS(ALGraph G, int v, void (*visit)(Vnode))
{
    visit(G.vertices[v]);
    visited[v] = true;
    ArcNode *current;
    for (current = G.vertices[v].first; current; current = current->next)
        if (!visited[current->adjvex])
            DFS(G, current->adjvex, visit);
}

void DFSTraverse(ALGraph G, void (*visit)(Vnode))
{
    int i;
    for (i = 0; i < G.vexnum; i++)
        visited[i] = false;
    for (i = 0; i < G.vexnum; i++)
        if (!visited[i])
            DFS(G, i, visit);
}

void print(Vnode v)
{
    printf("%2c", v.data);
}

int main(void)
{
    ALGraph G;
    InitGraph(&G);
    char vexs[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    char edges[][2] = {
        {'A', 'B'},
        {'B', 'C'},
        {'B', 'E'},
        {'B', 'F'},
        {'C', 'E'},
        {'D', 'C'},
        {'E', 'B'},
        {'E', 'D'},
        {'F', 'G'}};
    int i;
    for (i = 0; i < sizeof(vexs) / sizeof(char); i++)
        InsertVertex(&G, vexs[i]);
    for (i = 0; i < sizeof(edges) / (sizeof(char) * 2); i++)
        AddEdge(&G, edges[i][0] - 'A', edges[i][1] - 'A');
    DFSTraverse(G, print);
    putchar('\n');
    BFSTraverse(G, print);
    // putchar('\n');
    return 0;
}