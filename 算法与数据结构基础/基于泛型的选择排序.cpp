#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 加入模板，使其能对任意类型的向量进行排序
template <typename T>
void selectSort(vector<T> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[j] < v[minIndex])
            {
                minIndex = j;
            }
        }

        swap(v[i], v[minIndex]);
    }
}

int main()
{

    vector<int> vInt = {3, 6, 1, 4, 8, 5, 9, 2, 7};

    selectSort<int>(vInt);

    for (auto it = vInt.begin(); it != vInt.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    vector<string> vStr = {"hello", "word", "count", "exec"};
    selectSort<string>(vStr);

    for (auto it = vStr.begin(); it != vStr.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}