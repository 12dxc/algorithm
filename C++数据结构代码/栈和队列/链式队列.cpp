#include <iostream>
using namespace std;

// 链式队列  底层实现为双向循环链表
class LinkQueue
{
public:
    LinkQueue()
    {
        m_head = new Node();
        m_head->next = m_head;
        m_head->prev = m_head;
    }
    ~LinkQueue()
    { // 循环链表的遍历条件是p != m_head，故头节点必须保留
        auto p = m_head->next;
        while (p != m_head)
        {
            m_head->next = p->next; // 头节点next后移1位
            p->next->prev = m_head; // 当前节点的下个节点头指针挂上头节点
            delete p;
            p = m_head->next;
        }
        delete m_head;
        m_head = nullptr;
    }

public:
    // 入队  队尾进
    void push(int val)
    {
        auto node = new Node(val);
        node->prev = m_head->prev;
        node->next = m_head;
        m_head->prev->next = node;
        m_head->prev = node;
    }
    // 出队 队头出
    void pop()
    {
        if (m_head->next == m_head) // 队列无有效节点
            throw "queue is empty";
        auto p = m_head->next; // 要删除节点
        m_head->next = p->next;
        p->next->prev = m_head;
        delete p;
    }
    // 获取队头元素
    int front() const
    {
        if (m_head->next == m_head)
            throw "queue is empty";
        return m_head->next->m_data;
    }
    // 获取队尾元素
    int back() const
    {
        if (m_head->next == m_head)
            throw "queue is empty";
        return m_head->prev->m_data;
    }
    // 判空
    bool empty() const
    {
        return m_head->next == m_head;
    }

private:
    struct Node
    {
        Node(int data = 0)
            : m_data(data), next(nullptr), prev(nullptr) {}
        int m_data;
        Node *next;
        Node *prev;
    };
    Node *m_head; // 指向头节点
};

int main()
{
    system("chcp 65001");

    int arr[] = {12, 3, 54, 6, 71, 29, 80};
    LinkQueue q;
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