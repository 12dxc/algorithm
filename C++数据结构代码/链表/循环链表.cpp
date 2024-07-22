#include<iostream>
using namespace std;

//单向循环链表
class CircleLink
{
public:
    CircleLink()
    {
        head = new Node();
        tail = head;
        head->next = head;  //空循环链表，头结点next指向其本身
    }
    ~CircleLink()
    {
        Node* p = head->next;
        while (p != head)  //遍历结束条件即（尾节点==头节点)
        {
            head->next = p->next;  //头结点下一个元素后移
            delete p;  //释放当前节点
            p = head->next;   //迭代节点，即重指向头节点next
        }
        delete head;   //最后才del 头节点
    }
public:
    //尾插法  O(1)
    void insertTail(int val)
    {
        auto node = new Node(val);
        tail->next = node;    //将新结点挂在尾节点后
        node->next = head;    //新尾节点next须指向头节点
        tail = node;   //更新尾指针
    }
    //头插法  O(1)
    void insertHead(int val)
    {
        auto node = new Node(val);
        node->next = head->next;
        head->next = node;
        //如是空链表，tail也需更新指向新结点
        if (node->next == head)
            tail = node;
    }
    //删除节点
    void remove(int val)
    {
        auto q = head;
        auto p = head->next;
        while (p != head)
        {
            if (p->m_data == val)
            {   //找到删除节点
                q->next = p->next;
                delete p;
                //如果要删除的节点是尾节点，还需更新tail
                if (q->next == head)
                    tail = q;
                return;
            }
            else
            {
                q = p;
                p = p->next;
            }
        }
    }
    //查询
    bool find(int val) const
    {
        auto p = head->next;
        while (p != head)
        {
            if (p->m_data == val)
                return true;
            else
                p = p->next;
        }
        return false;
    }
    //打印
    void show() const
    {
        auto p = head->next;
        while (p != head)
        {
            cout << p->m_data << " ";
            p = p->next;
        }
        cout << endl;
    }
private:
    struct Node  //节点类型
    {
        Node(int data = 0) :m_data(data), next(nullptr) {}
        int m_data;
        Node* next;
    };
    Node* head;  //指向头节点
    Node* tail;  //指向尾节点
};

int main()
{
    system("chcp 65001");

    CircleLink clink;
    //头插
    for (int i = 0; i != 10; ++i)
        clink.insertHead(i);
    clink.show();
    //尾插
    for (int i = 0; i != 100; i += 10)
        clink.insertHead(i);
    clink.show();
    //删除
    clink.remove(0);
    clink.show();
    //查找
    if (clink.find(80))
        cout << "元素80在链表中" << endl;

    system("pause");
    return 0;
}