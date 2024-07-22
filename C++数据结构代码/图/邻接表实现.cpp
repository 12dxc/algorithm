#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <fstream>
#include <sstream>
using namespace std;

// ʵ��һ������ͼ���ڽӱ�ṹ
class Digraph
{
public:
    // �������ļ����붥��ͱߵ���Ϣ�������ڽӱ�
    void readFile(string filePath)
    {
        ifstream file(filePath);

        // ռ�õ�0��λ��
        vertics.emplace_back("");

        if (file.is_open())
        {
            string currentVertex;
            string line;
            while (getline(file, line))
            {
                // �������ĸ�У����¼��ǰ����
                if (isalpha(line[0]))
                {
                    currentVertex = line[0];
                    vertics.emplace_back(currentVertex);
                }
                else
                { // �������ŷָ��������б�
                    istringstream iss(line);
                    string number;
                    while (getline(iss, number, ','))
                    {
                        if (stoi(number) > 0) // û����ȵľͲ������ڽ�����
                            // ��������ӵ���ǰ������ڽ�������
                            vertics.back().adjList_.emplace_back(stoi(number));
                    }
                }
            }
            file.close();
        }
    }

    // ����ڽӱ���Ϣ
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

    // ͼ��������ȱ���
    void dfs()
    {
        vector<bool> visited(vertics.size(), false); // ��¼�����Ƿ񱻱�����
        dfs(1, visited);
        cout << endl;
    }
    // ͼ�Ĺ�����ȱ���
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
            // ������ǰ������ڽ�����
            for (auto no : vertics[cur_no].adjList_)
            {
                if (!visited[no]) // �ж��Ƿ������
                {
                    que.push(no);
                    visited[no] = true;
                }
            }
        }
        cout << endl;
    }
    // �󲻴�Ȩֵ�����·������ - ������ȱ���
    void shortPath(int start, int end)
    {
        vector<bool> visited(vertics.size(), false);
        queue<int> que;

        que.push(start);
        visited[start] = true;
        // ��¼�����ڱ��������е�ǰ�������ϵ
        vector<int> path(vertics.size(), 0);

        while (!que.empty())
        {
            int cur_no = que.front();
            if (cur_no == end)
                break;
            que.pop();

            // ������ǰ������ڽ�����
            for (auto no : vertics[cur_no].adjList_)
            {
                if (!visited[no]) // �ж��Ƿ������
                {
                    que.push(no);
                    visited[no] = true;
                    // ��ǰ�ڵ㴦����¼�Ǵ���һ���ڵ������
                    path[no] = cur_no;
                }
            }
        }

        if (!que.empty())
        {
            // ����һ�����·������ô�����
            showPath(end, path);
        }
        else
        {
            cout << "��������Ч�����·��!" << endl;
        }
        cout << endl;
    }

private:
    // ������ȱ����ĵݹ�ӿ�
    void dfs(int start, vector<bool> &visited)
    {
        if (visited[start] == true)
            return; // ���Ѿ��������Ľڵ�

        cout << vertics[start].data_ << " ";
        visited[start] = true;
        // �ݹ������һ��ڵ�
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
    // ��������
    struct Vertic
    {
        Vertic(string data) : data_(data) {}

        string data_;       // �洢�������Ϣ
        list<int> adjList_; // �ڽ�����ṹ
    };

    vector<Vertic> vertics; // �ڽӱ�ṹ
};

int main()
{
    Digraph graph;
    graph.readFile("data.txt");
    graph.show();
    cout << "������ȱ���:" << endl;
    graph.dfs();
    cout << "������ȱ���:" << endl;
    graph.bfs();
    cout << "���·��:" << endl;
    graph.shortPath(1, 8);

    return 0;
}