#include "dlinklist.h"

bool InitDLinkList(DLinklist *L)
{
    (*L)=(DNode *)malloc(sizeof(DNode));
    if(!(*L))
        return false;
    (*L)->next=NULL;
    (*L)->piror=NULL;
    return true;
}