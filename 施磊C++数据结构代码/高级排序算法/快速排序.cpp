#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

// 快排分割函数
int Partation(int arr[], int l, int r)
{
    //优化方法2：三数取中法，旨在挑选合适的基准数，防止快排退化成冒泡排序。即在left、mid、right中取中间值，作为基准值。
    int val = arr[l]; // 记录基准数
    // 一次快排处理
    while (l < r)
    {
        // 从r开始往前找第一个 < val的数字
        while (l < r && arr[r] > val)
            r--;
        // 放到l的地方，l++
        if (l < r)
        {
            arr[l] = arr[r];
            l++;
        }
        // 从l开始往后找第一个 > val的数字
        while (l < r && arr[l] < val)
            l++;
        // 放到r的地方，r--
        if (l < r)
        {
            arr[r] = arr[l];
            r--;
        }
    }
    // l == r的位置，就是放基准数的位置
    arr[l] = val;
    return l;
}

/*快速排序  基本思想：选取一个基准数，把小于基准数的元素调整到基准数的左边，
把大于基准数的元素调整到基准数右边,然后对基准数左边和右边的序列继续进行这样的操作，直至整个序列变有序*/
void QuickSort(int arr[], int begin, int end)
{
    if (begin >= end) // 快排递归结束的条件
        return;

    // 优化方法1: 对于小段趋于有序的序列采用插入排序
    /*if (end - begin <= 50)
        InsertSort(int arr,int size);*/

    // 在[begin, end]区间的元素做一次快排分割处理
    int pos = Partation(arr, begin, end);
    // 对基准数的左边和右边的序列，再分别进行快排
    QuickSort(arr, begin, pos - 1);
    QuickSort(arr, pos + 1, end);
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
    QuickSort(arr, 0, len - 1);
    print(arr, len);

    return 0;
}