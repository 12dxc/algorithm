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

//循环双向链表
class DoubleCircleLink
{
public:
    DoubleCircleLink()
    {
        head = new Node();
        //循环双向链表头节点的 头、尾指针指向自己
        head->next = head;
        head->prev = head;

    }
    ~DoubleCircleLink()
    {
        Node* p = head->next;
        while (p != head)
        {
            head->next = p->next;  //头节点后移
            p->next->prev = head;  //要删除节点的头指针指向头
            delete p;
            p = head->next;  //让p重新指向第一个节点，进行删除
        }
        delete head;
        head = nullptr;
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
        head->next->prev = node;   //原头节点指向新节点
        head->next = node;      //head->next 指向新结点
    }
    //尾插法  O(1)
    void insertTail(int val)
    {
        //找到末尾节点 即head的前一个节点
        auto p = head->prev;

        auto node = new Node(val);
        //连接指针 p->尾节点
        node->prev = p;
        node->next = head;
        p->next = node;
        head->prev = node;
    }
    //节点删除
    void remove(int val)
    {
        auto p = head->next;
        while (p != head)
        {
            if (p->m_data == val)
            {   //删除p指向的节点
                //修改指向p的指针，让其越过p 前后连接
                p->prev->next = p->next;
                p->next->prev = p->prev;
                delete p;
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
        while (p != head)
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
        while (p != head)
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

    DoubleCircleLink dlink;
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