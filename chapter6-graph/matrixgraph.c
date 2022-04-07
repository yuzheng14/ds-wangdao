#include "matrixgraph.h"

int InsertVertex(MGraph *G, VertexType v)
{
    if (G->vexnum > MaxVertexNum - 1)
        return -1;
    G->Vex[G->vexnum] = v;
    G->vexnum++;
    return G->vexnum - 1;
}

void InitGraph(MGraph *G)
{
    int i, j;
    G->vexnum = 0;
    G->arcnum = 0;
    for (i = 0; i < MaxVertexNum; i++)
        for (j = 0; j < MaxVertexNum; j++)
            G->Edge[i][j] = INF;
    for (i = 0; i < MaxVertexNum; i++)
        G->Vex[i] = 0;
}

bool AddEdge(MGraph *G, int x, int y, int info)
{
    if (x < 0 || y < 0 || x > G->vexnum || y > G->vexnum || x == y)
        return false;
    G->Edge[x][y] = info;
    G->Edge[y][x] = info;
    G->arcnum++;
    return true;
}

void MiniSpanTree_Prim(MGraph G)
{
    // 记录当前 lowcost 中的最小权值是哪个结点的边
    int adject[G.vexnum];
    // 可到达的边的最小权值，若为 0 则表示当前边已加入生成树
    int lowcost[G.vexnum];
    int i;
    // 初始化
    // 将 lowcost 更新为 v0到各边的权值
    // 将 adject 全部初始化为 0，表示当前 lowcost 是 v0 的权值
    for (i = 0; i < G.vexnum; i++)
    {
        lowcost[i] = G.Edge[0][i];
        adject[i] = 0;
    }
    // 将 v0 加入最小生成树。
    lowcost[0] = 0;
    // 开始循环，共循环 n-1 次，一次循环将一个结点加入生成树
    for (i = 1; i < G.vexnum; i++)
    {
        int min = INF;
        int k = 0;
        int j;
        // 循环查找 lowcost 中最小的结点
        for (j = 1; j < G.vexnum; j++)
            if (lowcost[j] != 0 && lowcost[j] < min)
            {
                min = lowcost[j];
                k = j;
            }
        printf("(%d, %d)\n", adject[k], k);
        // 将 k 结点加入生成树
        lowcost[k] = 0;
        // 循环更新 lowcost 的值
        for (j = 1; j < G.vexnum; j++)
            if (lowcost[j] != 0 && G.Edge[k][j] < lowcost[j])
            {
                adject[j] = k;
                lowcost[j] = G.Edge[k][j];
            }
    }
}

int main(void)
{
    MGraph G;
    InitGraph(&G);
    char vexs[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int i;
    for (i = 0; i < sizeof(vexs) / sizeof(char); i++)
        InsertVertex(&G, vexs[i]);
    int edges[][3] = {
        {0, 1, 6},
        {0, 2, 5},
        {0, 3, 1},
        {1, 4, 3},
        {2, 5, 2},
        {3, 1, 5},
        {3, 2, 4},
        {3, 4, 6},
        {3, 5, 4},
        {4, 5, 6}};
    for (i = 0; i < sizeof(edges) / (sizeof(int) * 3); i++)
        AddEdge(&G, edges[i][0], edges[i][1], edges[i][2]);
    MiniSpanTree_Prim(G);
}