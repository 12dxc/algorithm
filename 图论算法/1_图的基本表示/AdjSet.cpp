/*
    图的邻接表实现改进 -> 用红黑树进行优化
*/

#include <iostream>
#include <vector>
#include <cstdio>
#include <ranges>
#include <algorithm>
#include <set>
using namespace std;

class AdjSet
{
private:
    int V_;                // 顶点个数
    int E_;                // 边数
    vector<set<int>> adj_; // 表示图的结构
public:
    AdjSet(string filename)
    {
        FILE *fd = fopen(filename.c_str(), "r");
        if (fd == nullptr)
        {
            perror("打开文件时出错");
            exit(EXIT_FAILURE);
        }

        fscanf(fd, "%d %d\n", &V_, &E_);
        if (V_ < 0 || E_ < 0)
        {
            perror("顶点数 或 边数，不能为0");
            exit(0);
        }
        adj_.resize(V_);

        for (int i = 0; i < E_; i++)
        {
            int a, b;
            fscanf(fd, "%d %d\n", &a, &b);
            validateVertex(a);
            validateVertex(b);
            if (a == b)
            {
                perror("不允许自环边");
                exit(0);
            }
            if (ranges::find(adj_[a], b) != adj_[a].end())
            {
                perror("是平行边");
                exit(0);
            }
            adj_[a].emplace(b);
            adj_[b].emplace(a);
        }
    }
    // 判断顶点是否合法
    void validateVertex(int v)
    {
        if (v < 0 || v >= V_)
        {
            printf("顶点%d不合法\n", v);
            return;
        }
    }
    int V() { return V_; }
    int E() { return E_; }
    // 是否存在某条边
    bool hasEdge(int v, int w)
    {
        validateVertex(v);
        validateVertex(w);
        return ranges::find(adj_[v], w) != adj_[v].end();
    }
    // 返回与v顶点相连的顶点
    vector<int> adj(int v)
    {
        validateVertex(v);
        return vector<int>(adj_[v].begin(), adj_[v].end());
    }
    // 求一个顶点的度
    int degree(int v)
    {
        validateVertex(v);
        return adj_[v].size();
    }

    friend ostream &operator<<(ostream &os, const AdjSet &adjList)
    {
        os << "V = " << adjList.V_ << ", E = " << adjList.E_ << endl;
        for (int v = 0; v < adjList.V_; v++)
        {
            os << v << ": ";
            for (int w : adjList.adj_[v])
                os << w << " ";
            os << endl;
        }
        return os;
    }
};

int main()
{
    AdjSet adjSet("g.txt");
    cout << adjSet;
    // 打印相邻顶点
    vector<int> v = adjSet.adj(1);
    for (auto i : v)
        cout << i << " ";
    cout << endl;
}