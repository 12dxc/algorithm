#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

// 合并操作
void Merge(int arr[], int l, int m, int r)
{
    // 先开辟数组，用于临时储存归并好的子序列
    int *p = new int[r - l + 1];
    int idx = 0;   // 指向新数组元素的末尾
    int i = l;     // 指向左区间首元素
    int j = m + 1; // 指向右区间首元素

    // 1、重排左右子序列元素顺序
    while (i <= m && j <= r)
    {
        if (arr[i] <= arr[j]) // 如果i小装入新数组，idx和i ++，处理下一个元素
            p[idx++] = arr[i++];
        else // 如果j小装入新数组，idx和j ++，处理下一个元素
            p[idx++] = arr[j++];
    }

    // 2、将未排完元素连接至p末尾
    //  有一个区间未遍历完，因任意区间已归并过，处于有序，则把剩余元素依次添至p末尾
    while (i <= m)
        p[idx++] = arr[i++];
    while (j <= r)
        p[idx++] = arr[j++];

    // 3、把合并好的大段有序的结果，拷贝到原始arr数组[l,r]区间内
    for (i = l, j = 0; i <= r; ++i, ++j) // i、j变量已无用途，故拿来迭代赋值数组元素
        arr[i] = p[j];

    delete[] p;
}
// 归并排序
void MergeSort(int arr[], int begin, int end)
{
    // 递归结束条件
    if (begin >= end)
        return;

    int mid = (begin + end) / 2;
    // 先递
    MergeSort(arr, begin, mid);
    MergeSort(arr, mid + 1, end);
    // 再归并  [begin, mid]、[mid+1, end] 把两个小段有序的序列，合并成大段有序的序列
    Merge(arr, begin, mid, end);
}

// 打印函数
template <typename T>
void print(T arr[], int size)
{
    for (size_t i = 0; i != size; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    // 创建随机数数组
    int arr[10];
    int len = sizeof(arr) / sizeof(arr[0]); // 长度
    srand(time(NULL));
    for (int i = 0; i != 10; ++i)
        arr[i] = rand() % 100 + 1;

    print(arr, len);
    MergeSort(arr, 0, len - 1);
    print(arr, len);

    return 0;
}