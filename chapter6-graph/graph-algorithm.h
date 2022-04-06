#include <stdbool.h>
#include "../chapter3-stack-queue-array/linkqueue.h"
#if !defined GRAPH_ALGORITHM_H
#define GRAPH_ALGORITHM_H

#if !defined ADJLIST_GRAPH_H || !defined MATRIX_GRAPH_H
#include "matrixgraph.h"
#endif

bool visited[MaxVertexNum];
LinkQueue Q;

void BFSTraverse(Graph G, void (*visit)(int));
void BFS(Graph G, int v, void (*visit)(int));
void DFSTraverse(Graph G, void (*visit)(int));
void DFS(Graph G, int v, void (*visit)(int));

#endif