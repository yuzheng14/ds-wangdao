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
} ALGraph;

#endif