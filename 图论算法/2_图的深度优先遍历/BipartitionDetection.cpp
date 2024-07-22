#include "Graph.h"

// dfs应用于检测二分图
class BipartitionDetection
{
private:
    Graph g_;
    vector<bool> visited_;
    vector<int> colors_;      // 用于染色的数组
    bool isBipartite_ = true; // 标记是否是二分图

private:
    bool dfs(int v, int color)
    {
        visited_[v] = true;
        colors_[v] = color;
        for (int w : g_.adj(v))
            if (!visited_[w])
            {
                if (!dfs(w, 1 - color)) // 染相反的色，非0即1
                    return false;
            }
            else if (colors_[w] == colors_[v])
            {
                return false;
            }
        return true;
    }

public:
    BipartitionDetection(Graph g)
        : g_(g), visited_(g_.V(), false), colors_(g_.V(), -1)
    {
        for (int v = 0; v < g_.V(); v++)
            if (!visited_[v])
                if (!dfs(v, 0))
                {
                    isBipartite_ = false;
                    break;
                }
    }
    bool isBipartite() { return isBipartite_; }
};

int main()
{
    cout << boolalpha;
    Graph g("g.txt");
    BipartitionDetection bd(g);
    cout << "是否是二分图: " << bd.isBipartite() << endl;
    return 0;
}