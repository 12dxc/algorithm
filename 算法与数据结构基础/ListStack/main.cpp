#include <iostream>
using namespace std;
#include "LinkedListStack.h"

int main()
{
    LinkedListStack<int> stack;
    // 依次向链表添加元素
    for (int i = 0; i < 5; i++)
    {
        stack.push(i);
        cout << stack << endl;
    }

    stack.push(666);

    cout << "压栈后，栈顶元素: " << stack.peek() << endl;

    system("pause");
    return 0;
}