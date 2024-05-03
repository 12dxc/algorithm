#include <iostream>
using namespace std;

/* 跳跃表 模板类 */
template <typename T>
class SkipList
{
public:
    // 构造函数
    SkipList()
    {
        head_ = new HeadNode(1); // 虚拟头val为初始化默认值
    }
    // 析构函数，逐层销毁跳跃表
    ~SkipList()
    {
        int level = head_->level_;
        for (int i = 0; i < level; i++)
        {
            Node *cur = head_->next_; // 保留头节点，待当前层都删完再删
            // 逐个删除当前层头节点之后的节点
            while (cur != nullptr)
            {
                Node *tmp = cur->next_;
                delete cur;
                cur = tmp;
            }
            // 删除当前层头节点
            cur = head_;
            head_ = static_cast<HeadNode *>(head_->down_); // 头节点下降
            delete cur;                                    // 删除之前层的头节点
        }
    }

public:
    // 查找元素
    bool find(T val)
    {
        Node *pre = head_;
        Node *cur = pre->next_;

        while (true)
        {
            // 遍历完当前层
            if (cur != nullptr)
            {
                // 链表只能从前向后遍历，如果当前不符则向后遍历
                if (cur->val_ < val)
                {
                    pre = cur;
                    cur = cur->next_;
                    continue; // 还未找完，跳出当前循环，不去执行跳到下层链表
                }
                // 找到了
                else if (cur->val_ == val)
                {
                    return true;
                }
            }
            // pre和cur已遍历至最后一层末尾
            if (pre->down_ == nullptr)
                break;

            // 继续向下层寻找
            pre = pre->down_;
            cur = pre->next_;
        }
        return false;
    }

    // 插入元素
    void insert(T val)
    {
        // 先查找数据是否存在
        if (find(val))
            return;

        // val数据需添加几层
        int level = getRandLevel();
        // level超过现有层数，SkipList只增长一层
        if (level > head_->level_)
        {
            level = head_->level_ + 1;
            HeadNode *hnode = new HeadNode(level); // 创建新头节点
            // 更新头节点
            hnode->down_ = head_;
            head_ = hnode;
        }

        // 先创建level层的data节点串，修改down指针域
        Node **nodeList = new Node *[level];
        // 自顶向下构建节点串
        for (int i = level - 1; i >= 0; i--)
        {
            nodeList[i] = new Node(val);
            // 非末尾节点，进行层级连接
            if (i < level - 1)
            {
                nodeList[i]->down_ = nodeList[i + 1];
            }
        }

        // 下降至之前决定上浮的最高层
        Node *head = head_;
        for (int i = head_->level_; i > level; i--)
            head = head->down_;

        // head指向了要插入节点的链表，逐层向下插入
        Node *pre = head;
        Node *cur = pre->next_;
        for (int i = 0; i < level; i++)
        {
            // 寻找插入节点位置
            while (cur != nullptr && cur->val_ < val)
            {
                pre = cur;
                cur = cur->next_;
            }

            // 新节点插入到pre和cur中间
            nodeList[i]->next_ = cur;
            pre->next_ = nodeList[i];

            // 节点下降
            pre = pre->down_;
            if (pre != nullptr)
                cur = pre->next_;
        }

        delete[] nodeList;
        nodeList = nullptr;
    }

    // 打印跳跃表元素
    void disply() const
    {
        Node *head = head_;
        int level = head_->level_;
        while (head != nullptr)
        {
            Node *cur = head;
            cout << "Level " << level-- << ": ";
            while (cur != nullptr)
            {
                cout << cur->val_ << "->";
                cur = cur->next_;
            }
            cout << endl;
            head = head->down_;
        }
        cout << endl;
    }

    // 删除元素
    void remove(T val)
    {
        Node *pre = head_;
        Node *cur = pre->next_;
        while (true)
        {
            // 不符合则继续向后寻找，直至遍历完当前层
            if (cur != nullptr)
            {
                if (cur->val_ < val)
                {
                    pre = cur;
                    cur = cur->next_;
                    continue;
                }
                else if (cur->val_ == val) // 找到了
                {
                    // 删除cur指向的节点
                    pre->next_ = cur->next_;
                    delete cur;
                }
            }

            // 找不到删除的元素
            if (pre->down_ == nullptr)
                break;

            // 继续向下层寻找
            pre = pre->down_;
            // 如果删除的是顶层元素，致使顶层链表只有一个元素，那么则删除顶层链表
            if (head_->next_ == nullptr)
            {
                delete head_;
                head_ = static_cast<HeadNode *>(pre);
            }
            cur = pre->next_;
        }
    }

private:
    // 获取一个随机数上浮层数，用于节点插入
    int getRandLevel() const
    {
        int level = 1;
        while (rand() % 2 == 1)
            level++;
        return level;
    }

    // 跳跃表节点类型
    struct Node
    {
        Node(T val = T())
            : val_(val), next_(nullptr), down_(nullptr) {}
        T val_;
        Node *next_, *down_;
    };
    // 跳跃表头节点
    struct HeadNode : public Node
    {
        HeadNode(int level) : level_(level) {}
        int level_;
    };

private:
    HeadNode *head_; // 指向跳表最上层链表的头节点
};

int main()
{
    // 测试跳跃表
    SkipList<int> list;
    srand(time(nullptr));

    for (int i = 0; i < 20; i++)
    {
        list.insert(rand() % 100);
    }

    list.insert(50);
    list.disply();

    list.remove(50);
    list.disply();

    return 0;
}