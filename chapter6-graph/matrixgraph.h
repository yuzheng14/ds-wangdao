#include <limits.h>
#include <stdio.h>
#include <stdbool.h>
#if !defined MATRIX_GRAPH_H
#define MATRIX_GRAPH_H

#define MaxVertexNum 100
#define INF (INT_MAX / 2 - 1)

typedef char VertexType;
typedef int EdgeType;

typedef struct
{
    VertexType Vex[MaxVertexNum];
    EdgeType Edge[MaxVertexNum][MaxVertexNum];
    int vexnum, arcnum;
} MGraph, Graph;

// 下列两个函数未实现
int FirstNeighbor(MGraph G, int x);
int NextNeighbor(MGraph G, int x, int y);
void MiniSpanTree_Prim(MGraph G);
bool AddEdge(MGraph *G, int x, int y, int info);
void InitGraph(MGraph *G);
int InsertVertex(MGraph *G, VertexType v);
void MiniSpanTree_Kruskal(MGraph G);
// Dijkstra算法求单源最短路径
// v 为起始顶点
// distance 为路径长度
// path 为路径
// 请确保 distance 和 path 数组长度不小于顶点长度
void ShortestDistance_Dijkstra(MGraph G, int v, int *distance, int *path);

#endif