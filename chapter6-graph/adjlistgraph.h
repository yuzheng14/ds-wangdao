#include <stdbool.h>

#if !defined ADJLIST_GRAPH_H
#define ADJLIST_GRAPH_H

#define MaxVertexNum 100
typedef char VertexType;
typedef int InfoType;

typedef struct ArcNode
{
    int adjvex;
    struct ArcNode *next;
    // 边权值
    // InfoType info;
} ArcNode;

typedef struct
{
    VertexType data;
    ArcNode *first;
} Vnode, AdjList[MaxVertexNum];

typedef struct
{
    AdjList vertices;
    int vexnum, arcnum;
} ALGraph, Graph;

// 初始化图
void InitGraph(ALGraph *G);
// 向图中插入结点，返回插入结点的索引，若失败则返回 -1
int InsertVertex(ALGraph *G, char data);
// 判断顶点集是否满
bool VextexFull(ALGraph G);
// 向表中添加一条有向边，由 x 指向 y
bool AddEdge(ALGraph *G, int x, int y);
// 下列两个函数无实现，因为个人实现 BFS 和DFS未用到以下两个函数
int FirstNeighbor(ALGraph G, int x);
int NextNeighbor(ALGraph G, int x, int y);
void BFSTraverse(ALGraph G, void (*visit)(Vnode));
void DFSTraverse(ALGraph G, void (*visit)(Vnode));
// BFS算法求无权图单源最短路径
// v 为起始节点
// d 为顶点 v 到各点的最短路径权值
// path 为顶点 v 到各点的最短路径
// d 和 path 的长度需不小于顶点数，否则会导致非法访问或者未知行为
void BFS_MIN_Distance(ALGraph G, int v, int *d, int *path);
// 拓扑排序
// print 为拓扑路径
// 请保证 print 数组长度不小于顶点数，否则会导致非法访问或者未定义行为
// true 为无环路，false 为有环路
bool ToplogicalSort(ALGraph G, int *print);

#endif