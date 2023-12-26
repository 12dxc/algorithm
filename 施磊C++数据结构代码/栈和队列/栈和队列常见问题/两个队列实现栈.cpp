#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    MyStack() {
        q1 = new queue<int>();
        q2 = new queue<int>();
    }
    ~MyStack()
    {
        delete q1;
        delete q2;
    }

    void push(int x) {
        q1->push(x);
        while (!q2->empty())
        {
            q1->push(q2->front());
            q2->pop();
        }
        swap(q1, q2);
    }

    int pop() {
        int val = q2->front();
        q2->pop();
        return val;
    }

    int top() {
        return q2->front();
    }

    bool empty() {
        return q1->empty() && q2->empty();
    }
private:
    queue<int>* q1;  //指向新加入
    queue<int>* q2;
};
int main()
{


    system("pause");
    return 0;
}