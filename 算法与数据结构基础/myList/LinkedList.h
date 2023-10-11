#include <iostream>
using namespace std;

template <class T>
class LinkedList
{
private:
    // 结点类
    struct Node
    {
    public:
        // 链表元素
        T e;
        // 指向下一个链表的节点
        Node *next;

        // 重载左移运算符，定义链表输出
        friend ostream &operator<<(ostream &os, const Node &node)
        {
            os << node.e;
            return os;
        }

        // 初始化链表
        // 构造函数传元素和指针
        Node(T e, Node *next)
        {
            this->e = e;
            this->next = next;
        }
        // 构造函数只传元素，指针默认为空
        Node(T e) : Node(e, nullptr) {}
        // 构造函数不传参
        Node()
        {
            next = nullptr;
        }
    };

    Node *dummyHead;
    int m_size;

    // 重载<<运算符，设置链表输出方式
    friend ostream &operator<<(ostream &os, const LinkedList<T> &list)
    {
        for (Node *cur = list.dummyHead->next; cur != nullptr; cur = cur->next)
        {
            os << (*cur) << "->";
        }
        os << "NULL";
        return os;
    }

public:
    LinkedList()
    {
        dummyHead = new Node();
        m_size = 0;
    }
    ~LinkedList()
    {
        Node *cur = dummyHead;

        while (cur)
        {
            Node *toDel = cur;
            cur = cur->next;
            delete toDel;
        }
    }
    // 获取链表中的元素个数
    int size()
    {
        return m_size;
    }
    // 获取链表是否为空
    bool isEmpty()
    {
        return m_size == 0;
    }

    // 获得链表的第index(0-based)个位置的元素
    // 在链表中不是一个常用的操作，练习用: )
    void add(int index, T e)
    {
        // 检查索引合法性
        if (index < 0 || index > m_size)
        {
            throw invalid_argument("添加失败，非法索引。");
        }

        // 先找到插入位置的前一个节点
        Node *pre = dummyHead;
        for (int i = 0; i < index; i++)
        {
            pre = pre->next;
        }

        // 创建新节点,使新节点next指向原前一个节点的next

        //  Node node = new Node(e);
        //  node.next = pre->next;
        //  pre->next = node;
        //  更简洁写法:
        pre->next = new Node(e, pre->next);

        m_size++;
    }
    // 在链表头添加新的元素
    void addFrist(T e)
    {
        add(0, e);
    }
    // 在链表末尾添加新的元素e
    void addLast(T e)
    {
        add(m_size - 1, e);
    }

    // 获得链表的第index(0-based)个位置的元素
    // 在链表中不是一个常用的操作，练习用: )
    T get(int index)
    {
        if (index < 0 || index > m_size)
        {
            throw invalid_argument("查找失败，非法索引。");
        }
        // 1、定义当前节点current，初始化为头节点
        Node *cur = dummyHead->next;
        // 2、使用for循环，循环index次，每次当前节点移到下一个
        for (int i = 0; i < index; i++)
        {
            cur = cur->next;
        }
        // 返回current的元素值
        return cur->e;
    }
    // 获取链表的第一个元素
    T getFrist()
    {
        return get(0);
    }
    // 获取链表的最后一个元素
    T getLast()
    {
        return get(m_size - 1);
    }

    // 修改链表的第index(0-based)个位置的元素为e
    // 在链表中不是一个常用的操作，练习用: )
    void set(int index, T e)
    {
        if (index < 0 || index > m_size)
        {
            throw invalid_argument("修改失败，非法索引。");
        }
        Node *cur = dummyHead->next;
        for (int i = 0; i < index; i++)
        {
            cur = cur->next;
        }
        cur.e = e;
    }

    // 查找链表中是否有元素e
    bool contains(T e)
    {
        // 1、定义一个当前节点current,初始化为头节点
        Node *cur = dummyHead->next;
        // 2、遍历链表,当前节点不为空时循环执行
        while (cur != nullptr)
        {
            // 比较当前节点的数据与要查找的数据
            if (cur->e = e)
            {
                // 3、如果相等,返回当前节点
                return true;
            }
            // 4、如果不等,current移动到下一个节点
            cur = cur->next;
        }
        return false;
    }

    // 从链表中删除index(0-based)位置的元素, 返回删除的元素
    // 在链表中不是一个常用的操作，练习用: )
    T remove(int index)
    {
        // 1. 检查索引合法性
        if (index < 0 || index >= m_size)
        {
            throw invalid_argument("删除失败,非法索引。");
        }

        // 2. 从dummy头节点开始,遍历到index位置的前一个节点
        Node *prv = dummyHead;
        for (int i = 0; i < index; i++)
        {
            prv = prv->next;
        }

        // 3. 记录下要删除的节点
        Node *retNode = prv->next;

        // 4. 保存要删除节点的值
        T ret = retNode->e;

        // 5. 修改前一个节点的next,跳过要删除的节点
        prv->next = retNode->next;

        // 6. 删除节点
        delete retNode;

        // 7.大小减1
        m_size--;

        // 8. 返回删除值
        return ret;
    }
    // 从链表中删除第一个元素, 返回删除的元素
    T removeFirst()
    {
        return remove(0);
    }
    // 从链表中删除最后一个元素, 返回删除的元素
    T removeLast()
    {
        return remove(m_size - 1);
    }
};
