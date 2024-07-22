#include <iostream>
using namespace std;

// 桶的状态
enum State
{
    STATE_UNUSE, // 从未使用过的桶
    STATE_USING, // 正在使用的桶
    STATE_DEL,   // 元素被删除了的桶
};
// 桶的类型
struct Bucket
{
    Bucket(int key = 0, State state = STATE_UNUSE)
        : key_(key), state_(state) {}

    int key_;     // 存储的数据
    State state_; // 桶的当前状态
};
// 线性探测哈希类型
class HashTable
{
public: // 固有方法
    HashTable(int size = primes_[0], double loadFactor = 0.75)
        : useBucketNum_(0), loadFactor_(loadFactor), primeIdx_(0)
    {
        // 把用户传入的size调整到最近的比较大的素数上
        if (size != primes_[0])
        {
            for (; primeIdx_ < PRIME_SIZE; primeIdx_++)
            {
                if (primes_[primeIdx_] >= size)
                    break;
            }
            // 用户传入的size值过大，已经超过最后一个素数，调整到最后一个素数
            if (primeIdx_ == PRIME_SIZE)
                primeIdx_--;
        }

        tableSize_ = primes_[primeIdx_]; // 初始化哈希表表长
        table_ = new Bucket[tableSize_]; // 初始化哈希表
    }
    ~HashTable()
    {
        delete[] table_;
        table_ = nullptr;
    }

public: // 对外操作接口
    // 插入元素
    bool insert(int key)
    {
        // 考虑扩容  以占用桶个数除以桶总数
        double factor = useBucketNum_ * 1.0 / tableSize_;
        cout << "factor: " << factor << endl;
        if (factor > loadFactor_)
            expand(); // 哈希表开始扩容

        int idx = key % tableSize_; // 计算散列码
        int i = idx;
        do
        {
            if (table_[i].state_ != STATE_USING)
            {
                table_[i].state_ = STATE_USING;
                table_[i].key_ = key;
                useBucketNum_++;
                return true; // O(1)
            }
            i = (i + 1) % tableSize_;
        } while (i != idx); // O(n)

        return false;
    }
    // 删除元素
    bool erase(int key)
    {
        int idx = key % tableSize_;

        int i = idx;
        do
        {
            if (table_[i].state_ == STATE_USING && table_[i].key_ == key)
            {
                table_[i].state_ = STATE_DEL;
                useBucketNum_--;
            }
            i = (i + 1) % tableSize_;
        } while (table_[i].state_ != STATE_UNUSE && i != idx);

        return true;
    }
    // 查询
    bool find(int key)
    {
        int idx = key % tableSize_;

        int i = idx;
        do
        {
            if (table_[i].state_ == STATE_USING && table_[i].key_ == key)
            {
                return true;
            }
            i = (i + 1) % tableSize_;
        } while (table_[i].state_ != STATE_UNUSE && i != idx);

        return false;
    }

private: // 私有方法
    // 扩容操作
    void expand()
    {
        ++primeIdx_;
        if (primeIdx_ == PRIME_SIZE)
            throw "散列表太大，无法再扩展";

        Bucket *newTable = new Bucket[primes_[primeIdx_]];
        for (int i = 0; i < tableSize_; i++)
        {
            if (table_[i].state_ == STATE_USING) // 旧表有效的数据，重新哈希放到新表
            {
                int idx = table_[i].key_ % primes_[primeIdx_];

                int k = idx;
                do
                {
                    if (newTable[k].state_ != STATE_USING)
                    {
                        newTable[k].state_ = STATE_USING;
                        newTable[k].key_ = table_[i].key_;
                        break;
                    }
                    k = (k + 1) % primes_[primeIdx_];
                } while (k != idx);
            }
        }
        // 更新成员变量
        delete[] table_;
        table_ = newTable;
        tableSize_ = primes_[primeIdx_];
    }

private:                // 成员变量
    Bucket *table_;     // 指向动态开辟的哈希表
    int tableSize_;     // 哈希表当前的长度
    int useBucketNum_;  // 已经使用的桶的个数
    double loadFactor_; // 哈希表的装载因子

    static const int PRIME_SIZE = 10; // 素数的大小
    static int primes_[PRIME_SIZE];   // 素数表
    int primeIdx_;                    // 当前使用的素数下标
};

// 素数表  静态成员变量须在类外初始化
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