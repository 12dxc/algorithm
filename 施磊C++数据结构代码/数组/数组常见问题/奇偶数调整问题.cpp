#include <iostream>
#include <memory>
using namespace std;

// 问题：给定一个整形数组，将偶数放在数组左边，奇数放在数组右边
void AdjustArray(int arr[], int size)
{
    int *p = arr;
    int *q = arr + size - 1;
    while (p < q)
    {
        // p ->奇数
        if (*p % 2 == 0)
        {
            ++p;
            continue;
        }
        // q ->偶数
        if (*q % 2 != 0)
        {
            --q;
            continue;
        }
        // 执行交换
        int temp = *p;
        *p = *q;
        *q = temp;
        // 交换完，继续迭代
        ++p, --q;
    }
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    AdjustArray(arr, 10);

    for (auto i : arr)
        cout << i << " ";
    cout << endl;

    return 0;
}
