#if !defined SORT_H
#define SORT_H

#define BIG 1
#define EQUAL 0
#define SMALL -1

typedef int SortType;

// 直接插入排序
void InsertSort(SortType A[],int n,int (*compare)(SortType a,SortType b));

#endif