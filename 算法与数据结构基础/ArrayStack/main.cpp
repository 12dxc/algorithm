#include <iostream>
using namespace std;
#include "ArrayStack.h"

int main()
{

    ArrayStack<int> stack;
    // 入栈
    for (int i = 10; i > 0; i--)
    {
        stack.push(i);
    }
    cout << "入栈：" << endl
         << stack << endl;

    // 出栈
    stack.pop();
    cout << "出栈：" << endl
         << stack << endl;

    // 查看栈顶元素
    cout << "栈顶元素为：" << stack.peek() << endl;

    // 测试栈是否为空，不为空打印栈的大小和容量
    if (!stack.isEmpty())
    {
        cout << "栈大小：" << stack.size() << " 栈容量：" << stack.capacity() << endl;
    }

    system("pause");
    return 0;
}