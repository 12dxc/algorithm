#include "Array.h"
#include "Stack.h"

template <class T>
class ArrayStack : public Stack<T>
{

private:
    Array<T> array;

    friend ostream &operator<<(ostream &os, const ArrayStack<T> &stack)
    {
        os << "Stack: [";

        for (int i = 0; i < stack.array.size(); i++)
        {
            os << stack.array.get(i);
            if (i != stack.array.size() - 1)
            {
                os << ", ";
            }
        }

        os << "] top";

        return os;
    }

public:
    // 给予构造函数默认值，以不传参实例对象
    ArrayStack(int capacity = 10) : array(capacity) {}
    // 获取栈元素个数
    int size() override
    {
        return array.size();
    }
    // 查看栈是否为空
    bool isEmpty() override
    {
        return array.isEmpty();
    }
    // 查看栈容量
    int capacity() override
    {
        return array.capacity();
    }
    // 入栈
    void push(T e) override
    {
        array.addFrist(e);
    }
    // 出栈
    T pop() override
    {
        return array.remove(0);
    }
    // 查看栈顶元素
    T peek() override
    {
        return array.get(0);
    }
};
