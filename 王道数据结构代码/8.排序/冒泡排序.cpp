#include <stdbool.h>
#include <stdio.h>


// 交换
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// 冒泡排序
void BubbleSort(int A[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        bool flag = false;              // 表示本趟冒泡是否发生交换的标志
        for (int j = n - 1; j > i; --j) // 一趟冒泡过程
            if (A[j - 1] > A[j])        // 若为逆序
            {
                swap(A[j - 1], A[j]); // 交换
                flag = true;
            }
        if (flag == false)
            return; // 本趟遍历后没有发生交换，说明表已经有序
    }
}

int main()
{
    int arr[] = {4, 5, 8, 1, 7, 2, 3, 6, 9, 0};
    int len = sizeof(arr) / sizeof(arr[0]);
    BubbleSort(arr, len);

    for (int i = 0; i != len; ++i)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}