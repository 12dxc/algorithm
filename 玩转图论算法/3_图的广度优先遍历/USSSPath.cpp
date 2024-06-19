#include "Graph.h"
#include <queue>

// dfs求解无权图单源最短路径
class USSPath // Unweighted Single Source Shortest Path (无权单源最短路径)
{
private:
    Graph g_;
    int s_; // 源点

    vector<bool> visited_;
    vector<int> pre_; // 记录来源顶点
    vector<int> dis_; // 记录所属层数

private:
    void bfs(int s)
    {
        queue<int> que;
        que.push(s);
        visited_[s] = true;
        pre_[s] = s;
        dis_[s] = 0;

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
                    dis_[w] = dis_[v] + 1; // 来源顶点所属层数+1
                }
        }
    }

public:
    USSPath(Graph g, int s)
        : g_(g), s_(s), visited_(g_.V(), false),
          pre_(g_.V(), -1), dis_(g_.V(), -1)
    {
        bfs(s);
    }
    bool isConnectedTo(int t) { return visited_[t]; }
    int dis(int t) { return dis_[t]; }
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
    USSPath usspath(g, 0);
    cout << "0 -> 6 的路径为: ";
    for (int i : usspath.path(6))
        cout << i << " ";
    cout << "\n"
         << "距离为: " << usspath.dis(6);

    return 0;
}