#include "Graph.h"

// dfs应用于检测无向图中的环
class CycleDetection
{
private:
    Graph g_;
    vector<bool> visited_;
    bool hasCycle_ = false; // 标记是否有环

private:
    // 从顶点 v 开始，判断图中是否有环
    bool dfs(int v, int parent)
    {
        visited_[v] = true;
        for (int w : g_.adj(v))
            if (!visited_[w])
            {
                if (dfs(w, v))
                    return true;
            }
            else if (w != parent)
                return true;
        return false;
    }

public:
    CycleDetection(Graph g)
        : g_(g), visited_(g_.V(), false)
    {
        for (int v = 0; v < g_.V(); v++) // 可能有非连通图，故要考虑所有的节点
            if (!visited_[v])
                if (dfs(v, v))
                {
                    hasCycle_ = true;
                    break;
                }
    }
    bool hasCycle() { return hasCycle_; }
};

int main()
{
    cout << boolalpha;
    Graph g("g.txt");
    CycleDetection cd(g);
    cout << "图中是否有环: " << cd.hasCycle() << endl;

    Graph g2("g2.txt");
    CycleDetection cd2(g2);
    cout << "图2中是否有环: " << cd2.hasCycle() << endl;
}