#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

template <class T>
class InsertSort
{
public:
    // 插入排序函数
    // 对传入的向量v进行排序
    static void sort(vector<T> &v)
    {
        // 外层for循环:遍历向量的每个元素
        for (int i = 0; i < v.size(); i++)
        {
            T temp = v[i];
            int j;
            for (j = i; i - 1 >= 0 && temp < v[j - 1]; j--)
            {
                v[j] = v[j - 1];
            }
            v[j] = temp;
        }
    }

    // 打印函数
    // 打印排序后的向量内容
    static void myPrint(vector<T> &v)
    {
        // 使用迭代器遍历向量
        for (auto it = v.begin(); it != v.end(); it++)
        {
            // 输出当前元素
            cout << *it << " ";
        }
        // 打印换行
        cout << endl;
    }
    // 生成数组
    static void addArr(vector<T> &v, int len)
    {
        for (int i = 0; i < len; i++)
        {

            int r = rand() % 100; // 生成随机数
            v.push_back(r);
        }
    }
};

int main()
{
    srand((unsigned)time(NULL));

    // 定义整数向量并初始化
    vector<int> v;
    InsertSort<int>::addArr(v, 10);

    // 调用插入排序算法对向量进行排序
    InsertSort<int>::sort(v);

    // 调用打印函数输出排序后的向量
    InsertSort<int>::myPrint(v);

    system("pause");
    return 0;
}