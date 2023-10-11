#include <iostream>
using namespace std;
#include "Queue.h"

template <class T>
class LinkedListQueue : public Queue<T>
{
private:
    struct Node
    {
        T e;
        Node *next;

        friend ostream &operator<<(ostream &os, const Node &node)
        {
            os << node.e;

            return os;
        }

        Node(T e, Node *next)
        {
            this->e = e;
            this->next = next;
        }

        Node(T e) : Node(e, nullptr) {}

        Node()
        {
            next = nullptr;
        }
    };

    Node *head;
    Node *tail;
    int m_size;

    friend ostream &operator<<(ostream &os, const LinkedListQueue &list)
    {
        os << "Queue: front ";

        // 类似迭代器的遍历
        for (Node *cur = list.head->next; cur != nullptr; cur = cur->next)
        {
            cout << (*cur) << "->";
        }
        os << "NULL tail";
        return os;
    }

public:
    LinkedListQueue()
    {
        head = nullptr;
        tail = nullptr;
        m_size = 0;
    }
    ~LinkedListQueue()
    {
        if (head)
        {
            Node *toDel = head;
            head = head->next;
            delete toDel;
        }
    }

    int size() override
    {
        return m_size;
    }
    bool isEmpty() override
    {
        return m_size == 0;
    }
    // 入队  在链表尾进行
    void enqueue(T e)
    {
        // 链表没有元素
        if (tail == nullptr)
        {
            tail = new Node(e);
            head = tail;
        }
        // 链表有元素
        else
        {
            // 尾指针的下一个结点创建新元素
            tail->next = new Node(e);
            // 尾指针指向当前尾结点的下一个元素
            tail = tail->next;
        }
        m_size++;
    }
    // 出队
    T dequeue()
    {
        if (isEmpty())
        {
            throw std::invalid_argument("不能从空队列中退出队列");
        }
        T ret = head->e;
        // 创建一个临时对象指向头结点
        Node *retNode = head;
        // 头结点指向下一个元素
        head = head->next;
        delete retNode;

        // 如果出队后，队列为空
        if (head == nullptr)
        {
            tail = nullptr;
        }
        m_size--;
        return ret;
    }
    T getFront()
    {
        if (isEmpty())
        {
            throw std::invalid_argument("不能从空队列中返回队首元素");
        }
        return head->e;
    }
};
