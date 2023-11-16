#include <stdio.h>
#include <stdbool.h>

// 希尔排序
void ShellSort(int A[], int n)
{
    int d, i, j;
    // A[0]只是暂存单元，不是哨兵，当j<=0时，插入位置已到
    for (d = n / 2; d >= 1; d = d / 2) // 步长变化
        for (i = d + 1; i <= n; ++i)
            if (A[i] < A[i - d]) // 需将A[i]插入有序增量子表
            {
                A[0] = A[i]; // 暂存在A[0]
                for (j = i - d; j > 0 && A[0] < A[j]; j -= d)
                    A[j + d] = A[j]; // 记录后移，查找插入的位置
                A[j + d] = A[0];     // 插入
            }
}

int main()
{
    int arr[] = {4, 5, 8, 1, 7, 2, 3, 6, 9, 0};
    int len = sizeof(arr) / sizeof(arr[0]);
    ShellSort(arr, len);

    for (int i = 0; i != len; ++i)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}