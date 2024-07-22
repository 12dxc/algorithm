#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using uint = unsigned int; // ��ʾ�޷�������
const uint INF = INT_MAX;  // ��ʾ�����޷�����

// �Ͻ�˹�����㷨�ӿ�
int Dijkstra(vector<vector<uint>> &graph,
             int start, // ���
             int end)   // �յ�
{
    const int N = graph.size();
    // �洢������������·��(��СȨֵ)
    vector<uint> dis(N, 0); // �洢����������·�� ����U
    vector<bool> use(N, false);

    // ��start����S����
    use[start] = true;
    // ��ʼ��start������U���϶���Ȩֵ
    for (int i; i < N; ++i)
        dis[i] = graph[start][i];

    // ��U�����еĶ��㴦����
    for (int i = 1; i < N; i++) // O(n)
    {
        // �ȴ�U�������ҵ�Ȩֵ��С�Ķ���
        int k = -1;
        int min = INF;
        for (int j = 0; j < N; ++j)
        {
            if (!use[j] && min > dis[j]) // U���ϵĶ���
            {
                min = dis[j];
                k = j;
            }
        }

        if (k == -1)
            break; // ��ʾ��û��ȥ��һ�����·��

        // ��ѡ���Ķ�����뵽S������
        use[k] = true;

        // ��U������ʣ�ඥ���Ȩֵ��Ϣ����һ��
        for (int j = 0; j < N; ++j)
        {
            if (!use[j] && min + graph[k][j] < dis[j]) // U����
            {
                dis[j] = min + graph[k][j];
            }
        }
    }

    // ���Դ�ӡ
    for (int d : dis)
    {
        cout << d << " ";
    }
    cout << endl;

    return dis[end];
}

// �Ͻ�˹�����㷨�ӿ�  --С�����Ż�
int Dijkstra2(vector<vector<uint>> &graph,
              int start, // ���
              int end)   // �յ�
{
    const int N = graph.size();
    // �洢������������·��(��СȨֵ)
    vector<uint> dis(N, 0); // �洢����������·�� ����U
    vector<bool> use(N, false);

    // ����С����
    priority_queue<pair<uint, int>, vector<pair<uint, int>>, greater<pair<uint, int>>> que;

    // ��start����S����
    use[start] = true;
    // ��ʼ��start������U���϶���Ȩֵ
    for (int i; i < N; ++i)
    {
        dis[i] = graph[start][i];
        if (i != start) // �ѳ�start�������������ȫ������U����С������
            que.emplace(graph[start][i], i);
    }

    // ��U�����еĶ��㴦����
    while (!que.empty()) // O(n)
    {
        // ��С������Ȩֵ��С�Ķ���    O(logn)   pair<Ȩֵ��������>
        // �ȴ�U�������ҵ�Ȩֵ��С�Ķ���
        auto pair = que.top();
        que.pop();
        if (pair.first == INF)
            break;
        int k = pair.second;
        int min = pair.first;

        if (use[k])
            continue;
        // ��ѡ���Ķ�����뵽S������
        use[k] = true;

        // ��U������ʣ�ඥ���Ȩֵ��Ϣ����һ��
        for (int j = 0; j < N; ++j)
        {
            if (!use[j] && min + graph[k][j] < dis[j]) // U����
            {
                dis[j] = min + graph[k][j];
                // ����U�����ж����Ȩֵ��
                que.emplace(dis[j], j);
            }
        }
    }

    // ���Դ�ӡ
    for (int d : dis)
    {
        cout << d << " ";
    }
    cout << endl;

    return dis[end];
}
int main()
{
    vector<vector<uint>> graph = // ͼ���ڽӾ���
        {
            {0, 6, 3, INF, INF, INF},
            {6, 0, 2, 5, INF, INF},
            {3, 2, 0, 3, 4, INF},
            {INF, 5, 3, 0, 2, 3},
            {INF, INF, 4, 2, 0, 5},
            {INF, INF, INF, 3, 5, 0},
        };

    int distance = Dijkstra(graph, 1, 4);
    if (distance == INF)
    {
        cout << "��������Ч·��!" << endl;
    }
    else
    {
        cout << "distance:" << distance << endl;
    }
}