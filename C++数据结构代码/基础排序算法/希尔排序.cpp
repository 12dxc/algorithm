#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

// 希尔排序  是插入排序的一种优化通过比较相距一定间隔的元素来进行，
// 各趟比较所用的距离随着算法的进行而减小，直到只比较相邻元素的最后一趟排序为止
void ShellSort(int arr[], int size)
{
    for (int gap = size / 2; gap > 0; gap /= 2) // 使用gap进行分组，每次/2,以此越分越细
    {
        for (int i = gap; i < size; i++) // 间隔gap开始迭代
        {
            int val = arr[i]; // 保存要比较的当前值，以免在移动中被覆盖
            int j = i - gap;  // 从当前值，一直往前遍历，每次迭代间隔gap
            for (; j >= 0; j -= gap)
            {
                if (arr[j] <= val) // 如果前面的值都比当前值小，故退出此次比较
                    break;
                // 否则，进行后移
                arr[j + gap] = arr[j];
            }
            // 因为遍历的是当前值的前一值，故需加1才为指定位置
            arr[j + gap] = val; // 将要插入的元素放到找到的位置
        }
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
    ShellSort(arr, len);
    print(arr, len);

    return 0;
}