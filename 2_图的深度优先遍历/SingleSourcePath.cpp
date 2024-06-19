#include "Graph.h"

// dfs应用于求单源路径
class SingleSourcePath
{
private:
    Graph g_;
    int s_; // 源

    vector<bool> visited_;
    vector<int> pre_; // 记录路径

public:
    SingleSourcePath(Graph g, int s)
        : g_(g), s_(s), visited_(g_.V(), false), pre_(g_.V())
    {
        dfs(s, s);
    }
    // 求源能否到达t顶点
    bool isConnectedTo(int t)
    {
        return visited_[t];
    }
    // 返回 s->t 的路径
    vector<int> path(int t)
    {
        vector<int> res;
        if (!isConnectedTo(t))
            return res;

        int cur = t;
        while (cur != s_)
        {
            res.push_back(cur);
            cur = pre_[cur]; // 求去源的节点
        }
        res.push_back(s_);

        ranges::reverse(res);
        return res;
    }

private:
    void dfs(int v, int parent)
    {
        visited_[v] = true;
        pre_[v] = parent;

        for (int w : g_.adj(v))
            if (!visited_[w])
                dfs(w, v); // v 即经过的顶点
    }
};

int main()
{
    Graph g("g.txt");
    SingleSourcePath ss(g, 0);
    printf("0->6: ");
    for (int i : ss.path(6))
        printf("%d ", i);
    printf("\n");

    return 0;
}