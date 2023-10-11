#include "Queue.h"
#include <iostream>
using namespace std;

template <class T>
class LoopQueue : public Queue
{
private:
    T *m_data;
    int m_capacity;
    int front, tail;
    int m_size;

    // 动态扩容
    resize(int newCapacity)
    {
        T *newData = new T[newCapacity + 1];
        for (int i = 0; i < m_size; i++)
        {
            newData[i] = data[(front + i) % m_capacity];
        }
        data = newData;
        front = 0;
        tail = m_size;
    }

    // 重载 <<
    friend ostream &operator<<(ostream &os, const LoopQueue<T> queue)
    {
        os << "Queue: size = " << queue.m_size << " , capacity = " << queue.capacity() << endl;
        os << "front [";
        for (int i = queue.front; i != queue.tail; i = (i + 1) % queue.m_capacity)
        {
            os << queue.m_data[i];
            if ((i + 1) % queue.m_capacity != queue.tail)
            {
                os << ", ";
            }
        }
        os << "] tail";

        return os;
    }

public:
    LoopQueue(int capacity = 10)
    {
        m_data = new T[capacity + 1];
        m_capacity = capacity + 1;
        front = 0;
        tail = 0;
        m_size = 0;
    };
    ~LoopQueue()
    {
        delete[] m_data;
    }

    // 循环队列容量
    int capacity() const
    {
        return m_capacity - 1;
    }
    // 判断循环队列是否为空
    bool isEmpty() override
    {
        return (front == tail);
    }
    // 循环队列大小
    int size() override
    {
        return size;
    }
    // 入队
    void enqueue(T e) override
    {
        if ((tail + 1) % m_capacity == front)
        {
            resize(capacity() * 1.5);
        }
        m_data[tail] = e;
        tail = (tail + 1) % capacity;
        size++;
    }
    // 出队
    T dequeue() override
    {
        if (isEmpty())
        {
            throw invalid_argument("不能从空队列中退出队列");
        }
        T ret = m_data[front];
        front = (front + 1) & m_capacity;
        size--;
        if (m_size == m_capacity / 3 && m_capacity / 2 == 0)
        {
            resize(m_capacity / 1.5);
        }
        return ret;
    }
};
