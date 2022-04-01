#if !defined MATRIX_GRAPH_H
#define MATRIX_GRAPH_H

#define MaxVertexNum 100

typedef struct
{
    char Vex[MaxVertexNum];
    int Edge[MaxVertexNum][MaxVertexNum];
    int vexnum, arcnum;
} MGraph;

#endif