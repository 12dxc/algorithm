#include <iostream>
#include <vector>
using namespace std;

using uint = unsigned int;
const uint INF = INT_MAX;

int main()
{
    vector<vector<uint>> graph =
        {
            {0, 6, 3, INF, INF, INF},
            {6, 0, 2, 5, INF, INF},
            {3, 2, 0, 3, 4, INF},
            {INF, 5, 3, 0, 2, 3},
            {INF, INF, 4, 2, 0, 5},
            {INF, INF, INF, 3, 5, 0},
        };
    int n = graph.size(); // 结点数

    // 弗洛伊德算法
    //  一次把每一个顶点加入
    for (int k = 0; k != n; ++k)
    {
        // 都需要遍历邻接矩阵
        for (int i = 0; i != n; ++i)
        {
            for (int j = 0; j != n; ++j)
            {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    // 遍历输出所有结点最短路径
    for (auto line : graph)
    {
        for (auto dis : line)
        {
            cout << dis << " ";
        }
        cout << endl;
    }
}