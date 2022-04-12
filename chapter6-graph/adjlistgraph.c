#include <stdlib.h>
#include <limits.h>
#include "adjlistgraph.h"
#include "../chapter3-stack-queue-array/linkqueue.h"
#define LinkNode LiNode
#include "../chapter3-stack-queue-array/listack.h"

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

bool AddEdge(ALGraph *G, int x, int y, int info)
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
        current->info = info;
        current->next = NULL;
        G->vertices[x].first = current;
    }
    else
    {
        for (current = G->vertices[x].first; current->next; current = current->next)
            ;
        ArcNode *new = (ArcNode *)malloc(sizeof(ArcNode));
        new->adjvex = y;
        new->info = info;
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
    // 初始化数组
    for (i = 0; i < G.vexnum; i++)
    {
        visited[i] = false;
        d[i] = INF;
        path[i] = -1;
    }
    LinkQueue Q;
    InitQueue(&Q);
    d[v] = 0;
    visited[v] = true;
    EnQueue(&Q, v);
    // BFS 算法
    while (!QueueEmpty(Q))
    {
        DeQueue(&Q, &v);
        ArcNode *current;
        for (current = G.vertices[v].first; current; current = current->next)
        {
            if (!visited[current->adjvex])
            {
                // 将计算该节点的路径长度
                d[current->adjvex] = d[v] + 1;
                // 存储该节点的路径
                path[current->adjvex] = v;
                visited[current->adjvex] = true;
                EnQueue(&Q, current->adjvex);
            }
        }
    }
}

void compute_in_array(ALGraph G, int *in)
{
    int i;
    ArcNode *current;
    for (i = 0; i < G.vexnum; i++)
        in[i] = 0;
    for (i = 0; i < G.vexnum; i++)
        for (current = G.vertices[i].first; current; current = current->next)
            in[current->adjvex]++;
}

bool ToplogicalSort_Complete(ALGraph G, int *print, int *ve)
{
    int in[G.vexnum];
    int i;
    // 求入度数组
    compute_in_array(G, in);
    // 初始化
    for (i = 0; i < G.vexnum; i++)
        print[i] = -1;
    // 如果 ve 存在，则初始化 ve，事件的最早发生时间
    if (ve)
        for (i = 0; i < G.vexnum; i++)
            ve[i] = 0;
    LiStack S;
    InitStack(&S);
    // 将入度为 0 的结点压入栈
    for (i = 0; i < G.vexnum; i++)
        if (in[i] == 0)
            Push(&S, i);
    int k;
    i = 0;
    // 栈中不为空则一直循环
    while (!StackEmpty(S))
    {
        // 从栈中取出入度为 0 的结点
        Pop(&S, &k);
        // 将该节点加入拓扑排序
        print[i++] = k;
        ArcNode *current;
        // 遍历该结点直接到达结点
        for (current = G.vertices[k].first; current; current = current->next)
        { // 入度 -1，如果入度为 0 则压入栈
            if (--in[current->adjvex] == 0)
                Push(&S, current->adjvex);
            // 如果 ve 存在，则计算事件最早发生时间（=max{到达该结点的最早发生时间 + 活动的时间}
            if (ve)
                if (ve[k] + current->info > ve[current->adjvex])
                    ve[current->adjvex] = ve[k] + current->info;
        }
    }
    // 如果拓扑排序中的结点数 == 顶点数，则返回true
    if (i == G.vexnum)
        return true;
    else
        return false;
}

bool ToplogicalSort(ALGraph G, int *print)
{
    return ToplogicalSort_Complete(G, print, NULL);
}

void CriticalPath(ALGraph G)
{
    // 活动的最早/晚发生时间
    int e, l;
    // 事件的最早/晚发生事件
    int ve[G.vexnum], vl[G.vexnum];
    // 拓扑排序数组
    int print[G.vexnum];
    ToplogicalSort_Complete(G, print, ve);
    // 将 vl 初始化为 INF
    int i;
    for (i = 0; i < G.vexnum; i++)
        vl[i] = ve[print[G.vexnum - 1]];
    // 循环遍历拓扑排序
    ArcNode *current;
    for (i = G.vexnum - 1; i >= 0; i--)
        for (current = G.vertices[print[i]].first; current; current = current->next)
            if (vl[current->adjvex] - current->info < vl[print[i]])
                vl[print[i]] = vl[current->adjvex] - current->info;

    for (i = 0; i < G.vexnum; i++)
        for (current = G.vertices[i].first; current; current = current->next)
        {
            e = ve[i];
            l = vl[current->adjvex] - current->info;
            if (e == l)
                printf("<%d, %d> %d\n", i, current->adjvex, current->info);
        }
}

// void print(Vnode v)
// {
//     printf("%-2c", v.data);
// }

int main(void)
{
    ALGraph G;
    InitGraph(&G);
    //     char vexs[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};
    //     int edges[][2] = {
    //         {1, 5},
    //         {1, 2},
    //         {2, 6},
    //         {6, 3},
    //         {6, 7},
    //         {7, 4},
    //         {4, 8},
    //         {7, 8},
    //         {3, 4},
    //         {3, 7}};
    //     int i;
    //     for (i = 0; i < 8; i++)
    //         InsertVertex(&G, vexs[i]);
    //     for (i = 0; i < 10; i++)
    //     {
    //         AddEdge(&G, edges[i][0], edges[i][1]);
    //         AddEdge(&G, edges[i][1], edges[i][0]);
    //     }
    //     BFSTraverse(G, print);
    //     putchar('\n');
    //     DFSTraverse(G, print);
    //     putchar('\n');
    //     int d[G.vexnum], path[G.vexnum];
    //     BFS_MIN_Distance(G, 2, d, path);
    //     for (i = 0; i < G.vexnum; i++)
    //         printf("%-2d", d[i]);
    //     putchar('\n');
    //     for (i = 0; i < G.vexnum; i++)
    //         printf("%-2d", path[i]);
    //     putchar('\n');

    // 拓扑排序测试
    // char vexs[] = {'0', '1', '2', '3', '4'};
    // int edges[][3] = {
    //     {0, 1, 1},
    //     {1, 3, 1},
    //     {3, 4, 1},
    //     {2, 3, 1},
    //     {2, 4, 1}};
    // int print[G.vexnum];
    // int i;
    // for (i = 0; i < 5; i++)
    //     InsertVertex(&G, vexs[i]);
    // for (i = 0; i < 5; i++)
    //     AddEdge(&G, edges[i][0], edges[i][1]);
    // if (ToplogicalSort(G, print))
    //     puts("拓扑排序成功！");

    // for (i = 0; i < G.vexnum; i++)
    //     printf("%-3d", print[i]);
    // putchar('\n');
    char vexs[] = {'1', '2', '3', '4', '5', '6'};
    int edges[][3] = {
        {1, 2, 3},
        {1, 3, 2},
        {2, 4, 2},
        {2, 5, 3},
        {3, 4, 4},
        {3, 6, 3},
        {4, 6, 2},
        {5, 6, 1}};
    int i;
    for (i = 0; i < 6; i++)
        InsertVertex(&G, vexs[i]);
    for (i = 0; i < 8; i++)
        AddEdge(&G, edges[i][0] - 1, edges[i][1] - 1, edges[i][2]);
    CriticalPath(G);
    return 0;
}