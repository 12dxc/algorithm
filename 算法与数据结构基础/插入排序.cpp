#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cstdlib>
using namespace std;

// 模板类,用于实现插入排序算法
// 模板参数T表示可以对任意类型的数据进行排序
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
            // 内层for循环:将当前元素插入到正确位置
            for (int j = i; j - 1 >= 0; j--)
            {
                // 如果当前元素小于前一个元素,交换两个元素
                if (v[j] < v[j - 1])
                {
                    swap(v[j], v[j - 1]);
                }
                // 否则说明已经找到了正确位置,退出内层循环
                else
                {
                    break;
                }
            }
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

            int r = rand(); // 生成随机数
            v.push_back(r);
        }
    }
};

int main()
{
    srand(time(0)); // 设置种子

    // 定义整数向量并初始化
    vector<int> v;
    InsertSort<int>::addArr(v, 10000);

    auto begin = chrono::high_resolution_clock::now();

    // 调用插入排序算法对向量进行排序
    InsertSort<int>::sort(v);

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::seconds>(end - begin);

    printf("%f\n", elapsed.count());

    // 调用打印函数输出排序后的向量
    // InsertSort<int>::myPrint(v);

    system("pause");
    return 0;
}