#include <stdio.h>
#include <stdbool.h>

#include "sqlist.h"

bool DeleteMinimum(SqList *L,ElemType *e)
{
    if((*L).length<=0)
    {
        // puts("The length of Sqlist is 0!\n");
        return false;
    }
    int i,min=0;
    for(i=1;i<(*L).length;i++)
    {
        if((*L).data[i]<(*L).data[min])
            min=i;
    }
    *e=(*L).data[i];
    (*L).data[i]=(*L).data[(*L).length-1];
    (*L).length--;
    return true;
}

bool reverse_list(SqList *L)
{
    int i;
    ElemType temp;
    for (i=0;i<(*L).length/2;i++)
    {
        temp=(*L).data[i];
        (*L).data[i]=(*L).data[(*L).length-i-1];
        (*L).data[(*L).length-i-1]=temp;
    }
    return true;
}

bool delete(SqList *L)
{
    
}