#include "Stack.h"
#include "LinkedList.h"

template <class T>
class LinkedListStack : public Stack<T>
{
private:
    LinkedList<T> list;
    friend ostream &operator<<(ostream &os, const LinkedListStack<T> &lsitStack)
    {
        // 使输出方式为原链表的输出方式
        os << "Stack: top " << lsitStack.list;
        return os;
    }

public:
    LinkedListStack()
    {
    }
    // 返回栈大小
    int size() override
    {
        return list.size();
    }
    // 查看栈是否为空
    bool isEmpty() override
    {
        return list.isEmpty();
    }
    // 压栈
    void push(T e) override
    {
        list.addFrist(e);
    }
    // 出栈
    T pop() override
    {
        return list.removeFirst();
    }
    // 查看栈顶
    T peek() override
    {
        return list.getFrist();
    }
};
