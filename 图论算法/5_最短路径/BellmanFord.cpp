#include "WeightedGraph.h"

// 贝尔曼-福德算法，用于求单源最短路径，一般用于有向无权图，可适用于有负权的情况（无向负权没有最短路径）
class BellmanFord
{
private:
    WeightedGraph g_;
    int s_;
    vector<int> dis_;
    vector<int> pre_;
    bool hasNegCycle = false;

public:
    BellmanFord(WeightedGraph g, int s)
        : g_(g), s_(s), dis_(g_.V(), INT_MAX), pre_(g_.V(), -1)
    {
        dis_[s] = 0;

        for (int pass = 1; pass < g_.V(); pass++)
        {
            for (int v = 0; v < g_.V(); v++)
                for (int w : g_.adj(v))
                    if (dis_[v] != INT_MAX &&
                        dis_[v] + g_.getWeight(v, w) < dis_[w])
                    {
                        dis_[w] = dis_[v] + g_.getWeight(v, w);
                        pre_[w] = v;
                    }
        }

        // 判断是否有负权边
        for (int v = 0; v < g_.V(); v++)
            for (int w : g_.adj(v))
                if (dis_[v] != INT_MAX &&
                    dis_[v] + g_.getWeight(v, w) < dis_[w])
                    hasNegCycle = true;
    }
    bool hasNegativeCycle() { return hasNegCycle; }

    bool isConnectedTo(int v) { return dis_[v] != INT_MAX; }

    int distTo(int v)
    {
        if (hasNegCycle)
            cerr << "存在负权环" << endl;
        return dis_[v];
    }

    vector<int> path(int t)
    {
        vector<int> res;
        if (!isConnectedTo(t))
            return res;

        int cur = t;
        while (cur != s_)
        {
            res.push_back(cur);
            cur = pre_[cur];
        }
        res.push_back(s_);
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    WeightedGraph g("g.txt");
    BellmanFord bf(g, 0);
    if (!bf.hasNegativeCycle())
    {
        for (int v = 0; v < g.V(); v++)
            cout << bf.distTo(v) << " ";
        cout << endl;
    }
    else
        cerr << "存在负权环" << endl;
    for (int i : bf.path(3))
        cout << i << " ";
    cout << endl;
}