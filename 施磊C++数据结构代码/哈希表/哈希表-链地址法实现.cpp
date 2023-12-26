#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

// 链式哈希表
class HashTable
{
public:
    HashTable(int size = primes_[0], double loadFactor = 0.75)
        : useBucketNum_(0), loadFactor_(loadFactor), primeIdx_(0)
    {
        if (size != primes_[0])
        {
            for (; primeIdx_ < PRIME_SIZE; primeIdx_++)
            {
                if (primes_[primeIdx_] >= size)
                    break;
            }
            if (primeIdx_ == PRIME_SIZE)
            {
                primeIdx_--;
            }
        }
        table_.resize(primes_[primeIdx_]); // 构造哈希表
    }

public:
    // 增加元素  不能重复插入key
    void insert(int key)
    {
        // 判断扩容
        double factor = useBucketNum_ * 1.0 / table_.size();
        cout << "factor: " << factor << endl;
        if (factor > loadFactor_)
            expand();

        int idx = key % table_.size(); // 计算桶的下标，即散列码  O(1)
        if (table_[idx].empty())
        {
            useBucketNum_++;
            table_[idx].emplace_front(key);
        }
        else // 去重
        {
            // 使用全局::find泛型算法,而不是调用自己的成员方法find
            auto it = ::find(table_[idx].begin(), table_[idx].end(), key); // O(n)
            if (it == table_[idx].end())
            {
                // key不存在
                table_[idx].emplace_front(key);
            }
        }
    }
    // 删除元素
    void erase(int key)
    {
        int idx = key % table_.size(); // O(1)
        // 如果链表节点过长：如果散列函数比较集中，散列函数有问题。
        //               如果散列结果比较离散，链表长度一般不会过长，因为有装载因子
        auto it = ::find(table_[idx].begin(), table_[idx].end(), key); // O(n)
        if (it != table_[idx].end())
        {
            table_[idx].erase(it);
            if (table_.empty()) // 桶成空，更新成员变量
                useBucketNum_--;
        }
    }
    // 搜索元素
    bool find(int key)
    {
        int idx = key % table_.size();
        auto it = ::find(table_[idx].begin(), table_[idx].end(), key);
        return it != table_[idx].end();
    }

private:
    // 扩容
    void expand()
    {
        if (primeIdx_ + 1 == PRIME_SIZE) // 已到素数表末尾
            throw "散列表太大，无法再扩展";

        primeIdx_++;

        vector<list<int>> oldTable;
        table_.swap(oldTable);             // 将原哈希表内容放至oldTable中
        table_.resize(primes_[primeIdx_]); // 更改原哈希表大小

        // 遍历老哈希表，重新哈希key插入新表
        for (auto list : oldTable)
        {
            for (auto key : list)
            {
                int idx = key % table_.size(); // 计算新散列值
                if (table_[idx].empty())       // 桶为空，记录个数
                    useBucketNum_++;

                table_[idx].emplace_front(key); // 重新哈希插入key
            }
        }
    }

private:
    vector<list<int>> table_; // 哈希表的数据结构
    int useBucketNum_;        // 记录桶的个数
    double loadFactor_;       // 记录哈希表装载因子

    static const int PRIME_SIZE = 10; // 素数的大小
    static int primes_[PRIME_SIZE];   // 素数表
    int primeIdx_;                    // 当前使用的素数下标
};

// 素数表
int HashTable::primes_[PRIME_SIZE] = {3, 7, 23, 47, 97, 251, 443, 911, 1471, 42773};

int main()
{
    HashTable htable;
    htable.insert(21);
    htable.insert(32);
    htable.insert(14);
    htable.insert(15);
    htable.insert(22);

    cout << htable.find(22) << endl;
    htable.erase(22);
    cout << htable.find(22) << endl;

    return 0;
}