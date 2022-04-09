#include <stdlib.h>
#include <limits.h>
#include "adjlistgraph.h"
#include "../chapter3-stack-queue-array/linkqueue.h"

#define INF INT_MAX

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

void BFS_MIN_Distance(ALGraph G, int v, int *d, int *path)
{
    int i;
    if (d)
        free(d);
    if (path)
        free(path);
    d = (int *)malloc(G.vexnum);
    path = (int *)malloc(G.vexnum);
    for (i = 0; i < G.vexnum; i++)
    {
        visited[i] = false;
        d[i] = INF;
        path[i] = -1;
    }
    LinkQueue Q;
    InitQueue(&Q);
    visited[v] = true;
    EnQueue(&Q, v);
    while (QueueEmpty(Q))
    {
        DeQueue(&Q, &v);
        ArcNode *current;
        for (current = G.vertices[v].first; current; current = current->next)
        {
            if (!visited[current->adjvex])
            {
                d[current->adjvex] = d[v] + 1;
                path[current->adjvex] = v;
                visited[current->adjvex] = true;
                EnQueue(&Q, current->adjvex);
            }
        }
    }
}