#include <iostream>
#include <vector>
#include <algorithm> // 为了使用std::swap和std::min_element
using namespace std;

int main()
{

    vector<int> v = {3, 6, 1, 4, 8, 5, 9, 2, 7};

    // 外层循环,遍历数组进行选择排序
    for (int i = 0; i < v.size(); i++)
    {

        // 内层循环,找出从i到末尾最小的值的索引
        int minIndex = i;
        for (int j = i + 1; j < v.size(); j++)
        {

            // 如果找到更小的值,记录其索引
            if (v[j] < v[minIndex])
            {
                minIndex = j;
            }
        }

        // 将找到的最小值交换到当前位置i
        swap(v[i], v[minIndex]);
    }

    // 打印排序后的数组
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}