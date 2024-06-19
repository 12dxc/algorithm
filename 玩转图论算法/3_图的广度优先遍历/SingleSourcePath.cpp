#include "Graph.h"
#include <queue>

// bfs应用于无向无权图求单源路径
class SingleSourcePath
{
private:
    Graph g_;
    int s_; // 源点

    vector<bool> visited_;
    vector<int> pre_; // 记录来源顶点

private:
    void bfs(int s)
    {
        queue<int> que;
        que.push(s);
        visited_[s] = true;
        pre_[s] = s;
        while (!que.empty())
        {
            int v = que.front();
            que.pop();

            for (int w : g_.adj(v))
                if (!visited_[w])
                {
                    que.push(w);
                    visited_[w] = true;
                    pre_[w] = v;
                }
        }
    }

public:
    SingleSourcePath(Graph g, int s)
        : g_(g), s_(s), visited_(g_.V(), false), pre_(g_.V(), -1)
    {
        bfs(s);
    }
    bool isConnectedTo(int t) { return visited_[t]; }
    // 返回s->t的路径
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
    Graph g("g.txt");
    SingleSourcePath bfs(g, 0);
    cout << "0 -> 6 的路径为: ";
    for (int i : bfs.path(6))
        cout << i << " ";
    cout << endl;
    return 0;
}