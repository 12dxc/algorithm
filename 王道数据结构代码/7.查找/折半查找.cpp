#include <iostream>
#include <vector>
using namespace std;

//折半查找（二分查找）
template <typename T>
int Binary_Search(vector<T> &v, const T t)
{
    int low = 0, high = v.size() - 1, mid;
    while (low <= high)
    {
        mid = (high + low) / 2; //找到中间元素
        if (t > v[mid])
            low = mid + 1; //从前半部分继续查找
        else if (t < v[mid])
            high = mid - 1; //从后半部分继续查找
        else
            return mid; //查找成功则返回所在位置
    }
    return -1;
}

int main()
{
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8};
    cout << Binary_Search(v, 4) << endl;
    return 0;
}