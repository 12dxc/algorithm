#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


void Merge(int A[], int low, int mid, int high);
const int n = 100;
int *B = NULL; // 辅助数组B

// 归并排序
void MergeSort(int A[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;  // 从中间划分
        MergeSort(A, low, mid);      // 对左半部分归并排序
        MergeSort(A, mid + 1, high); // 对右半部分归并排序
        Merge(A, low, mid, high);    // 归并
    }
}
void Merge(int A[], int low, int mid, int high)
{
    int i, j, k;
    for (k = low; k <= high; k++)
        B[k] = A[k]; // 将A数组的元素复制到B中
    for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++)
    {
        if (B[i] <= B[j])
            A[k] = B[i++]; // 将较小值复制到A中
        else
            A[k] = B[j++];
    }
    while (j <= mid)
        A[k++] = B[i++];
    while (j <= high)
        A[k++] = B[j++];
}

int main()
{
    B = (int *)malloc(n * sizeof(int));
    int arr[] = {4, 5, 8, 1, 7, 2, 3, 6, 9, 0};
    int len = sizeof(arr) / sizeof(arr[0]);
    MergeSort(arr, 0, len - 1);

    for (int i = 0; i != len; ++i)
        printf("%d ", i);
    printf("\n");

    return 0;
}