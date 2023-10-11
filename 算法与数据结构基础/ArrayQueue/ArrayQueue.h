#include "Queue.h"
#include "Array.h"

template <class T>
class ArrayQueue : public Queue<T>
{
private:
    Array<T> array;

    friend ostream &operator<<(ostream &os, const ArrayQueue<T> &queue)
    {
        os << "Queue: front [";

        for (int i = 0; i < queue.array.size(); i++)
        {
            os << queue.array.get(i);
            if (i != queue.array.size() - 1)
            {
                os << ", ";
            }
        }

        os << "] tail";

        return os;
    }

public:
    ArrayQueue(int capacity = 10) : array(capacity)
    {
    }
    // 返回队列大小
    int size() override
    {
        return array.size();
    }
    // 返回队列容量
    int capacity() override
    {
        return array.capacity();
    }
    // 返回队列是否为空
    bool isEmpty() override
    {
        return array.isEmpty();
    }
    // 入队
    void enqueue(T e) override
    {
        array.addLast(e);
    }
    // 出队
    T dequeue() override
    {
        return array.remove(0);
    }
    // 查看队首元素
    T getFront() override
    {
        return array.get(0);
    }
};