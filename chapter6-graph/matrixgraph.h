#include <limits.h>
#include <stdio.h>
#include <stdbool.h>
#if !defined MATRIX_GRAPH_H
#define MATRIX_GRAPH_H

#define MaxVertexNum 100
#define INF INT_MAX

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

#endif