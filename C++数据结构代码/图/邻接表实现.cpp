#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <fstream>
#include <sstream>
using namespace std;

// 实现一个有向图的邻接表结构
class Digraph
{
public:
    // 从配置文件读入顶点和边的信息，生成邻接表
    void readFile(string filePath)
    {
        ifstream file(filePath);

        // 占用第0号位置
        vertics.emplace_back("");

        if (file.is_open())
        {
            string currentVertex;
            string line;
            while (getline(file, line))
            {
                // 如果是字母行，则记录当前顶点
                if (isalpha(line[0]))
                {
                    currentVertex = line[0];
                    vertics.emplace_back(currentVertex);
                }
                else
                { // 解析逗号分隔的数字列表
                    istringstream iss(line);
                    string number;
                    while (getline(iss, number, ','))
                    {
                        if (stoi(number) > 0) // 没有入度的就不插入邻接链表
                            // 将数字添加到当前顶点的邻接链表中
                            vertics.back().adjList_.emplace_back(stoi(number));
                    }
                }
            }
            file.close();
        }
    }

    // 输出邻接表信息
    void show() const
    {
        for (int i = 1; i < vertics.size(); ++i)
        {
            cout << vertics[i].data_ << " : ";
            for (auto no : vertics[i].adjList_)
            {
                cout << no << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    // 图的深度优先遍历
    void dfs()
    {
        vector<bool> visited(vertics.size(), false); // 记录顶点是否被遍历过
        dfs(1, visited);
        cout << endl;
    }
    // 图的广度优先遍历
    void bfs()
    {
        vector<bool> visited(vertics.size(), false);
        queue<int> que;

        que.push(1);
        visited[1] = true;

        while (!que.empty())
        {
            int cur_no = que.front();
            que.pop();

            cout << vertics[cur_no].data_ << " ";
            // 遍历当前顶点的邻接链表
            for (auto no : vertics[cur_no].adjList_)
            {
                if (!visited[no]) // 判断是否遍历过
                {
                    que.push(no);
                    visited[no] = true;
                }
            }
        }
        cout << endl;
    }
    // 求不带权值的最短路径问题 - 广度优先遍历
    void shortPath(int start, int end)
    {
        vector<bool> visited(vertics.size(), false);
        queue<int> que;

        que.push(start);
        visited[start] = true;
        // 记录顶点在遍历过程中的前后遍历关系
        vector<int> path(vertics.size(), 0);

        while (!que.empty())
        {
            int cur_no = que.front();
            if (cur_no == end)
                break;
            que.pop();

            // 遍历当前顶点的邻接链表
            for (auto no : vertics[cur_no].adjList_)
            {
                if (!visited[no]) // 判断是否遍历过
                {
                    que.push(no);
                    visited[no] = true;
                    // 当前节点处，记录是从哪一个节点过来的
                    path[no] = cur_no;
                }
            }
        }

        if (!que.empty())
        {
            // 存在一条最短路径，怎么输出？
            showPath(end, path);
        }
        else
        {
            cout << "不存在有效的最短路径!" << endl;
        }
        cout << endl;
    }

private:
    // 深度优先遍历的递归接口
    void dfs(int start, vector<bool> &visited)
    {
        if (visited[start] == true)
            return; // 是已经遍历过的节点

        cout << vertics[start].data_ << " ";
        visited[start] = true;
        // 递归遍历下一层节点
        for (auto no : vertics[start].adjList_)
        {
            dfs(no, visited);
        }
    }

    void showPath(int end, vector<int> path)
    {
        if (end == 0)
            return;
        showPath(path[end], path);

        cout << vertics[end].data_ << " ";
    }

private:
    // 顶点类型
    struct Vertic
    {
        Vertic(string data) : data_(data) {}

        string data_;       // 存储顶点的信息
        list<int> adjList_; // 邻接链表结构
    };

    vector<Vertic> vertics; // 邻接表结构
};

int main()
{
    Digraph graph;
    graph.readFile("data.txt");
    graph.show();
    cout << "深度优先遍历:" << endl;
    graph.dfs();
    cout << "广度优先遍历:" << endl;
    graph.bfs();
    cout << "最短路径:" << endl;
    graph.shortPath(1, 8);

    return 0;
}