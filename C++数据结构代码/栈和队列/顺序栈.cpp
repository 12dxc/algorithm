#include<iostream>
using namespace std;

//顺序栈
class SepStack
{
public:       //固有方法
    SepStack(int size = 10) :m_top(0), m_cap(size)
    {
        mpStack = new int[size];
    }
    ~SepStack()
    {
        delete[] mpStack;
        mpStack = nullptr;
    }
public:      //专有方法
    //入栈
    void push(int val)
    {
        if (m_top == m_cap)   //栈满
            expand(2 * m_cap);  //扩容

        mpStack[m_top] = val;
        ++m_top;
    }
    //出栈
    void pop()
    {
        if (m_top == 0)
            throw "stack is empty";   //栈空执行删除则抛出异常
        --m_top;
    }
    //获取栈顶元素
    int top() const
    {
        if (m_top == 0)
            throw "stack is empty";   //栈空执行获取栈顶元素则抛出异常
        return mpStack[m_top - 1];
    }
    //栈是否为空
    bool empty() const
    {
        return m_top == 0;
    }
    //栈元素个数
    int size() const
    {
        return m_top;
    }
private:
    int* mpStack;
    int m_top;   //栈顶
    int m_cap;   //栈空间大小

    void expand(int size)
    {
        int* p = new int[size];
        for (int i = 0; i != m_top; ++i)
            p[i] = mpStack[i];
        delete[]mpStack;
        mpStack = p;
        m_cap = size;
    }
};


int main()
{
    system("chcp 65001");

    int arr[] = { 12,3,54,6,71,29,80 };
    SepStack s;
    //入栈
    for (int i : arr)
        s.push(i);
    //遍历栈
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();  //出栈
    }
    cout << endl;


    system("pause");
    return 0;
}