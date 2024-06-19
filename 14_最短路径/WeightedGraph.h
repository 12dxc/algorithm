#pragma once
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

// 用于构建图结构的类，暂时只支持无向带权图
class WeightedGraph
{
private:
    int V_;                     // 顶点个数
    int E_;                     // 边数
    vector<map<int, int>> adj_; // 表示图的结构
public:
    WeightedGraph(string filename)
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
            int a, b, weight;
            fscanf(fd, "%d %d %d\n", &a, &b, &weight);
            validateVertex(a);
            validateVertex(b);
            if (a == b)
            {
                perror("不允许自环边");
                exit(0);
            }
            if (adj_[a].find(b) != adj_[a].end())
            {
                perror("有平行边");
                exit(0);
            }
            adj_[a].emplace(b, weight);
            adj_[b].emplace(a, weight);
        }
    }
    // 判断顶点是否合法
    void validateVertex(int v)
    {
        if (v < 0 || v >= V_)
        {
            cerr << "顶点" << v << "不合法" << endl;
        }
    }
    int V() { return V_; }
    int E() { return E_; }
    // 是否存在某条边
    bool hasEdge(int v, int w)
    {
        validateVertex(v);
        validateVertex(w);
        return adj_[v].find(w) != adj_[v].end();
    }
    // 返回与v顶点相连的顶点
    vector<int> adj(int v)
    {
        validateVertex(v);
        vector<int> res;
        for (auto i : adj_[v])
            res.push_back(i.first);
        return res;
    }
    // 返回两点之间的权值
    int getWeight(int v, int w)
    {

        if (hasEdge(v, w))
            return adj_[v].at(w);
        cerr << "没有边 " << v << "->" << w << endl;
        return -1;
    }
    // 求一个顶点的度
    int degree(int v)
    {
        validateVertex(v);
        return adj_[v].size();
    }

    friend ostream &operator<<(ostream &os, const WeightedGraph &adjList)
    {
        os << "V = " << adjList.V_ << ", E = " << adjList.E_ << endl;
        for (int v = 0; v < adjList.V_; v++)
        {
            os << v << ": ";
            for (auto w : adjList.adj_[v])
                os << "(" << w.first << ": " << w.second << ") ";
            os << endl;
        }
        return os;
    }
};
