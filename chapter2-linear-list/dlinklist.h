#include <stdio.h>

#if !defined DLINKLIST_H
#define DLINKLIST_H

#if !defined ELEMTYPE
#define ELEMTYPE
typedef int ElemType;
#endif


typedef struct DNode{
    ElemType data;
    struct DNode *next,*piror;
 } DNode, *DLinklist;

#endif