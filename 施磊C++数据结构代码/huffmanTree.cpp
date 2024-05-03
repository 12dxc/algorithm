#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <functional>
using namespace std;

// 哈夫曼树类  用于编码压缩，串中出现越多的字符放的层数越高，越少则越低，根据出现次数的多少实现不定长的编码
class HuffmanTree
{
public:
    HuffmanTree()
        : root_(nullptr),
          minHeap_([](Node *n1, Node *n2) -> bool
                   { return n1->weight_ > n2->weight_; }){};
    ~HuffmanTree()
    {
        if (root_ == nullptr)
            return;

        queue<Node *> q;
        q.push(root_);
        while (!q.empty())
        {
            Node *node = q.front();
            q.pop();

            if (node->left != nullptr)
                q.push(node->left);
            if (node->right != nullptr)
                q.push(node->right);

            delete node;
        }
    }

    // 构造一棵哈夫曼树
    void create(string str)
    {
        // 先统计字符权值
        unordered_map<char, unsigned int> dataMap;
        for (char ch : str)
            dataMap[ch]++;

        // 生成节点，放入小根堆中
        for (auto &pair : dataMap)
            minHeap_.push(new Node(pair.first, pair.second));

        while (minHeap_.size() > 1)
        {
            // 获取两个权值最小的节点
            Node *n1 = minHeap_.top();
            minHeap_.pop();
            Node *n2 = minHeap_.top();
            minHeap_.pop();

            // 生成父节点，两节点权值相加构造出一个父节点，并将前面两个节点接至左右节点
            Node *node = new Node('\0', n1->weight_ + n2->weight_);
            node->left = n1;
            node->right = n2;
            // 生成好的父节点放回堆里，继续构造
            minHeap_.push(node);
        }
        root_ = minHeap_.top(); // 堆中最后的节点即根节点
        minHeap_.pop();
    }

    // 利用哈夫曼树进行编码  压缩
    string encode(string str)
    {
        // 编码前要构造哈夫曼映射
        getHuffmanCode();

        string encode_str;
        for (char ch : str)
            encode_str.append(codeMap_[ch]);

        return encode_str;
    }

    // 利用哈夫曼树进行解码  解压缩
    string decode(string encode)
    {
        string decode_str;
        Node *cur = root_;

        for (char ch : encode)
        {
            // 寻找对应字符存在的根节点
            if (ch == '0')
                cur = cur->left;
            else
                cur = cur->right;

            // 将根节点的字符加入到结果集
            if (cur->left == nullptr && cur->right == nullptr)
            {
                decode_str.push_back(cur->data_);
                cur = root_;
            }
        }

        return decode_str;
    }

    // 输出哈夫曼编码
    void getHuffmanCode()
    {
        string code;
        // 前序遍历
        getHuffmanCode(root_, code);
        // for (auto &pair : codeMap_)
        //     cout << pair.first << " : " << pair.second << endl;
        // cout << endl;
    }

private:
    struct Node
    {
        Node(char data, unsigned int weight)
            : data_(data), weight_(weight),
              left(nullptr), right(nullptr) {}

        char data_;           // 字符
        unsigned int weight_; // 权值
        Node *left, *right;
    };

private:
    // 内部递归方法，获取哈夫曼编码
    void getHuffmanCode(Node *root, string code)
    {
        // 前序遍历
        if (root->left == nullptr && root->right == nullptr)
        {
            codeMap_[root->data_] = code;
            return;
        }

        getHuffmanCode(root->left, code + "0");
        getHuffmanCode(root->right, code + "1");
    }

    Node *root_;                                                                     // 指向根节点
    unordered_map<char, string> codeMap_;                                            // 存储字符对应的哈夫曼编码
    priority_queue<Node *, vector<Node *>, function<bool(Node *, Node *)>> minHeap_; // 求权值的小根堆
};

int main()
{
    string str = "ABACDAEFDEG";

    HuffmanTree htree;
    htree.create(str);
    // htree.getHuffmanCode();

    string encode = htree.encode(str);
    cout << encode << endl;
    cout << htree.decode(encode) << endl;
}