#include "Graph.h"

// dfs应用于求连通分量
class CC
{
private:
    Graph g_;
    vector<int> visited_;
    int cccount_ = 0; // 用以记录属于哪个连通分量

public:
    CC(Graph g)
        : g_(g), visited_(g_.V(), -1)
    {
        for (int v = 0; v < g_.V(); v++)
        {
            if (visited_[v] == -1)
            {
                dfs(v, cccount_);
                cccount_++;
            }
        }
    }
    int count() { return cccount_; }
    // 是否属于同个连通分量
    bool isConnected(int v, int w)
    {
        return visited_[v] == visited_[w];
    }
    // 返回连通分量组
    vector<vector<int>> components()
    {
        vector<vector<int>> res(cccount_);
        for (int v = 0; v != g_.V(); ++v)
            res[visited_[v]].push_back(v);
        return res;
    }

private:
    void dfs(int v, int ccid)
    {
        visited_[v] = ccid;
        for (int w : g_.adj(v))
            if (visited_[w] == -1)
                dfs(w, ccid);
    }
};

int main()
{
    Graph g("g.txt");
    CC cc(g);
    printf("连通分量个数: %d\n", cc.count());

    printf("5和6是否属于同个连通分量: %s\n",
           cc.isConnected(5, 6) ? "是" : "否");

    vector<vector<int>> comp = cc.components();
    printf("联通分量分组: \n");
    for (int i = 0; i != comp.size(); ++i)
    {
        printf("1:");
        for (int v : comp[i])
            printf(" %d", v);
        printf("\n");
    }

    return 0;
}