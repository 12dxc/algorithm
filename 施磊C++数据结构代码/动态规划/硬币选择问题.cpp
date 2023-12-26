#include <iostream>
#include <vector>
using namespace std;

/*
硬币选择问题：有1，3，5分面额的硬币，给定一个面值11，问组成给定面值所需要的最少的硬币数量是多少？？？
dp[i]: 组成面值i需要的硬币最少数量
*/

/*
问题的状态：dp[i] 组成面值i所需要的最少的硬币数量
状态转移方程：
dp[0] = 0
dp[1] = 1 + dp[1-1] = 1
dp[2] = 1 + dp[2-1] = 1 + dp[1] = 1 + 1 = 2
dp[3] :
           1 + dp[3-1] = 1 + dp[2] = 1 + 2 = 3    选择了3个1分硬币
           1 + dp[3-3] = 1 + dp[0] = 1  选择了1个3分硬币
dp[4]:
           1 + dp[4-1] = 1 + dp[3] = 1 + 1 = 2   1,3
           1 + dp[4-3] = 1 + dp[1] = 1 + 1 = 2   3,1
dp[5]:
           1 + dp[5-1] = 1 + dp[4] = 1 + 2 = 3
           1 + dp[5-3] = 1 + dp[2] = 1 + 2 = 3
           1 + dp[5-5] = 1 + dp[0] = 1  最优解   1个5分硬币

从上面的理论推导，得到下面的状态转移方程：
dp[i] = min {1 + dp[i-vj]}   i表示面值   vj表示第j个硬币的面额 条件 i>=Vj
*/
int main()
{
    int v[] = {1, 3, 5}; // 存储硬币
    int len = sizeof(v) / sizeof(v[0]);
    int c = 11;                 // 给定面值
    int *dp = new int[c + 1](); // dp数组
    for (int i = 1; i <= c; ++i)
    {
        dp[i] = i; // 表示初始全部由1分硬币组成
        for (int j = 0; j < len; ++j)
        {
            if (i >= v[j] && (1 + dp[i - v[j]]) < dp[i])
                dp[i] = 1 + dp[i - v[j]];
        }
    }
    cout << dp[c] << endl;
    delete[] dp;

    return 0;
}