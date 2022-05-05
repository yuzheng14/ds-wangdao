#include "sort.h"

#include <stdbool.h>

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

void BinaryInsertSort(SortType A[], int n,
                      int (*compare)(SortType a, SortType b)) {
    int i, j, low, high, mid;
    SortType temp;
    for (i = 1; i < n; i++) {
        temp = A[i];
        while (low <= high) {
            mid = high / 2 + low / 2;
            if (compare(A[mid], temp) == BIG)
                high = mid - 1;
            else
                low = mid + 1;
        }
        for (j = i - 1; j >= low; --j) A[j + 1] = A[j];
        A[low] = temp;
    }
}

void ShellSort(SortType A[], int n, int (*compare)(SortType a, SortType b)) {
    int i, j, d;
    SortType temp;
    for (d = n / 2; d >= 1; d /= 2) {
        for (i = d; i < n; i++) {
            if (compare(A[i], A[i - d]) == SMALL) {
                temp = A[i];
                for (j = i - d; j >= 0 && compare(A[j], temp) == BIG; j -= d)
                    A[j + d] = A[j];
                A[j + d] = temp;
            }  // if
        }      // for i
    }          // for d
}

void BubbleSort(SortType A[], int n, int (*compare)(SortType a, SortType b)) {
    int i, j;
    bool flag = true;
    // 控制循环次数
    for (i = 0; i < n - 1 && flag; i++) {
        flag = false;
        // 控制对比
        for (j = n - 1; j > i; j--) {
            if (compare(A[j - 1], A[j]) == BIG) {
                swap(&A[j - 1], &A[j]);
                flag = true;
            }
        }
    }
}