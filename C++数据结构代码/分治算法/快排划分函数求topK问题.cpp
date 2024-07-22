#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

// 快排分割函数
int Partation(vector<int> &vec, int l, int r)
{
    // 优化方法2：三数取中法，旨在挑选合适的基准数，防止快排退化成冒泡排序。即在left、mid、right中取中间值，作为基准值。
    int val = vec[l]; // 记录基准数
    // 一次快排处理
    while (l < r)
    {
        // 从r开始往前找第一个 < val的数字
        while (l < r && vec[r] > val)
            r--;
        // 放到l的地方，l++
        if (l < r)
        {
            vec[l] = vec[r];
            l++;
        }
        // 从l开始往后找第一个 > val的数字
        while (l < r && vec[l] < val)
            l++;
        // 放到r的地方，r--
        if (l < r)
        {
            vec[r] = vec[l];
            r--;
        }
    }
    // l == r的位置，就是放基准数的位置
    vec[l] = val;
    return l;
}
// 找第k大的，即vec.size()-k的下标
int max_selectTopK(vector<int> &vec, int i, int j, int k)
{
    int pos = Partation(vec, i, j); // pos表示基准数位置
    if (pos == vec.size() - k)      // 找到了 基准数的位置和topK的k值相等了
    {
        return vec[pos];
    }
    else if (pos < vec.size() - k) // topK应在基准数右边
    {
        return max_selectTopK(vec, pos + 1, j, k);
    }
    else // topK应在基准数左边
    {
        return max_selectTopK(vec, i, pos - 1, k);
    }
}

int main()
{
    vector<int> v;
    for (int i = 0; i != 20; ++i)
        v.push_back(rand() % 100);

    // 求第top 10大的元素
    int val = max_selectTopK(v, 0, v.size() - 1, 10);
    cout << "val: " << val << endl;

    // 打印排好序列
    sort(v.begin(), v.end());
    for (auto i : v)
        cout << i << " ";
    cout << endl;

    return 0;
}