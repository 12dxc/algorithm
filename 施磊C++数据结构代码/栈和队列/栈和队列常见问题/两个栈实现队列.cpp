#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    MyQueue() {

    }

    void push(int x) {
        s1.push(x);
    }

    int pop() {
        //判断s2是否有元素
        if (s2.empty())
            //若无，将s1所有元素放入s2中
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        int val = s2.top();  //保存栈顶元素
        s2.pop();
        return val;
    }

    int peek() {
        if (s2.empty())
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
private:
    stack<int>s1;
    stack<int>s2;
};


int main()
{


    system("pause");
    return 0;
}