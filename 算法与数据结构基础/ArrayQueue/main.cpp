#include <iostream>
using namespace std;
#include "ArrayQueue.h"

// 测试用例
int main()
{
    // 创建队列
    ArrayQueue<int> queue;
    // 入队
    for (int i = 0; i < 10; i++)
    {
        queue.enqueue(i);
        cout << queue << endl;
        // 出队
        if (i % 3 == 2) // 每三次弹出一个元素
        {
            queue.dequeue();
        }
    }

    system("pause");
    return 0;
}