#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*1,3,5分的硬币，现在给定一个价值c：11，问组成少价值c需要的最的硬币的数量？？？*/
int main()
{
    /*使用贪心算法，每次都选择最优解，以此得到全局优解。
     *即每次都选5，直到不满足5才选更小面值的硬币*/
    vector<int> v = {1, 3, 5}; // 硬币面值
    int c = 11;
    sort(v.begin(), v.end(), [](int a, int b) -> bool
         { return a > b; }); // 倒序排列，最大面值排前面

    int idx = 0; // 5 3 1  记录正在使用的面值
    int cnt = 0; // 记录硬币个数
    while (c > 0)
    {
        if (c >= v[idx])
        {
            c -= v[idx]; // 减去现有面值
            cnt++;       // 增加硬币数
        }
        else
        {
            idx++; // 如果硬币面值低于剩余金额，则换更小的硬币
        }
    }

    cout << "兑换11最少需要" << cnt << "个硬币" << endl;

    return 0;
}