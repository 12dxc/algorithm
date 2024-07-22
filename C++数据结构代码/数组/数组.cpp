#include <iostream>
#include <memory>
using namespace std;

// 数组实现
template <typename T>
class Array
{
public:
    Array(int size = 10) : mCur(0), mCap(size)
    {
        mpArr = new T[mCap]();
    }
    ~Array()
    {
        delete[] mpArr;
        mpArr = nullptr;
    }

public:
    // 返回数组容量
    int capacity() const { return mCap; }
    // 返回数组大小
    int size() const { return mCur; }
    // 末尾增加元素  O(1)
    void push_back(int val)
    {
        if (mCur == mCap)     // 数组空间不够
            expand(2 * mCap); // 扩容  O(n)

        mpArr[mCur] = val;
        ++mCur;
    }
    // 末尾删除元素  O(1)
    void pop_back()
    {
        if (mCur == 0)
            return;
        --mCur;
    }
    // 按位置增加元素  O(n)
    void insert(int pos, int val)
    {
        // 数组下标是否合理
        if (pos < 0 || pos > mCur)
            return;
        // 检测空间是否足够
        if (mCur == mCap)
            expand(2 * mCap);

        // 移动元素
        for (int i = mCur - 1; i >= pos; --i)
            mpArr[i + 1] = mpArr[i];

        mpArr[pos] = val;
        ++mCur;
    }
    // 按元素删除  O(n)
    void erase(int pos)
    {
        if (pos < 0 || pos >= mCur)
            return;
        // 移动元素
        for (int i = pos + 1; i != mCur; ++i)
            mpArr[i - 1] = mpArr[i];
        --mCur; // 更新数据
    }
    // 元素查询  O(n)
    int find(int val) const
    {
        for (int i = 0; i != mCur; ++i)
        {
            if (mpArr[i] == val)
                return i;
        }
        return -1;
    }
    // 打印数据
    void show() const
    {
        for (int i = 0; i != mCur; ++i)
        {
            cout << mpArr[i] << " ";
        }
        cout << endl;
    }

private:
    T *mpArr; // 指向可扩容的数组内存
    int mCap; // 数组的容量
    int mCur; // 数组的有效个数
    // 数组动态扩容
    void expand(int size)
    {
        int *p = new int[size];
        for (int i = 0; i != mCur; ++i)
            p[i] = mpArr[i];
        delete[] mpArr;
        // 更新数据
        mpArr = p;
        mCap = size;
    }
};

int main()
{
    system("chcp 65001");

    Array<int> a;
    for (int i = 0; i != 10; ++i)
        a.push_back(i);
    a.show();
    a.pop_back();
    a.show();

    a.insert(9, 100);
    a.show();

    int pos = a.find(100);
    if (pos == -1)
        cout << "元素不存在" << endl;
    else
        cout << "要查询的元素下标为：" << pos << endl;

    cout << "元素的容量为: " << a.capacity() << "\n元素的大小为: " << a.size() << endl;

    return 0;
}
