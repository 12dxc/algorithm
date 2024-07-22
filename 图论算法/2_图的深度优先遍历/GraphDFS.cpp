#include "Graph.h"

// 图的深度优先遍历
class GraphDFS
{
private:
    Graph g_;
    vector<int> pre_;  // 先序遍历数组
    vector<int> post_; // 后序遍历数组
    vector<bool> visited_;

private:
    void dfs(int v)
    {
        visited_[v] = true;
        pre_.push_back(v); // 先序遍历
        for (int w : g_.adj(v))
            if (!visited_[w]) // 要做判断顶点是否被遍历过，这个也是递归终止条件
                dfs(w);
        post_.push_back(v); // 后序遍历
    }

public:
    GraphDFS(Graph g)
        : g_(g), pre_(0), post_(0), visited_(g_.V(), false)
    {
        for (int v = 0; v < g_.V(); v++) // 可能有非连通图，故要考虑所有的节点
            if (!visited_[v])
                dfs(v);
    }
    vector<int> pre()
    {
        return pre_;
    }
    vector<int> post()
    {
        return post_;
    }
};

int main()
{
    Graph g("g.txt");
    GraphDFS dfs(g);

    cout << "先序遍历: ";
    for (auto i : dfs.pre())
        cout << i << " ";
    cout << "\n先序遍历: ";
    for (auto i : dfs.post())
        cout << i << " ";
    cout << endl;

    return 0;
}