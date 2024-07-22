#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

// 堆的下沉调整
void siftDown(int arr[], int i, int size)
{
    int val = arr[i];
    while (i < size / 2)
    {
        int child = 2 * i + 1;
        // 左半判断是否有右孩子，右半判断右孩子是否大于左孩子
        if (child + 1 < size && arr[child + 1] > arr[child])
        {
            child = child + 1;
        }
        if (arr[child] > val)
        {
            arr[i] = arr[child]; // 孩子节点往上提
            i = child;           // i继续指向它的孩子，继续调整
        }
        else
        {
            break; // 以满足堆性质，则提前结束
        }
    }
    arr[i] = val;
}

// 堆排序  O(logn)
void HeapSort(int arr[], int size)
{
    int n = size - 1; // 末尾元素下标
    // 将传入数组调整为大根堆
    for (int i = (n - 1) / 2; i >= 0; --i) // 从第一个非叶子节点开始
        siftDown(arr, i, size);
    // 把堆底元素与末尾元素交换，从堆顶开始进行下沉操作
    for (int i = n; i > 0; i--)
    {
        //因堆顶元素为堆最小值，故交换堆顶元素和末尾元素，以达成排序
        swap(arr[0], arr[i]); // 末尾元素需变动
        siftDown(arr, 0, i);  // 第三个参数，参与调整元素的个数
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
    HeapSort(arr, len);
    print(arr, len);

    return 0;
}