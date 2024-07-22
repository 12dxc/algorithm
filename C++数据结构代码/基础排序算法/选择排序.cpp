 #include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

// 选择排序  基本思想是每次从未排序的部分中找出最小的元素，然后与当前位置的元素交换，直到所有元素都排好序
void ChoiceSort(int arr[], int size)
{
    for (int i = 0; i < size-1; i++) // 用一个循环遍历数组的每个位置，i表示当前要排序的位置
    {
        int min = arr[i];              // 最小值，初始化为当前位置的元素
        int k = i;                     // 最小值下标，初始化为当前位置的下标
        for (int j = i; j < size; j++) // 用另一个循环从当前位置开始向后查找最小的元素
        {
            if (arr[j] < min) // 当前值比min更小
            {
                // 更新最小值和其下标
                min = arr[j]; // 将当前值赋给min
                k = j;        // 将当前下标赋给k
            }
        }
        if (k != i)               // 如果k发生了变化，说明找到了比当前位置更小的元素
            swap(arr[i], arr[k]); // 则交换k与i的数组元素
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
    ChoiceSort(arr, len);
    print(arr, len);

    return 0;
}