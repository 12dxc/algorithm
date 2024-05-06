#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <queue>
using namespace std;

// 字典树
class TrieTree
{
public: // 默认方法
    TrieTree()
    {
        root_ = new TrieNode('\0', 0);
    }
    ~TrieTree()
    {
        // 利用层序遍历释放多叉树资源
        queue<TrieNode *> que;
        que.push(root_);
        while (!que.empty())
        {
            TrieNode *front = que.front();
            que.pop();
            // 把当前节点的孩子节点全部入队列
            for (auto pair : front->nodeMap_)
                que.push(pair.second);
            // 释放当前节点资源
            delete front;
        }
    }

public: // 自定义成员方法
    // 添加单词
    void add(const string &word)
    {
        // 从根节点开始遍历
        TrieNode *cur = root_;
        for (char ch : word)
        {
            auto childIt = cur->nodeMap_.find(ch);
            if (childIt == cur->nodeMap_.end())
            {
                // 相应字符的节点没有，创建它
                TrieNode *child = new TrieNode(ch, 0);
                cur->nodeMap_.emplace(ch, child); // 插入到当前节点的字符子树
                cur = child;                      // cur还需要继续向下迭代
            }
            else
            {
                // 相应的字符节点已经存在，移动cur执行对应的字符节点
                cur = childIt->second;
            }
        }
        // cur指向word单词的最后一个节点
        cur->freps_++;
    }

    // 删除节点
    void remove(const string &word)
    {
        TrieNode *cur = root_;
        TrieNode *del = root_; // 从哪个节点开始删除
        char delch = word[0];
        for (char ch : word)
        {
            auto childIt = cur->nodeMap_.find(ch);
            if (childIt == cur->nodeMap_.end())
                return;

            // 情况2: 待删单词中包含一个更短的单词，不可删除那个更短的单词，所以需要更新删除指针
            // 情况3: 与其他单词有公共前缀，不能删除与其他单词相同的前缀，所以需要更新删除指针
            if (cur->freps_ > 0 || cur->nodeMap_.size() > 1)
            {
                del = cur;
                delch = ch;
            }

            // cur移动到子节点
            cur = childIt->second;
        }

        // cur指向了末尾字符节点，word单词存在于字典树
        if (cur->nodeMap_.empty())
        {
            // 开始删除
            TrieNode *child = del->nodeMap_[delch];
            del->nodeMap_.erase(delch);

            // 释放相应的节点资源
            queue<TrieNode *> que;
            que.push(child);
            while (!que.empty())
            {
                TrieNode *front = que.front();
                que.pop();
                // 把当前节点的孩子节点全部入队列
                for (auto pair : front->nodeMap_)
                    que.push(pair.second);
                // 释放当前节点资源
                delete front;
            }
        }
        else
        {
            // 情况1: 待删单词末尾字符后面还有字符节点，即此单词包含在一个更长的单词中，故不做任何删除
            cur->freps_ = 0;
        }
    }

    // 查询单词
    int query(const string &word)
    {
        TrieNode *cur = root_;
        for (char ch : word)
        {
            auto childIt = cur->nodeMap_.find(ch);
            if (childIt == cur->nodeMap_.end())
                return 0;
            // 移动cur指向下一个单词的字符节点上
            cur = childIt->second;
        }
        return cur->freps_; // 出循环已经是最后一个节点，即匹配到了
    }

    // 前序遍历字典树 实现串排序
    void preOrder()
    {
        vector<string> wordList;
        preOrder(root_, string(), wordList);
        for (auto word : wordList)
            cout << word << " ";
        cout << endl;
    }

    // 串的前缀搜索
    vector<string> queryPrefix(const string &prefix)
    {
        TrieNode *cur = root_;
        for (char ch : prefix)
        {
            auto childIt = cur->nodeMap_.find(ch);
            if (childIt == cur->nodeMap_.end())
                return {};
            else
                cur = childIt->second;
        }

        // cur指向了前缀的最后一个字符
        vector<string> wordList;
        preOrder(cur, prefix.substr(0, prefix.size() - 1), wordList); // 排序方法会将当前指向的字符加入word，但是前缀已加入word，则前缀末尾会重复，故这里截掉前缀末尾
        return wordList;
    }

private: // 成员变量
    // 节点类型定义
    struct TrieNode
    {
        TrieNode(char ch, int freps)
            : ch_(ch), freps_(freps) {}

    public:
        char ch_;                       // 节点存储的字符数据
        int freps_;                     // 单词的末尾字符及存储的单词数量（频率）
        map<char, TrieNode *> nodeMap_; // 存储孩子节点的字符数据和节点指针的对应关系，这里使用红黑树是因为需要实现字符排序
    };

    TrieNode *root_; // 根节点

private: // 私有成员方法
    void preOrder(TrieNode *node, string word, vector<string> &wordList)
    {
        // 前序遍历  VLR
        if (node != nullptr)
            word.push_back(node->ch_);
        if (node->freps_ > 0)
            // 已经遍历到一个有效单词
            wordList.emplace_back(word);

        // 递归处理孩子节点
        for (auto pair : node->nodeMap_)
            preOrder(pair.second, word, wordList);
    }
};

int main()
{
    TrieTree trie;
    trie.add("hello");
    trie.add("hello");
    trie.add("helloo");
    trie.add("hel");
    trie.add("hel");
    trie.add("hel");
    trie.add("china");
    trie.add("ch");
    trie.add("ch");
    trie.add("heword");
    trie.add("hellw");

    cout << trie.query("hello") << endl;
    cout << trie.query("helloo") << endl;
    cout << trie.query("hel") << endl;
    cout << trie.query("china") << endl;
    cout << trie.query("ch") << endl;

    cout << "=====================" << endl;
    trie.preOrder();
    cout << "=====================" << endl;

    vector<string> words = trie.queryPrefix("ch");
    for (auto word : words)
    {
        cout << word << endl;
    }
    cout << endl;

    trie.remove("hellw");
    cout << "=====================" << endl;
    trie.preOrder();

    return 0;
}