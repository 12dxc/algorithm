#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

// 冒泡排序
void BubbleSort(int arr[], int size)
{
    for (int i; i < size - 1; i++) // 趟数
    {
        bool flag = false;
        // 一趟的处理
        for (int j = 0; j < size - 1 - i; j++)  //每次比较会使最大值排到最后，故每轮减少i次（一次）匹配
        {
            if (arr[j] > arr[j + 1])  //如果当前值比下一个值大
            {
                swap(arr[j], arr[j + 1]); //则交换当前值和下一个值
                flag = true;
            }
        }
        if (!flag)  // 如果没有进行数据交换，说明数据已有序
            return; // 直接结束排序
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
    BubbleSort(arr, len);
    print(arr, len);

    return 0;
}