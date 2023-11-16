#include <stdio.h>

// 直接插入排序
void InsertSort(int A[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)  // 将各元素插入已排好序的序列中
        if (A[i] < A[i - 1]) // 将A[i]关键字小于前驱
        {
            temp = A[i];                                // 用temp暂存A[i]
            for (j = i - 1; j >= 0 && A[j] > temp; --j) // 检查所有前面已排好序的元素
                A[j + 1] = A[j];                        // 所有大于temp的元素向后挪位
            A[j + 1] = temp;                            // 复制到插入位置
        }
}
// 折半插入排序（优化）
void InsertSort2(int A[], int n)
{
    int i, j, low, high, mid;
    for (i = 2; i <= n; i++) // 依次将A[2]~A[n]插入前面的已排序序列
    {
        A[0] = A[i]; // 将A[i]暂存到A[0]
        low = 1;     // 设置折半查找范围
        high = i - 1;
        while (low <= high) // 折半查找（默认递增有序）
        {
            mid = (low + high) / 2; // 取中间点
            if (A[mid] > A[0])      // 查找左半子表
                high = mid - 1;
            else // 查找右半子表
                low = mid + 1;
        }
        for (j = i - 1; j >= high; --j)
            A[j + 1] = A[j]; // 统一后移操作，空出插入位置
        A[high + 1] = A[0];  // 插入操作
    }
}

int main()
{
    int arr[] = {2, 6, 1, 4, 9, 5, 0, 7, 8, 3};
    int len = sizeof(arr) / sizeof(arr[0]);
    InsertSort(arr, len);
    for (int i = 0; i != len; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}