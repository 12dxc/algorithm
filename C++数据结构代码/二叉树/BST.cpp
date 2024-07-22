#include <iostream>
#include <functional>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

// BST 二叉搜索树实现
template <typename T, typename Comp = less<T>>
class BSTree
{
public:
    //友元测试函数
    friend void test1();
public:
    BSTree(Comp comp = Comp())
        : root_(nullptr), comp_(comp) {}
    ~BSTree()
    {
        //使用层序遍历，来逐个删除节点
        queue<Node*> q;
        q.push(root_);
        while (!q.empty())
        {
            Node* front = q.front();
            q.pop();

            //迭代  分别加入左右孩子
            if (front->lchild != nullptr)
                q.push(front->lchild);
            if (front->rchild != nullptr)
                q.push(front->rchild);
            delete front;
        }
    }

public:
    // 非递归插入操作
    void n_insert(const T& val)
    {
        // 树为空，生成新节点
        if (root_ == nullptr)
        {
            root_ = new Node(val);
            return;
        }

        // 搜索合适的插入位置，记录父节点的位置
        Node* parent = nullptr;
        Node* cur = root_;
        // 遍历二叉树
        while (cur != nullptr)
        {
            if (cur->data_ == val)
            {
                return; // 不插入元素相同的值
            }
            else if (comp_(cur->data_, val))
            {

                parent = cur;
                cur = cur->rchild;
            }
            else // 大于
            {
                parent = cur;
                cur = cur->lchild;
            }
        }

        // 把新节点插入到parent节点的孩子上
        if (comp_(val, parent->data_))
            parent->lchild = new Node(val);
        else
            parent->rchild = new Node(val);
    }
    // 递归插入操作
    void insert(const T& val)
    {
        root_ = insert(root_, val);
    }
    // 非递归删除操作
    void n_remove(const T& val)
    {
        /* 删除节点有三种情况：
         * 1、没有孩子的节点，父节点指针域nullptr
         * 2、有一个孩子，孩子写入父节点地址域
         * 3、删除的节点有两个孩子，找到前驱，用前驱覆盖待删节点，然后处理前驱，处理方式与1、2相同*/
        if (root_ == nullptr) // 树空直接返回
            return;

        // 搜索待删除节点
        Node* parent = nullptr; // 指向其父节点
        Node* cur = root_;      // 指向被删除节点
        // 遍历二叉树
        while (cur != nullptr)
        {
            if (cur->data_ == val)
            {
                break; // 找到待删除节点
            }
            else if (!comp_(cur->data_, val))
            {
                parent = cur;
                cur = cur->rchild;
            }
            else
            {
                parent = cur;
                cur = cur->lchild;
            }
        }
        // 未找到待删节点
        if (cur == nullptr)
            return;

        // 情况3 ->删除前驱节点（归结成情况1、2）
        if (cur->lchild != nullptr && cur->rchild != nullptr)
        {
            parent = cur; // 更新父节点
            // 找前驱节点  即左子树最右边的节点
            Node* pre = cur->lchild;
            while (pre->rchild != nullptr)
            {
                parent = pre;
                pre = pre->rchild;
            }
            cur->data_ = pre->data_; // 用前驱节点覆盖待删节点值
            cur = pre;               // 让cur指向前驱节点，转换成情况1、2
        }

        // cur指向删除节点，parent指向其父节点；统一处理情况1或2
        Node* child = cur->lchild;
        if (child == nullptr)
        {
            child = cur->rchild;
        }

        if (parent == nullptr) // 特殊情况  表示删除的是根节点
        {
            root_ = child;
        }
        else
        {
            // 把待删除节点的孩子(nullptr或者不空)写入其父节点相应的地址域
            if (parent->lchild == cur)
                parent->lchild = child;
            else
                parent->rchild = child;
        }
        delete cur; // 删除当前节点
    }
    // 递归删除操作
    void remove(const T& val)
    {
        root_ = remove(root_, val);
    }
    // 非递归查询操作
    bool n_query(const T& val)
    {
        Node* cur = root_;
        while (cur != nullptr)
        {
            if (cur->data_ == val)
                return true;
            else if (comp_(cur->data_, val))
                cur = cur->rchild;
            else
                cur = cur->lchild;
        }
        return false;
    }
    // 递归查询操作
    bool query(const T& val)
    {
        return query(root_, val) != nullptr;
    }
    // 递归前序遍历操作
    void preOrder()
    {
        cout << "[递归]前序遍历: " << endl;
        preOrder(root_);
        cout << endl;
    }
    // 非递归前序遍历操作  VLR
    void n_preOrder()
    {
        cout << "[非递归]前序遍历: " << endl;
        if (root_ == nullptr)
            return;
        stack<Node*> s;
        s.push(root_);
        while (!s.empty())
        {
            Node* top = s.top();
            s.pop();

            cout << top->data_ << " "; // V

            if (top->lchild != nullptr) // L
                s.push(top->lchild);
            if (top->rchild != nullptr) // R
                s.push(top->rchild);
        }
        cout << endl;
    }
    // 递归中序遍历操作
    void inOrder()
    {
        cout << "[递归]中序遍历: " << endl;
        inOrder(root_);
        cout << endl;
    }
    // 非递归中序遍历操作  LVR
    void n_inOrder()
    {
        cout << "[非递归]中序遍历: " << endl;
        if (root_ == nullptr)
            return;
        stack<Node*> s;
        Node* cur = root_;

        while (!s.empty() || cur != nullptr)
        {
            if (cur != nullptr)
            {
                s.push(cur);
                cur = cur->lchild;
            }
            else
            {
                Node* top = s.top();
                s.pop();
                cout << top->data_ << " ";
                cur = top->rchild;
            }
        }
        cout << endl;
    }
    // 递归后序遍历操作
    void postOrder()
    {
        cout << "[递归]后序遍历: " << endl;
        postOrder(root_);
        cout << endl;
    }
    // 非递归后序遍历操作  LRV
    void n_postOrder()
    {
        cout << "[非递归]后序遍历: " << endl;

        if (root_ == nullptr)
            return;

        stack<Node*> s1;
        stack<Node*> s2;
        s1.push(root_);
        while (!s1.empty())
        {
            Node* top = s1.top();
            s1.pop();

            s2.push(top);               // V
            if (top->lchild != nullptr) // L
                s1.push(top->lchild);
            if (top->rchild != nullptr) // R
                s1.push(top->rchild);
        }
        while (!s2.empty())
        {
            cout << s2.top()->data_ << " ";
            s2.pop();
        }
        cout << endl;
    }
    // 递归层序遍历操作
    void levelOrder()
    {
        cout << "[递归]层序遍历: " << endl;
        int h = high();
        for (int i = 0; i != h; ++i)
            levelOrder(root_, i);
        cout << endl;
    }
    // 非递归层序遍历操作
    void n_levelOrder()
    {
        cout << "[非递归]层序遍历: " << endl;
        if (root_ == nullptr)
            return;

        queue<Node*> que;
        que.push(root_);
        while (!que.empty())
        {
            Node* front = que.front();
            que.pop();

            cout << front->data_ << " ";
            if (front->lchild != nullptr)
                que.push(front->lchild);
            if (front->rchild != nullptr)
                que.push(front->rchild);
        }

        cout << endl;
    }
    // 递归求二叉树层数
    int high()
    {
        return high(root_);
    }
    // 递归求二叉树节点个数
    int number()
    {
        return number(root_);
    }
    // 对二叉树区间进行搜索
    void findRange(vector<T>& v, int l, int r)
    {
        findRange(v, root_, l, r);
    }
    //判断二叉树是不是二叉搜索树
    bool  isBST()
    {
        Node* prev = nullptr; //其前一节点
        return isBST(root_, prev);
    }
    //求倒数第k个节点 
    int i = 1;//记录节点位次
    int getVal(int k)
    {
        Node* node = getVal(root_, k);
        if (node == nullptr)
            throw"no find";
        else
            return node->data_;
    }
private:
    // 节点定义
    struct Node
    {
        Node(T data = T()) // T() 零构造
            : data_(data), lchild(nullptr), rchild(nullptr)
        {
        }

        T data_;      // 数据域
        Node* lchild; // 指向左孩子
        Node* rchild; // 指向有右孩子
    };

    Node* root_; // 指向BST树的根节点
    Comp comp_;  // 定义一个函数对象
private:         // 私有方法
    // 递归前序遍历的实现  VLR
    void preOrder(Node* node)
    {
        if (node != nullptr)
        {
            cout << node->data_ << " "; // V
            preOrder(node->lchild);     // L
            preOrder(node->rchild);     // R
        }
    }
    // 递归中序遍历的实现  LVR
    void inOrder(Node* node)
    {
        if (node != nullptr)
        {
            inOrder(node->lchild);      // L
            cout << node->data_ << " "; // V
            inOrder(node->rchild);      // R
        }
    }
    // 递归后序遍历的实现  LRV
    void postOrder(Node* node)
    {
        if (node != nullptr)
        {
            postOrder(node->lchild);    // L
            postOrder(node->rchild);    // R
            cout << node->data_ << " "; // V
        }
    }
    // 递归层序遍历的实现
    void levelOrder(Node* node, int i)
    {
        if (node == nullptr)
            return;

        if (i == 0)
        {
            cout << node->data_ << " ";
            return;
        }
        levelOrder(node->lchild, i - 1);
        levelOrder(node->rchild, i - 1);
    }
    // 递归实现求二叉树层数 求以node为根节点的子树的高度并返回高度值
    int high(Node* node)
    {
        if (node == nullptr)
            return 0;
        int left = high(node->lchild);
        int right = high(node->rchild);

        return left > right ? left + 1 : right + 1;
    }
    // 递归求二叉树节点个数的实现 求以node为根节点的树的节点总数，并返回
    int number(Node* node)
    {
        if (node == nullptr)
            return 0;
        int left = number(node->lchild);  // L
        int right = number(node->rchild); // R
        return left + right + 1;          // V
    }
    // 递归插入实现
    Node* insert(Node* node, const T& val)
    {
        if (node == nullptr)
            return (new Node(val));

        if (node->data_ == val)
            return node;
        else if (comp_(node->data_, val))
            node->rchild = insert(node->rchild, val);
        else
            node->lchild = insert(node->lchild, val);
        return node;
    }
    // 递归查询实现
    Node* query(Node* node, const T& val)
    {
        if (node->data_ == val)
            return node;
        else if (comp_(node->data_, val))
            node->rchild = query(node->rchild, val);
        else
            node->lchild = query(node->lchild, val);
        return nullptr;
    }
    // 递归删除实现
    Node* remove(Node* node, const T& val)
    {
        // 空树
        if (node == nullptr)
            return nullptr;

        // 找到待删节点
        if (node->data_ == val)
        {
            // 情况3
            if (node->lchild != nullptr && node->rchild != nullptr)
            {
                // 找到前驱节点
                Node* pre = node->lchild;
                while (pre->rchild != nullptr)
                {
                    pre = pre->rchild;
                }
                node->data_ = pre->data_; // 用前驱节点覆盖待删节点
                // 通过递归直接删除前驱节点
                node->lchild = remove(node->lchild, pre->data_);
            }
            else // 情况1、2
            {
                if (node->lchild != nullptr)
                {
                    // 删除节点以后，把非空的左孩子返回，回溯时更新其父节点地址域
                    Node* left = node->lchild;
                    delete node;
                    return left;
                }
                else if (node->rchild != nullptr)
                {
                    // 删除节点以后，把非空的右孩子返回，回溯时更新其父节点地址域
                    Node* right = node->rchild;
                    delete node;
                    return right;
                }
                else // 删除的是没有孩子的节点  叶子节点
                {
                    delete node;
                    return nullptr; // 回溯时更新其父节点地址域为nullptr
                }
            }
        }
        else if (comp_(node->data_, val))
        {
            node->rchild = remove(node->rchild, val);
        }
        else
        {
            node->lchild = remove(node->lchild, val);
        }

        return node;
    }
    // 对二叉树区间进行搜索实现
    void findRange(vector<T>& v, Node* node, int l, int r)
    {
        if (node != nullptr)
        {
            //1、使用中序遍历BST树，得到有序元素序列
            findRange(v, node->lchild, l, r); // L
            //满足区间条件加入数组
            if (node->data_ >= l && node->data_ <= r)
                v.push_back(node->data_);     // V
            findRange(v, node->rchild, l, r); // R
        }
    }
    //判断二叉树是不是二叉搜索树实现
    bool isBST(Node* node, Node*& pre)
    {
        if (node == nullptr)  //递归到尽头，说明未触发条件，是BST树，返回true
            return true;
        //中序遍历树,可得到升序序列，如果前驱节点大于当前元素，说明不是BST树

        //中序遍历
        if (!isBST(node->lchild, pre))  // L 
            return false; // 如果递归函数内返回false，则不是BST树，直接返回false
        if (pre != nullptr)  // V 
            if (pre->data_ > node->data_)// 主要的判断
                return false;
        pre = node;  //更新前驱节点
        //递归函数直接返回，递归结果
        return isBST(node->rchild, pre);  // R
    }
    //求倒数第k个节点
    Node* getVal(Node* node, int k)
    {
        if (node == nullptr)
            return nullptr;

        getVal(node->rchild, k);
        if (i++ == k)
            return node;
        getVal(node->lchild, k);
        return node;
    }
};

//测试函数
void test1()   // 测试是否是BST树
{
    using Node = BSTree<int>::Node;
    BSTree<int> bst;
    bst.root_ = new Node(40);
    Node* node1 = new Node(20);
    Node* node2 = new Node(60);
    Node* node3 = new Node(30);
    Node* node4 = new Node(80);

    bst.root_->lchild = node1;
    bst.root_->rchild = node2;
    node2->lchild = node3;
    node2->rchild = node4;

    cout << bst.isBST() << endl;
}

int main()
{
    //test1();
    int arr[] = { 58, 24, 67, 0, 34, 62, 69, 5, 41, 64, 78 };
    BSTree<int> bst;
    for (auto i : arr)
        bst.insert(i);
    bst.inOrder();
    cout << bst.getVal(4) << endl;
    //cout << bst.isBST();
    // 测试插入、删除和查找
    /* bst.n_insert(12);
    cout << bst.n_query(12) << endl;

    bst.n_remove(12);
    bst.n_remove(34);
    bst.n_remove(58);

    cout << bst.n_query(12) << endl;*/

    // 测试递归版删除、查询
    /*bst.insert(12);
    bst.inOrder();
    bst.remove(12);
    bst.remove(34);
    bst.remove(58);
    bst.inOrder();*/

    // 测试遍历
    /*bst.preOrder();
    bst.n_preOrder();
    bst.inOrder();
    bst.n_inOrder();
    bst.postOrder();
    bst.n_postOrder();

    cout << "树高: " << bst.high() << "\n"
         << "节点个数: " << bst.number() << endl;
    bst.levelOrder();
    bst.n_levelOrder();*/

    //测试搜索区间元素
    /*vector<int> v;
    bst.findRange(v, 10, 50);
    bst.inOrder();
    printf("BST中10~50的元素: ");
    for (auto i : v)
        cout << i << " ";
    cout << endl;*/

    system("pause");
    return 0;
}