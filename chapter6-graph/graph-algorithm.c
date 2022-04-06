#include "graph-algorithm.h"

void BFSTraverse(Graph G, void (*visit)(int))
{
    InitQueue(&Q);
    int i;
    for (i = 0; i < G.vexnum; i++)
        visited[i] = false;
    for (i = 0; i < G.vexnum; i++)
        if (!visited[i])
            BFS(G, i, visit);
}
void BFS(Graph G, int v, void (*visit)(int))
{
    visit(v);
    visited[v] = true;
    EnQueue(&Q, v);
    while (!QueueEmpty(Q))
    {
        DeQueue(&Q, &v);
        int w;
        for (w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w))
            if (!visited[w])
            {
                visit(w);
                visited[w] = true;
                EnQueue(&Q, w);
            }
    }
}