#include <iostream>
using namespace std;

// 二分搜索（非递归）
int BinarySearch(int arr[], int size, int val)
{
    int left = 0, right = size - 1; // 指向头和末尾元素
    while (left <= right)
    {
        int mid = (left + right) / 2; // 取中间元素
        if (arr[mid] > val)           // val小于中间值
        {
            right = mid - 1; // 则后半元素无需比较，将right赋值为中间值
            // 因mid已比较过，故越过mid  right-1
        }
        else if (arr[mid] < val) // val大于中间值
        {
            left = mid + 1; // 则前半元素无需比较，将left赋值为中间值
            // 因mid已比较过，故越过mid  left+1
        }
        else // val等于中间值
        {
            return mid;
        }
    }
    return -1; // 数组中无此值
}
// 二分搜索（递归写法）
//递归必须分解问题，故参数需是一个范围
int BinarySearch(int arr[], int left, int right, int val)
{
    // 循环终止条件
    if (left > right) // 当左指针越过右指针，故全部比较过，val不存在
        return -1;

    int mid = (left + right) / 2;
    if (arr[mid] > val)
        return BinarySearch(arr, left, mid - 1, val);
    else if (arr[mid] < val)
        return BinarySearch(arr, mid + 1, right, val);
    else
        return mid;
}

int main()
{
    int arr[] = {12, 25, 34, 39, 45, 57, 63, 78, 82, 96, 100};
    int len = sizeof(arr) / sizeof(arr[0]);
    cout << BinarySearch(arr, len, 25) << endl;
    cout << BinarySearch(arr, 0, len - 1, 45) << endl;

    return 0;
}