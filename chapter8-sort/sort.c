#include "sort.h"

void swap(SortType *a, SortType *b) {
    SortType temp = *a;
    *a = *b;
    *b = temp;
}

void InsertSort(SortType A[], int n, int (*compare)(SortType a, SortType b)) {
    int i, j;
    SortType temp;
    // 将各元素插入到已经排好序的序列中（指前面的所有元素）
    for (i = 1; i < n; i++) {
        // 如果当前元素关键字比前驱小，即不调换位置的话序列无序
        if (compare(A[i], A[i - 1]) == SMALL) {
            temp = A[i];
            // 数据移位
            for (j = i - 1; j >= 0 && compare(A[j], temp) == BIG; j--)
                A[j + 1] = A[j];
            A[j + 1] = temp;
        }
    }
}