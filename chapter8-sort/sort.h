#if !defined SORT_H
#define SORT_H

#define BIG 1
#define EQUAL 0
#define SMALL -1

typedef int SortType;

// 直接插入排序
void InsertSort(SortType A[], int n, int (*compare)(SortType a, SortType b));
// 折半插入排序（直接插入排序的优化）
void BinaryInsertSort(SortType A[], int n,
                      int (*compare)(SortType a, SortType b));
// 希尔排序
void ShellSort(SortType A[], int n, int (*compare)(SortType a, SortType b));
// 冒泡排序
void BubbleSort(SortType A[], int n, int (*compare)(SortType a, SortType b));
// 快速排序
void QuickSort(SortType A[], int n, int (*compare)(SortType a, SortType b));

#endif