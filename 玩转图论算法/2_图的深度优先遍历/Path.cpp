#include "Graph.h"

// dfs应用于求单源路径（优化版本，加判断找到终点提前终止深搜）
class Path
{
private:
    Graph g_;
    int s_; // 源点
    int t_; // 终点

    vector<bool> visited_;
    vector<int> pre_; // 记录路径

public:
    Path(Graph g, int s, int t)
        : g_(g), s_(s), t_(t),
          visited_(g_.V(), false), pre_(g_.V())
    {
        dfs(s, s);
        cout << "深搜的的顶点情况: ";
        for (bool e : visited_)
            cout << e << " ";
        cout << endl;
    }
    // 求源能否到达t顶点
    bool isConnectedTo()
    {
        return visited_[t_];
    }
    // 返回 s->t 的路径
    vector<int> path()
    {
        vector<int> res;
        if (!isConnectedTo())
            return res;

        int cur = t_;
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
    bool dfs(int v, int parent)
    {
        visited_[v] = true;
        pre_[v] = parent;
        if (v == t_)
            return true;

        for (int w : g_.adj(v))
            if (!visited_[w])
                if (dfs(w, v))
                    return true;
        return false;
    }
};

int main()
{
    Graph g("g.txt");
    Path path(g, 0, 6);
    printf("0->6: ");
    for (int i : path.path())
        printf("%d ", i);
    printf("\n");

    Path path2(g, 0, 1);
    printf("0->1: ");
    for (int i : path2.path())
        printf("%d ", i);
    printf("\n");

    return 0;
}