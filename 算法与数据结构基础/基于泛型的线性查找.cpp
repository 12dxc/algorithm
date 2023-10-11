#include <iostream>
#include <vector>
using namespace std;

// 使用泛型让线性查找适用于所有的类型
template <typename T>
class Linear_search
{
public:
    static auto search(vector<T> &v, T target)
    {
        for (auto i = 0; i < v.size(); i++)
        {
            if (v[i] == target)
            {
                // 找到目标返回下标
                return i;
            }
        }
        // 未找到目标，返回-1
        return -1;
    }
};

int main()
{
    vector<int> v = {12, 32, 43, 54, 61, 23, 76, 18};

    auto res = Linear_search<int>::search(v, 12);
    cout << "要查找的值的下标为：" << res << endl;

    vector<string> vs = {"张三", "李四", "王五", "赵六"};
    auto resStr = Linear_search<string>::search(vs, "李四");
    cout << "要查找的值的下标为：" << resStr << endl;

    system("pause");
    return 0;
}