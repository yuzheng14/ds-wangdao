#if !defined EDGE_H
#define EDGE_H

#define MaxEdgeNum 100

typedef struct
{
    int begin;
    int end;
    int weight;
}ENode, Edge[MaxEdgeNum];

#endif
