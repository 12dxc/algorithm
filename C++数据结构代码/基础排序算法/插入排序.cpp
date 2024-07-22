#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

// 插入排序 基本思想是将一个未排序的元素插入到一个已排序的序列中，使得新的序列仍然有序
void InsertSort(int arr[], int size)
{
    for (int i = 1; i < size; i++) // 用一个循环遍历数组的每个位置，从第二个元素开始，i表示当前要插入的元素
    {
        int val = arr[i];   // 保存当前要插入的元素的值
        int j = i - 1;      // 用一个变量j表示已排序的序列的最后一个元素的下标
        for (; j >= 0; j--) // 用一个循环从后向前扫描已排序的序列
        {
            if (arr[j] <= val) // 如果已排序的元素小于或等于要插入的元素
            {
                break; // 则跳出循环，找到了要插入的位置
            }
            arr[j + 1] = arr[j]; // 否则，将已排序的元素后移一位，为要插入的元素腾出空间
        }
        arr[j + 1] = val; // 将要插入的元素放到找到的位置
    }
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
    InsertSort(arr, len);
    print(arr, len);

    return 0;
}