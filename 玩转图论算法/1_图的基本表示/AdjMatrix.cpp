/*
    图的邻接矩阵实现
*/

#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

// 简单图的邻接矩阵实现类
class adjMatrix
{
private:
    int V_;                   // 顶点个数
    int E_;                   // 边数
    vector<vector<int>> adj_; // 表示图的结构
public:
    adjMatrix(string filename)
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
            perror("顶点数 或 边数，不能为空");
            exit(0);
        }
        adj_.resize(V_);
        for (auto &v : adj_)
            v.resize(V_, 0);

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
            if (adj_[a][b] == 1)
            {
                perror("是平行边");
                exit(0);
            }
            adj_[a][b] = 1;
            adj_[b][a] = 1;
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
        return adj_[v][w] == 1;
    }
    // 返回与v顶点相连的顶点
    vector<int> adj(int v)
    {
        validateVertex(v);
        vector<int> res;
        for (int i = 0; i < V_; i++)
            if (adj_[v][i] == 1)
                res.push_back(i);

        return res;
    }
    // 求一个顶点的度
    int degree(int v)
    {
        return adj_[v].size();
    }

    friend ostream &operator<<(ostream &os, const adjMatrix &adjMatrix)
    {
        os << "V = " << adjMatrix.V_ << ", E = " << adjMatrix.E_ << endl;
        for (auto v : adjMatrix.adj_)
        {
            for (int i : v)
            {
                os << i << " ";
            }
            os << endl;
        }
        return os;
    }
};

int main()
{
    adjMatrix adjMatrix("g.txt");
    cout << adjMatrix;
    vector<int> v = adjMatrix.adj(1);
    for (auto i : v)
        cout << i << " ";
    cout << endl;

    return 0;
}