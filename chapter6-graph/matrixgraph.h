#include <limits.h>
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

int FirstNeighbor(MGraph G, int x);
int NextNeighbor(MGraph G, int x, int y);

#endif