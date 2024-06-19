#include "WeightedGraph.h"

// 求多源最短路径算法  弗洛伊德算法
class Floyed
{
private:
    WeightedGraph g_;
    vector<vector<int>> dis_; // 记录顶点[i,j]的最短路径长度
    bool hasNegCycle = false; // 标记是否有负权环

public:
    Floyed(WeightedGraph g)
        : g_(g), dis_(g_.V(), vector<int>(g_.V(), INT_MAX))
    {
        // Floyed利用了动态规划思想
        // 初始化路径矩阵
        for (int v = 0; v < g_.V(); v++)
        {
            dis_[v][v] = 0;
            for (int w : g_.adj(v))
                dis_[v][w] = g_.getWeight(v, w);
        }

        // 状态更新
        for (int t = 0; t < g_.V(); t++)
            for (int v = 0; v < g_.V(); v++)
                for (int w = 0; w < g_.V(); w++)
                    if (dis_[v][t] != INT_MAX && dis_[t][w] != INT_MAX &&
                        dis_[v][t] + dis_[t][w] < dis_[v][w])
                        dis_[v][w] = dis_[v][t] + dis_[t][w];

        // 判断负权环
        for (int v = 0; v < g_.V(); v++)
            if (dis_[v][v] < 0)
                hasNegCycle = true;
    }
    bool hasNegativeCycle()
    {
        return hasNegCycle;
    }
    bool isConnectedTo(int v, int w)
    {
        return dis_[v][w] != INT_MAX;
    }
    int distTo(int v, int w)
    {
        return dis_[v][w];
    }
};

int main()
{
    WeightedGraph g("g.txt");
    Floyed floyed(g);
    if (!floyed.hasNegativeCycle())
        for (int v = 0; v < g.V(); v++)
        {
            for (int w = 0; w < g.V(); w++)
                cout << floyed.distTo(v, w) << " ";
            cout << endl;
        }
    else
        cout << "存在负权环" << endl;
}