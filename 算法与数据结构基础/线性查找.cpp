#include <iostream>
#include <vector>
using namespace std;

class Linear_search
{
public:
    // 不创建对象，直接调用，需要加static
    static auto search(vector<int> &v, int target)
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

    auto res = Linear_search::search(v, 12);
    cout << "查找的值下标为：" << res << endl;

    res = Linear_search::search(v, 54);
    cout << "查找的值下标为：" << res << endl;

    system("pause");
    return 0;
}