#include <iostream>
#include <memory>
#include <vector>
using namespace std;

// 节点类型
struct Node
{
    Node(int m = 0) : data(m), next(nullptr) {} // 默认初始化结点
    int data;
    Node *next;
};

// 单链表
class Clink
{
public:
    Clink()
    {
        // 给head初始化指向头结点
        m_head = new Node();
    }
    ~Clink()
    {
        // 节点的释放(需迭代挨个删除所有节点)
        auto p = m_head;
        while (p != nullptr)
        {
            m_head = m_head->next; // 将头节点后移
            delete p;              // 删除当前节点
            p = m_head;            // 更新头节点(代替p=p->next)
        }
        m_head = nullptr;
    }

public:
    // 链表尾插法  O(n)
    void insertTail(int val)
    {
        // 先找到当前链表的末尾节点
        auto p = m_head;
        while (p->next != nullptr)
            p = p->next;

        // 生成新节点
        Node *node = new Node(val);
        // 新节点挂在尾节点
        p->next = node;
    }
    // 链表头插法  O(1)
    void insertHead(int val)
    {
        Node *node = new Node(val); // 生成新节点
        node->next = m_head->next;
        m_head->next = node;
    }
    // 链表节点的删除（删除单个指定元素）
    void remove(int val)
    {
        auto curr = m_head->next;
        auto prev = m_head; // 创建临时节点保存要删除节点
        while (curr != nullptr)
        {
            if (curr->data == val)
            {
                prev->next = curr->next;
                delete curr;
                return;
            }
            else
            {
                prev = curr;       // 保存当前节点
                curr = curr->next; // 迭代节点
            }
        }
    }
    // 链表节点的删除（删除多个指定元素）
    void removeAll(int val)
    {
        auto curr = m_head->next;
        auto prev = m_head; // 创建临时节点保存要删除节点
        while (curr != nullptr)
        {
            if (curr->data == val)
            {
                prev->next = curr->next;
                delete curr;
                curr = prev->next; // 重置迭代节点（指向前一节点的下节点，即新的当前节点）
            }
            else
            {
                prev = curr;       // 保存当前节点
                curr = curr->next; // 迭代节点
            }
        }
    }

    // 链表打印
    void show()
    {
        auto p = m_head->next;
        while (p != nullptr)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
    //查找
    bool find(int val)
    {
        auto p = m_head->next;
        while(p != nullptr)
        {
            if(p->data == val)
                return true;
            else
                p = p->next;
            return false;
        }
    }

private:
    Node *m_head; // 指向链表的头节点
};

int main()
{
    Clink link;
    for (int i = 0; i != 10; ++i)
        link.insertHead(i);
    for (int i = 0; i != 10; ++i)
        link.insertTail(i);
    link.show();

    link.remove(9);
    link.show();

    link.removeAll(8);
    link.show();

    if(link.find(3))
        cout<<"元素3存在"<<endl;

    return 0;
}
