#include "Graph.h"
#include <queue>

// 图的广度优先遍历
class GraphBFS
{
private:
    Graph g_;
    vector<bool> visited_;
    vector<int> order_;

private:
    void bfs(int s)
    {
        queue<int> que;
        que.push(s);
        visited_[s] = true;
        while (!que.empty())
        {
            int v = que.front();
            que.pop();
            order_.push_back(v);

            for (int w : g_.adj(v))
                if (!visited_[w])
                {
                    que.push(w);
                    visited_[w] = true;
                }
        }
    }

public:
    GraphBFS(Graph g)
        : g_(g), visited_(g_.V(), false)
    {
        for (int v = 0; v < g_.V(); v++)
            if (!visited_[v])
                bfs(v);
    }
    vector<int> order() { return order_; }
};

int main()
{
    Graph g("g.txt");
    GraphBFS bfs(g);
    for (int i : bfs.order())
        cout << i << " ";
    cout << endl;

    return 0;
}