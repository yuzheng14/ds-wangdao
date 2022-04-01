#include <limits.h>
#if !defined MATRIX_GRAPH_H
#define MATRIX_GRAPH_H

#define MaxVertexNum 100
#define INF INT_MAX

typedef char VertexType;
typedef int EdgeType;

typedef struct
{
    char Vex[MaxVertexNum];
    int Edge[MaxVertexNum][MaxVertexNum];
    int vexnum, arcnum;
} MGraph;

#endif