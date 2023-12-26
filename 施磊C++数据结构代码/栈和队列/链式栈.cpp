#include<iostream>
using namespace std;

//链式栈
class LinkStack
{
public:
    LinkStack() :m_size(0)
    {
        head = new Node();
    }
    ~LinkStack()
    {
        auto p = head;
        while (p != nullptr)
        {
            head = head->next;
            delete p;
            p = head;
        }
    }
public:
    //入栈  O(1) 把链表头节点后面，第一个有效节点的位置，当作栈顶 
    void push(int val)
    {
        auto node = new Node(val);
        node->next = head->next;
        head->next = node;
        ++m_size;
    }
    //出栈  O(1)
    void pop()
    {
        if (head->next == nullptr)
            throw "stack is empty";  //栈空无法删除元素

        auto p = head->next;
        head->next = p->next;  //头节点next 后移1
        delete p;
        --m_size;
    }
    //弹出栈顶元素
    int top() const
    {
        if (head->next == nullptr)
            throw "stack is empty";  //栈空无法获取栈顶元素
        return head->next->m_data;
    }
    //判断栈空
    bool empty() const
    {
        return head->next == nullptr;
    }
    //返回栈元素个数  需遍历一遍链表,记录节点个数 O(n)
    int size() const
    {
        //增添成员变量 效率变 O(1)
        return m_size;
    }
private:
    struct Node
    {
        Node(int data = 0) :m_data(data), next(nullptr) {}
        int m_data;
        Node* next;
    };

    Node* head;
    int m_size;
};

int main()
{
    system("chcp 65001");

    int arr[] = { 12,3,54,6,71,29,80 };
    LinkStack s;
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