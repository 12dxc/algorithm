#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
m个柜台提供服务，每个柜台给一个用户提供服务的时间是t(用数组表示每一个柜台提供服务的时间)，
问怎么排列，使得柜台给所有用户提供服务的时间最少？
*/

// 定义柜台信息类型
struct Counter
{
    bool operator<(const Counter &counter)
    {
        return time < counter.time;
    }
    int id;   // 柜台号
    int time; // 柜台所花费的时间
};
int main()
{
    int arr[] = {3, 2, 4};                      // 每一个柜台提供服务的时间
    const int m = sizeof(arr) / sizeof(arr[0]); // 柜台的数量
    int n = 15;                                 // 办理业务的人数

    // 定义柜台信息数组，初始化柜台id和time
    Counter cons[m];
    for (int i = 0; i < m; ++i)
    {
        cons[i].id = i;
        cons[i].time = arr[i];
    }

    // 按照柜台提供的时间进行升序排列
    sort(cons, cons + m);

    int minTime = 0; // 记录给所有用户提供服务的最少时间
    int x[m] = {0};  // 记录每一个柜台安排的用户数量

    for (int i = 0; i < n; ++i)
    {
        // 先计算把i用户放在0号柜台的时间
        int time = cons[0].time * (x[0] + 1);
        // 在遍历其他的柜台，看是否可以得到更少的花费时间
        int j = 1;
        for (; j < m; ++j)
        {
            int t = cons[j].time * (x[j] + 1);
            if (t <= time) // 放在其他柜台处理时间总体更快，直接放入j柜台
            {
                x[j]++;
                // 新添加了一个人，整体花费的时间有可能变得更长了，更新minTime
                if (t > minTime)
                {
                    minTime = t;
                }
                break;
            }
        }
        // 最终还是放在0号柜台花费的时间更少
        if (j == m)
        {
            x[0]++;
            // 新添加了一个人，整体花费的时间有可能变得更长了，更新minTime
            minTime = cons[0].time * x[0];
        }
    }

    cout << minTime << endl;
    for (int i = 0; i < m; ++i)
        cout << arr[cons[i].id] << " : " << x[i] << endl;

    return 0;
}