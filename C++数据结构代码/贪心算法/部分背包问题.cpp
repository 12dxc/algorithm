#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*部分背包问题: 有n个物体，第i个物体的重量为wi，价值为vi。在总重量不超过C的情况下让总价值尽量高。
每一个物体都可以只取走一部分，价值和重量按比例计算。求最大总价值。*/

struct Product // 物品信息类型
{
    double getPrice() const // 性价比
    {
        return v * 1.0 / w;
    }
    bool operator>(const Product &p) const
    {
        return getPrice() > p.getPrice();
    }
    int id; // 物品的id
    int w;  // 物品的重量
    int v;  // 物品的价值
};
int main()
{
    int w[] = {8, 6, 4, 2, 5}; // 每个物品的重量
    int v[] = {6, 4, 7, 8, 6}; // 每个物品的价值
    const int n = sizeof(w) / sizeof(w[0]);
    int c = 12;     // 背包总量
    int x[n] = {0}; // 记录哪些物品被装入背包

    // 将信息填入此数据类型
    Product pros[n];
    for (int i = 0; i < n; ++i)
    {
        pros[i].id = i;
        pros[i].w = w[i];
        pros[i].v = v[i];
    }
    // 按物品的性价比进行降序排列
    sort(pros, pros + n, [](const Product &p1, const Product &p2) -> bool
         { return p1 > p2; });

    // 按性价比高的往背包里面放（只考虑局部的最优解）
    double bestV = 0.0; // 记录背包的最大价值
    for (int i = 0; i < n; ++i)
    {
        if (pros[i].w <= c) // 说明第i个物品可以装入背包
        {
            bestV += pros[i].v; // 增加背包已有价值
            c -= pros[i].w;     // 减少背包承重
        }
        else // 说明第i个物品无法全部装入背包，按剩余容量的比例装入物品的一部分
        {
            bestV = bestV + pros[i].v * (c * 1.0 / pros[i].w);
            x[pros[i].id] = 1;
            break;
        }
        x[pros[i].id] = 1;
    }
    cout << "bestV:" << bestV << endl;
    for (int v : x)
    {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}