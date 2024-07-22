#include <iostream>
using namespace std;

// 环形队列
class Queue
{
public:
    Queue(int size = 10)
        : capa(size), m_front(0), m_rear(0), m_size(0)
    {
        m_que = new int[capa];
    }
    ~Queue()
    {
        delete[] m_que;
        m_que = nullptr;
    }

public:
    // 入队  相当于尾插
    void push(int val)
    {
        // 判断队满
        if ((m_rear + 1) % capa == m_front)
            expand(2 * capa); // 扩容
        m_que[m_rear] = val;
        m_rear = (m_rear + 1) % capa;
        ++m_size;
    }
    // 出队
    void pop()
    {
        // 判断队空
        if (m_front == m_rear)
            throw "queue is empty"; // 空队无法执行删除，则抛出异常
        m_front = (m_front + 1) % capa;
        --m_size;
    }
    // 获取队头元素
    int front() const
    {
        if (m_front == m_rear)
            throw "queue is empty";
        return m_que[m_front];
    }
    // 获取队尾元素
    int back() const
    {
        if (m_front == m_rear)
            throw "queue is empty";
        // rear总指向队尾元素的下一个位置
        return m_que[(m_rear - 1 + capa) % capa];
    }
    // 判断队空
    bool empty() const
    {
        return m_front == m_rear;
    }
    // 获取队列元素个数
    int size() const
    {
        // 添加成员变量  O(1)
        return m_size;

        // 遍历一遍统计队列元素个数 O(n)
        // int count = 0;  //用于计数
        // for (int i = m_front; i != m_rear; i = (i + 1) % capa)
        //     ++count;
        // return count;
    }

private:
    int *m_que;
    int capa;    // 空间容量
    int m_front; // 队头
    int m_rear;  // 队尾
    int m_size;  // 队列元素个数
    // 扩容接口
    void expand(int size)
    {
        auto newQue = new int[size];
        int i = 0;       // 遍历新队列
        int j = m_front; // 遍历老队列
        for (; j != m_rear; ++i, j = (j + 1) % capa)
            newQue[i] = m_que[j];
        delete[] m_que;
        // 更新成员变量
        m_que = newQue;
        capa = size;
        m_front = 0;
        m_rear = i;
    }
};

int main()
{
    system("chcp 65001");

    int arr[] = {12, 3, 54, 6, 71, 29, 80};
    Queue q;
    // 入栈
    for (int i : arr)
        q.push(i);

    cout << q.front() << endl; // 查看队头
    cout << q.back() << endl;  // 查看队尾

    cout << "遍历队列：" << endl;
    while (!q.empty())
    {
        cout << "队头元素为：" << q.front() << " 队尾元素为：" << q.back() << endl;
        q.pop();
    }

    system("pause");
    return 0;
}