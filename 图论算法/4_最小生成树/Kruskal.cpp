#include "WeightedEdge.h"
#include "UF.h"
#include "CC.h"

// 求最小生成树算法
class Kruskal
{
private:
    WeightedGraph g_;
    vector<WeightedEdge> mst_; // 存放最小生成树

public:
    Kruskal(WeightedGraph g) : g_(g), mst_()
    {
        // 只有属于一个连通分量才进行求最小生成树
        if (CC(g_).count() > 1)
            return;
        //  Kruskal算法
        vector<WeightedEdge> edges;
        for (int v = 0; v < g_.V(); ++v)
            for (int w : g_.adj(v))
                if (v < w)
                    edges.push_back(WeightedEdge(v, w, g_.getWeight(v, w)));
        sort(edges.begin(), edges.end()); // 按权值进行排序
        // 去除环
        UF uf(g_.V());
        for (auto edge : edges)
        {
            int v = edge.getV();
            int w = edge.getW();
            if (!uf.isConnected(v, w))
            {
                mst_.push_back(edge);
                uf.unionElements(v, w);
            }
        }
    }
    vector<WeightedEdge> result()
    {
        return mst_;
    }
};

int main()
{
    WeightedGraph g("g.txt");
    Kruskal kruskal(g);
    for (auto i : kruskal.result())
        cout << i << " ";
    cout << endl;
}