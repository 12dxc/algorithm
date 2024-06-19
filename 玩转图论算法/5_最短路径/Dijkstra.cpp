#include "WeightedGraph.h"
#include <queue>

// 求有权无向图的单源最短路径算法  迪杰斯特拉
class Dijkstra
{
public:
    // 存储顶点及当前最短路径的最小堆
    using pri_que = priority_queue<pair<int, int>, vector<pair<int, int>>, decltype([](pair<int, int> left, pair<int, int> right)
                                                                                    { return left.second > right.second; })>;

private:
    WeightedGraph g_;
    int s_;
    vector<int> dis_; // 记录从源点到其他顶点的最短路径长度
    vector<bool> visited_;
    vector<int> pre_; // 遍历最短路径经过的顶点

public:
    // 思想: 不断地选择最小距离的未访问顶点，并更新其邻接顶点的最短路径长度
    Dijkstra(WeightedGraph g, int s)
        : g_(g), s_(s), dis_(g_.V(), INT_MAX),
          visited_(g_.V(), false), pre_(g_.V(), -1)
    {
        dis_[s] = 0;
        pre_[s] = s;

        /* 使用优先队列优化 */
        pri_que pq;
        pq.push(make_pair(s, 0));
        while (!pq.empty())
        {
            int cur = pq.top().first;
            pq.pop();

            /* 性能不好 */
            // int cur = -1, curdis = INT_MAX;
            // for (int v = 0; v < g_.V(); v++)
            // {
            //     if (!visited_[v] && dis_[v] < curdis)
            //     {
            //         curdis = dis_[v];
            //         cur = v;
            //     }
            // }
            // if (cur == -1)
            //     break;

            if (visited_[cur])
                continue;

            visited_[cur] = true;
            for (int w : g_.adj(cur))
                if (!visited_[w])
                {
                    if (dis_[cur] + g_.getWeight(cur, w) < dis_[w])
                    {
                        // 遍历所有邻边，遇到更优路径需更新
                        dis_[w] = dis_[cur] + g_.getWeight(cur, w);
                        pq.push(make_pair(w, dis_[w]));
                        pre_[w] = cur;
                    }
                }
        }
    }
    bool isConnectedTo(int v) { return visited_[v]; }
    // 返回从源顶点到指定顶点的最短路径的长度
    int distTo(int v) { return dis_[v]; }
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
    WeightedGraph g("g.txt");
    Dijkstra dij(g, 0);
    for (int v = 0; v < g.V(); v++)
        cout << dij.distTo(v) << " ";
    cout << endl;
    for (int i : dij.path(3))
        cout << i << " ";
    cout << endl;
}