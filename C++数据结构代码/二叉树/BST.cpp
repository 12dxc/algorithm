#include <iostream>
#include <functional>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

// BST ����������ʵ��
template <typename T, typename Comp = less<T>>
class BSTree
{
public:
    //��Ԫ���Ժ���
    friend void test1();
public:
    BSTree(Comp comp = Comp())
        : root_(nullptr), comp_(comp) {}
    ~BSTree()
    {
        //ʹ�ò�������������ɾ���ڵ�
        queue<Node*> q;
        q.push(root_);
        while (!q.empty())
        {
            Node* front = q.front();
            q.pop();

            //����  �ֱ�������Һ���
            if (front->lchild != nullptr)
                q.push(front->lchild);
            if (front->rchild != nullptr)
                q.push(front->rchild);
            delete front;
        }
    }

public:
    // �ǵݹ�������
    void n_insert(const T& val)
    {
        // ��Ϊ�գ������½ڵ�
        if (root_ == nullptr)
        {
            root_ = new Node(val);
            return;
        }

        // �������ʵĲ���λ�ã���¼���ڵ��λ��
        Node* parent = nullptr;
        Node* cur = root_;
        // ����������
        while (cur != nullptr)
        {
            if (cur->data_ == val)
            {
                return; // ������Ԫ����ͬ��ֵ
            }
            else if (comp_(cur->data_, val))
            {

                parent = cur;
                cur = cur->rchild;
            }
            else // ����
            {
                parent = cur;
                cur = cur->lchild;
            }
        }

        // ���½ڵ���뵽parent�ڵ�ĺ�����
        if (comp_(val, parent->data_))
            parent->lchild = new Node(val);
        else
            parent->rchild = new Node(val);
    }
    // �ݹ�������
    void insert(const T& val)
    {
        root_ = insert(root_, val);
    }
    // �ǵݹ�ɾ������
    void n_remove(const T& val)
    {
        /* ɾ���ڵ������������
         * 1��û�к��ӵĽڵ㣬���ڵ�ָ����nullptr
         * 2����һ�����ӣ�����д�븸�ڵ��ַ��
         * 3��ɾ���Ľڵ����������ӣ��ҵ�ǰ������ǰ�����Ǵ�ɾ�ڵ㣬Ȼ����ǰ��������ʽ��1��2��ͬ*/
        if (root_ == nullptr) // ����ֱ�ӷ���
            return;

        // ������ɾ���ڵ�
        Node* parent = nullptr; // ָ���丸�ڵ�
        Node* cur = root_;      // ָ��ɾ���ڵ�
        // ����������
        while (cur != nullptr)
        {
            if (cur->data_ == val)
            {
                break; // �ҵ���ɾ���ڵ�
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
        // δ�ҵ���ɾ�ڵ�
        if (cur == nullptr)
            return;

        // ���3 ->ɾ��ǰ���ڵ㣨�������1��2��
        if (cur->lchild != nullptr && cur->rchild != nullptr)
        {
            parent = cur; // ���¸��ڵ�
            // ��ǰ���ڵ�  �����������ұߵĽڵ�
            Node* pre = cur->lchild;
            while (pre->rchild != nullptr)
            {
                parent = pre;
                pre = pre->rchild;
            }
            cur->data_ = pre->data_; // ��ǰ���ڵ㸲�Ǵ�ɾ�ڵ�ֵ
            cur = pre;               // ��curָ��ǰ���ڵ㣬ת�������1��2
        }

        // curָ��ɾ���ڵ㣬parentָ���丸�ڵ㣻ͳһ�������1��2
        Node* child = cur->lchild;
        if (child == nullptr)
        {
            child = cur->rchild;
        }

        if (parent == nullptr) // �������  ��ʾɾ�����Ǹ��ڵ�
        {
            root_ = child;
        }
        else
        {
            // �Ѵ�ɾ���ڵ�ĺ���(nullptr���߲���)д���丸�ڵ���Ӧ�ĵ�ַ��
            if (parent->lchild == cur)
                parent->lchild = child;
            else
                parent->rchild = child;
        }
        delete cur; // ɾ����ǰ�ڵ�
    }
    // �ݹ�ɾ������
    void remove(const T& val)
    {
        root_ = remove(root_, val);
    }
    // �ǵݹ��ѯ����
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
    // �ݹ��ѯ����
    bool query(const T& val)
    {
        return query(root_, val) != nullptr;
    }
    // �ݹ�ǰ���������
    void preOrder()
    {
        cout << "[�ݹ�]ǰ�����: " << endl;
        preOrder(root_);
        cout << endl;
    }
    // �ǵݹ�ǰ���������  VLR
    void n_preOrder()
    {
        cout << "[�ǵݹ�]ǰ�����: " << endl;
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
    // �ݹ������������
    void inOrder()
    {
        cout << "[�ݹ�]�������: " << endl;
        inOrder(root_);
        cout << endl;
    }
    // �ǵݹ������������  LVR
    void n_inOrder()
    {
        cout << "[�ǵݹ�]�������: " << endl;
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
    // �ݹ�����������
    void postOrder()
    {
        cout << "[�ݹ�]�������: " << endl;
        postOrder(root_);
        cout << endl;
    }
    // �ǵݹ�����������  LRV
    void n_postOrder()
    {
        cout << "[�ǵݹ�]�������: " << endl;

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
    // �ݹ�����������
    void levelOrder()
    {
        cout << "[�ݹ�]�������: " << endl;
        int h = high();
        for (int i = 0; i != h; ++i)
            levelOrder(root_, i);
        cout << endl;
    }
    // �ǵݹ�����������
    void n_levelOrder()
    {
        cout << "[�ǵݹ�]�������: " << endl;
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
    // �ݹ������������
    int high()
    {
        return high(root_);
    }
    // �ݹ���������ڵ����
    int number()
    {
        return number(root_);
    }
    // �Զ����������������
    void findRange(vector<T>& v, int l, int r)
    {
        findRange(v, root_, l, r);
    }
    //�ж϶������ǲ��Ƕ���������
    bool  isBST()
    {
        Node* prev = nullptr; //��ǰһ�ڵ�
        return isBST(root_, prev);
    }
    //������k���ڵ� 
    int i = 1;//��¼�ڵ�λ��
    int getVal(int k)
    {
        Node* node = getVal(root_, k);
        if (node == nullptr)
            throw"no find";
        else
            return node->data_;
    }
private:
    // �ڵ㶨��
    struct Node
    {
        Node(T data = T()) // T() �㹹��
            : data_(data), lchild(nullptr), rchild(nullptr)
        {
        }

        T data_;      // ������
        Node* lchild; // ָ������
        Node* rchild; // ָ�����Һ���
    };

    Node* root_; // ָ��BST���ĸ��ڵ�
    Comp comp_;  // ����һ����������
private:         // ˽�з���
    // �ݹ�ǰ�������ʵ��  VLR
    void preOrder(Node* node)
    {
        if (node != nullptr)
        {
            cout << node->data_ << " "; // V
            preOrder(node->lchild);     // L
            preOrder(node->rchild);     // R
        }
    }
    // �ݹ����������ʵ��  LVR
    void inOrder(Node* node)
    {
        if (node != nullptr)
        {
            inOrder(node->lchild);      // L
            cout << node->data_ << " "; // V
            inOrder(node->rchild);      // R
        }
    }
    // �ݹ���������ʵ��  LRV
    void postOrder(Node* node)
    {
        if (node != nullptr)
        {
            postOrder(node->lchild);    // L
            postOrder(node->rchild);    // R
            cout << node->data_ << " "; // V
        }
    }
    // �ݹ���������ʵ��
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
    // �ݹ�ʵ������������� ����nodeΪ���ڵ�������ĸ߶Ȳ����ظ߶�ֵ
    int high(Node* node)
    {
        if (node == nullptr)
            return 0;
        int left = high(node->lchild);
        int right = high(node->rchild);

        return left > right ? left + 1 : right + 1;
    }
    // �ݹ���������ڵ������ʵ�� ����nodeΪ���ڵ�����Ľڵ�������������
    int number(Node* node)
    {
        if (node == nullptr)
            return 0;
        int left = number(node->lchild);  // L
        int right = number(node->rchild); // R
        return left + right + 1;          // V
    }
    // �ݹ����ʵ��
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
    // �ݹ��ѯʵ��
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
    // �ݹ�ɾ��ʵ��
    Node* remove(Node* node, const T& val)
    {
        // ����
        if (node == nullptr)
            return nullptr;

        // �ҵ���ɾ�ڵ�
        if (node->data_ == val)
        {
            // ���3
            if (node->lchild != nullptr && node->rchild != nullptr)
            {
                // �ҵ�ǰ���ڵ�
                Node* pre = node->lchild;
                while (pre->rchild != nullptr)
                {
                    pre = pre->rchild;
                }
                node->data_ = pre->data_; // ��ǰ���ڵ㸲�Ǵ�ɾ�ڵ�
                // ͨ���ݹ�ֱ��ɾ��ǰ���ڵ�
                node->lchild = remove(node->lchild, pre->data_);
            }
            else // ���1��2
            {
                if (node->lchild != nullptr)
                {
                    // ɾ���ڵ��Ժ󣬰ѷǿյ����ӷ��أ�����ʱ�����丸�ڵ��ַ��
                    Node* left = node->lchild;
                    delete node;
                    return left;
                }
                else if (node->rchild != nullptr)
                {
                    // ɾ���ڵ��Ժ󣬰ѷǿյ��Һ��ӷ��أ�����ʱ�����丸�ڵ��ַ��
                    Node* right = node->rchild;
                    delete node;
                    return right;
                }
                else // ɾ������û�к��ӵĽڵ�  Ҷ�ӽڵ�
                {
                    delete node;
                    return nullptr; // ����ʱ�����丸�ڵ��ַ��Ϊnullptr
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
    // �Զ����������������ʵ��
    void findRange(vector<T>& v, Node* node, int l, int r)
    {
        if (node != nullptr)
        {
            //1��ʹ���������BST�����õ�����Ԫ������
            findRange(v, node->lchild, l, r); // L
            //��������������������
            if (node->data_ >= l && node->data_ <= r)
                v.push_back(node->data_);     // V
            findRange(v, node->rchild, l, r); // R
        }
    }
    //�ж϶������ǲ��Ƕ���������ʵ��
    bool isBST(Node* node, Node*& pre)
    {
        if (node == nullptr)  //�ݹ鵽��ͷ��˵��δ������������BST��������true
            return true;
        //���������,�ɵõ��������У����ǰ���ڵ���ڵ�ǰԪ�أ�˵������BST��

        //�������
        if (!isBST(node->lchild, pre))  // L 
            return false; // ����ݹ麯���ڷ���false������BST����ֱ�ӷ���false
        if (pre != nullptr)  // V 
            if (pre->data_ > node->data_)// ��Ҫ���ж�
                return false;
        pre = node;  //����ǰ���ڵ�
        //�ݹ麯��ֱ�ӷ��أ��ݹ���
        return isBST(node->rchild, pre);  // R
    }
    //������k���ڵ�
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

//���Ժ���
void test1()   // �����Ƿ���BST��
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
    // ���Բ��롢ɾ���Ͳ���
    /* bst.n_insert(12);
    cout << bst.n_query(12) << endl;

    bst.n_remove(12);
    bst.n_remove(34);
    bst.n_remove(58);

    cout << bst.n_query(12) << endl;*/

    // ���Եݹ��ɾ������ѯ
    /*bst.insert(12);
    bst.inOrder();
    bst.remove(12);
    bst.remove(34);
    bst.remove(58);
    bst.inOrder();*/

    // ���Ա���
    /*bst.preOrder();
    bst.n_preOrder();
    bst.inOrder();
    bst.n_inOrder();
    bst.postOrder();
    bst.n_postOrder();

    cout << "����: " << bst.high() << "\n"
         << "�ڵ����: " << bst.number() << endl;
    bst.levelOrder();
    bst.n_levelOrder();*/

    //������������Ԫ��
    /*vector<int> v;
    bst.findRange(v, 10, 50);
    bst.inOrder();
    printf("BST��10~50��Ԫ��: ");
    for (auto i : v)
        cout << i << " ";
    cout << endl;*/

    system("pause");
    return 0;
}