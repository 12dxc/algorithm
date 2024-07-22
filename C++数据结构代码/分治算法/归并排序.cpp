#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

// 合并划分序列
void Merge(vector<int> &vec, int low, int high, int mid)
{
    // 定义辅助数组，存储合并好的划分序列
    vector<int> temp;

    int i = low;
    int j = mid + 1;

    while (i <= mid && j <= high)
    {
        if (vec[i] > vec[j]) // 左序列更大；则先将右序列元素加入数组，并指向其下一元素
        {
            temp.push_back(vec[j++]);
        }
        else // 右序列更大；则先将左序列元素加入数组，并指向其下一元素
        {
            temp.push_back(vec[i++]);
        }
    }
    // 判断哪个序列未排完，将序列排至数组末尾
    while (i <= mid)
    {
        temp.push_back(vec[i++]);
    }
    while (j <= high)
    {
        temp.push_back(vec[j++]);
    }

    // 最后将合并好的序列，加入原数组
    for (int k = low; k <= high; ++k)
    {
        vec[k] = temp[k - low];
    }
}
// 归并排序
void MergeSort(vector<int> &vec, int l, int r)
{
    if (l >= r)
        return;
    // 归并划分
    int mid = (l + r) / 2;
    MergeSort(vec, l, mid);
    MergeSort(vec, mid + 1, r);

    // 合并
    Merge(vec, l, r, mid);
}
int main()
{
    vector<int> v;
    for (int i = 0; i != 10; ++i)
        v.push_back(rand() % 100);

    for (auto i : v)
        cout << i << " ";
    cout << endl;

    MergeSort(v, 0, v.size() - 1);

    // 打印排好序列
    for (auto i : v)
        cout << i << " ";
    cout << endl;

    return 0;
}