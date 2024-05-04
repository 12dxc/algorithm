#include <iostream>
#include <functional>
#include <stdlib.h>
#include <time.h>
using namespace std;

// 优先队列实现
class PriorityQueue
{
public:
    using Comp = function<bool(int, int)>;

    PriorityQueue(int cap = 20, Comp comp = greater<int>())
        : m_size(0), m_cap(cap), m_comp(comp)
    {
        m_que = new int[m_cap];
    }
    PriorityQueue(Comp comp)
        : m_size(0), m_cap(20), m_comp(comp)
    {
        m_que = new int[m_cap];
    }
    ~PriorityQueue()
    {
        delete[] m_que;
        m_que = nullptr;
    }

public:
    // 入堆操作
    void push(int val)
    {
        // 判断扩容
        if (m_size == m_cap)
        {
            int *p = new int[2 * m_cap];
            for (int i = 0; i != m_size; ++i)
                p[i] = m_que[i];
            delete[] m_que;
            m_que = p;
            m_cap *= 2;
        }
        if (m_size == 0)
        {
            // 只有一个元素，不用进行堆的上浮调整
            m_que[m_size] = val;
        }
        else
        {
            // 堆里面有多个元素，需进行上浮调整
            siftUp(m_size, val);
        }
        ++m_size;
    }
    // 出堆操作
    void pop()
    {
        if (m_size == 0)
            throw "PriorityQueue is empty";

        --m_size;
        if (m_size > 0)
        {
            // 删除堆顶元素，还有剩余元素，要进行堆的下沉调整
            siftDown(0, m_que[m_size]);
        }
    }
    bool empty() const { return m_size == 0; }
    int top() const
    {
        if (m_size == 0)
            throw "PriorityQueue is empty";
        return m_que[0];
    }
    int size() const { return m_size; }

private:
    int *m_que;  // 指向动态扩容的数组
    int m_size;  // 数组元素的个数
    int m_cap;   // 数组的总空间大小
    Comp m_comp; // 比较器对象

    // 入堆上浮调整  O(logn)
    void siftUp(int i, int val)
    {
        while (i > 0) // 最多计算到根节点（0号位）
        {
            int father = (i - 1) / 2; // 父节点
            if (m_comp(val, m_que[father]))
            {
                m_que[i] = m_que[father];
                i = father;
            }
            else
            {
                break;
            }
        }
        // 把val放到i的位置
        m_que[i] = val;
    }
    // 出堆的下沉调整  O(logn)
    void siftDown(int i, int val)
    {
        // i下沉不能超过最后一个有孩子的节点
        while (i < m_size / 2) // (n-1)/2 最后一个非叶子节点的下标
        {
            int child = 2 * i + 1; // 第i个节点的左孩子
            if (child + 1 < m_size && m_comp(m_que[child + 1], m_que[child]))
            {
                // 如果i节点右孩子的值大于左孩子，child记录右孩子的下标
                child = child + 1;
            }

            if (m_comp(m_que[child], val))
            {
                m_que[i] = m_que[child];
                i = child;
            }
            else
            {
                break; // 已经满足堆的性质，提前结束
            }
        }
        m_que[i] = val;
    }
};

int main()
{
    PriorityQueue que; // 基于大根堆实现的优先级队列

    // 基于小根堆实现的优先级队列  可根据函数对象对容器进行性质的更改
    // PriorityQueue que([](int a, int b){ return a < b; });

    srand(time(NULL));
    for (int i = 0; i != 10; ++i)
        que.push(rand() % 100);

    while (!que.empty())
    {
        cout << que.top() << " ";
        que.pop();
    }
    cout << endl;

    return 0;
}