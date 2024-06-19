#include "WeightedEdge.h"
#include "WeightedGraph.h"
#include "CC.h"
#include <queue>

// 求最小生成树算法
class Prim
{
private:
    WeightedGraph g_;
    vector<WeightedEdge> mst_; // 存放最小生成树
public:
    Prim(WeightedGraph g) : g_(g), mst_()
    {
        if (CC(g_).count() > 1)
            return;
        // Prim算法
        vector<int> visited(g_.V()); // 区分被切分的元素
        visited[0] = true;

        /* 优化版 */
        priority_queue<WeightedEdge, vector<WeightedEdge>, greater<WeightedEdge>> pq;
        // 初始横切边
        for (int w : g_.adj(0))
            pq.push(WeightedEdge(0, w, g_.getWeight(0, w)));

        while (!pq.empty())
        {
            WeightedEdge minEdge = pq.top();
            pq.pop();
            if (visited[minEdge.getV()] &&
                visited[minEdge.getW()]) // 不合法的横切边
                continue;

            mst_.push_back(minEdge);

            // 更新切分
            int newV = visited[minEdge.getV()] ? minEdge.getW() : minEdge.getV();
            visited[newV] = true;
            // 加入横切边元素
            for (int w : g_.adj(newV))
                if (!visited[w])
                    pq.push(WeightedEdge(newV, w, g_.getWeight(newV, w)));
        }

        /* 标准版 */
        // for (int i = 1; i < g_.V(); i++)
        // {
        //     WeightedEdge minEdge(-1, -1, INT_MAX);
        //     for (int v = 0; v < g_.V(); v++)
        //         if (visited[v])
        //             for (int w : g_.adj(v)) // 找到横切边
        //                 if (!visited[w] && g_.getWeight(v, w) < minEdge.getWeight())
        //                     minEdge = WeightedEdge(v, w, g_.getWeight(v, w));
        //     mst_.push_back(minEdge);
        //     // 更新切分
        //     visited[minEdge.getV()] = true;
        //     visited[minEdge.getW()] = true;
        // }
    }

    vector<WeightedEdge> result() { return mst_; }
};

int main()
{
    WeightedGraph g("g.txt");
    Prim prim(g);
    for (auto i : prim.result())
        cout << i << " ";
    cout << endl;
}