#include<iostream>
using namespace std;

//定义双向链表的节点类型
struct Node
{
    Node(int data = 0)
        :m_data(data),
        next(nullptr),
        prev(nullptr)
    {}
    int m_data;//数据域
    Node* next;//指向下一个节点
    Node* prev;//指向上一个节点
};

//双向链表
class DoubleLink
{
public:
    DoubleLink()
    {
        head = new Node();
    }
    ~DoubleLink()
    {
        Node* p = head;
        while (p != nullptr)
        {   //p->当前迭代节点
            head = head->next;//让头节点后移
            delete p;
            p = head;   //重置p 指向新的头节点
        }
    }
public:
    //头插法
    void insertHead(int val)
    {
        auto node = new Node(val);  //生成新节点
        //先改节点
        node->prev = head;   //新节点头指向 head
        node->next = head->next;   //新结点尾指向 head->next
        //再改链表
        if (head->next != nullptr)   //如果新插入的节点是第一个有效节点，无需进行下个操作
            head->next->prev = node;   //原头节点指向新节点
        head->next = node;      //head->next 指向新结点
    }
    void insertTail(int val)
    {
        //找到末尾节点
        auto p = head;
        while (p->next != nullptr)
            p = p->next;

        auto node = new Node(val);
        //连接指针 p->尾节点
        node->prev = p;
        p->next = node;  //新节点挂到链表末尾
    }
    //节点删除
    void remove(int val)
    {
        auto p = head->next;
        while (p != nullptr)
        {
            if (p->m_data == val)
            {   //删除p指向的节点
                p->prev->next = p->next;  //p->prev的next指针后移一位
                if (p->next != nullptr)   //p后边需有节点，才能连接p->next的头指针
                    p->next->prev = p->prev;  //p->next的prev指针前移一位
                //auto next = p->next; //删除多节点，保存迭代节点
                delete p;
                //p = next;
                return;
            }
            else
            {
                p = p->next;
            }
        }
    }
    //节点搜索
    bool find(int val)
    {
        auto p = head->next;
        while (p != nullptr)
        {
            if (p->m_data == val)
                return true;
            else
                p = p->next;
        }
        return false;
    }
    //链表节点输出
    void show()
    {
        auto p = head->next;
        while (p != nullptr)
        {
            cout << p->m_data << " ";
            p = p->next;
        }
        cout << endl;
    }
private:
    Node* head;//指向头节点
};


int main()
{
    system("chcp 65001");

    DoubleLink dlink;
    //插入
    for (int i = 0; i != 10; ++i)
        dlink.insertHead(i);
    dlink.show();
    for (int i = 0; i != 100; i += 10)
        dlink.insertTail(i);
    dlink.show();
    //删除
    dlink.remove(90);
    dlink.remove(9);
    dlink.show();

    //查找
    if (dlink.find(80))
        cout << "元素80在链表中" << endl;


    system("pause");
    return 0;
}