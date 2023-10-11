#include <iostream>
using namespace std;

template <class T>
class Array
{
    friend ostream &operator<<(ostream &os, const Array<T> &array)
    {
        os << "Array: size = " << array.m_size << " , capacity = " << array.m_capacity << endl;
        os << "[";
        for (int i = 0; i < array.m_size; i++)
        {
            os << array.m_data[i];
            if (i != array.m_size - 1)
            {
                os << ", ";
            }
        }
        os << "]";

        return os;
    }

public:
    // 构造函数，传入数组的容量capacity构造Array
    Array(int capacity = 10) : m_capacity(capacity) // 如果不传参，为默认构造创建长度10的数组
    {
        m_data = new T[capacity];
        m_size = 0;
    };
    ~Array()
    {
        // 释放堆内存空间
        delete[] m_data;
    }
    // 获取数组中元素的个数
    int size() const
    {
        return m_size;
    }
    // 获取数组的容量
    int capacity() const
    {
        return m_capacity;
    }
    // 获取是否为空
    bool isEmpty() const
    {
        return m_size == 0;
    }
    // 向所有元素后添加一个新元素
    void addLast(T e)
    {
        add(m_size, e);
    }
    // 向第一个元素添加位置
    void addFrist(T e)
    {
        add(0, e);
    }
    // 在第index个位置插入一个新元素
    void add(int index, T e)
    {
        // 输入索引超出数组条件 抛出异常
        if (index < 0 || index > m_size)
        {
            throw invalid_argument("添加失败!要求index >= 0且index <= size");
        }
        // 溢出 抛出异常
        if (m_size == m_capacity)
        {
            resize(1.5 * m_capacity);
        }

        for (int i = m_size - 1; i >= index; i--)
        {
            // 当后一个元素赋上前一个元素
            m_data[i + 1] = m_data[i];
        }
        m_data[index] = e;
        m_size++;
    }
    // 获取index索引位置的元素
    T get(int index) const
    {
        // 输入索引超出数组条件 抛出异常
        if (index < 0 || index >= m_size)
        {
            throw invalid_argument("添加失败!要求index >= 0且index <= size");
        }
        return m_data[index];
    }
    // 修改index索引位置的元素
    void set(int index, T e)
    {
        m_data[index] = e;
    }
    // 查找数组中是否有元素
    bool contains(T e)
    {
        for (int i = 0; i < m_size; i++)
        {
            if (m_data[i] == e)
            {
                return true;
            }
        }
        return false;
    }
    // 查找数组中元素所在的索引，如果不存在返回-1
    int find(T e)
    {
        for (int i = 0; i < m_size; i++)
        {
            if (m_data[i] == e)
            {
                return i;
            }
        }
        return -1;
    }
    // 删除数组中指定的元素
    T remove(int index)
    {
        if (index < 0 || index >= m_size)
        {
            throw invalid_argument("添加失败!要求index >= 0且index <= size");
        }
        T ret = m_data[index];
        for (int i = index + 1; i < m_size; i++)
        {
            m_data[i - 1] = m_data[i];
        };
        m_size--;

        // 为了以防数组震荡，当元素个数小于容量的1/3，再进行缩短
        if (m_size == m_capacity / 3 && m_capacity / 2 == 0)
        {
            resize(m_capacity / 1.5);
        }
        return ret;
    }
    // 从数组中删除元素e
    T removeElement(T e)
    {
        int index = find(e);
        if (index != -1)
        {
            remove(index);
        }
    }

private:
    // 数组指针
    T *m_data;
    // 数组大小
    int m_size;
    // 数组容量
    int m_capacity;

    // 使数组容量动态变化
    void resize(int newCapacity)
    {
        // 创建一个新数组，其容量等于传进来的容量参数
        T *newData = new T[newCapacity];
        // 遍历原来的数组，将原数组元素赋值给新数组
        for (int i = 0; i < m_size; i++)
        {
            newData[i] = m_data[i];
        }
        // 将数组指针改为新数组
        m_data = newData;
        // 同步新容量
        m_capacity = newCapacity;
    }
};
