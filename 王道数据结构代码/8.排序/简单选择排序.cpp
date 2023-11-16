#include <bits/stdc++.h>

// 简单选择排序
void SelectSort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++) // 一共进行n-1趟
    {
        int min = i;                    // 记录最小元素位置
        for (int j = i + 1; j < n; j++) // 在A[i...n-1]中选择最小的元素
            if (A[j] < A[min])          // 更新最小元素位置
                min = j;
        if (min != i) // 移动元素
            std::swap(A[i], A[min]);
    }
}

int main()
{
    int arr[] = {4, 5, 8, 1, 7, 2, 3, 6, 9, 0};
    int len = sizeof(arr) / sizeof(arr[0]);
    SelectSort(arr, len);

    for (auto i : arr)
        printf("%d ", i);
    printf("\n");

    return 0;
}