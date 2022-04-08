#include "matrixgraph.h"
#include "edge.h"

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

// 交换元素
void swap(Edge E, int a, int b)
{
    ENode temp;
    temp = E[a];
    E[a] = E[b];
    E[b] = temp;
}

// 快排
void quick_sort(Edge E, int left, int right)
{
    int i = left, j = right;
    while (i < j)
    {
        ENode temp = E[left];
        while (E[j].weight > temp.weight && i < j)
            j--;
        while (E[i].weight <= temp.weight && i < j)
            i++;
        swap(E, i, j);
    }

    if (left < right)
    {
        swap(E, left, i);
        quick_sort(E, left, i - 1);
        quick_sort(E, i + 1, right);
    }
}

// 并查集查操作
int find(int *parent, int v)
{
    while (parent[v] > -1)
        v = parent[v];
    return v;
}

// 邻接矩阵转换为边集数组
void MGraph2Edge(MGraph G, Edge E)
{
    int i, j;
    int k = 0;

    for (i = 0; i < G.vexnum - 1; i++)
        for (j = i + 1; j < G.vexnum; j++)

            if (G.Edge[i][j] != INF)
            {
                E[k].begin = i;
                E[k].end = j;
                E[k++].weight = G.Edge[i][j];
            }
}

// Kruscal 算法
void MiniSpanTree_Kruskal(MGraph G)
{
    Edge E;
    // 将邻接矩阵转换成边集数组
    MGraph2Edge(G, E);
    // 并查集，用于判断两个结点之间是否已经连通
    int parent[G.vexnum];
    int i, n, m;
    // 初始化并查集
    for (i = 0; i < G.vexnum; i++)
        parent[i] = -1;
    // 对边集数组进行排序
    quick_sort(E, 0, G.arcnum - 1);
    // 对边集数组中的每一条边判断
    // 从最小的边开始
    // 如果两个点没有连通则将该条边加入生成树
    for (i = 0; i < G.arcnum; i++)
    {
        n = find(parent, E[i].begin);
        m = find(parent, E[i].end);
        if (n != m)
        {
            printf("(%d, %d) %d\n", E[i].begin, E[i].end, E[i].weight);
            parent[n] = m;
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
    MiniSpanTree_Kruskal(G);
    return 0;
}