#include <iostream>
#include <memory>
#include <vector>
using namespace std;

// 移除元素问题
int removeElement(vector<int> &nums, int val)
{
    // 双指针，分别指向头尾元素
    int p = 0, q = nums.size() - 1;
    while (p <= q)
    {
        // q->也可能等于val，故先找不等于val的元素
        if (nums[q] == val)
        {
            --q;
            continue;
        }
        // p->找到等于val的元素
        if (nums[p] == val)
        {
            // 用不等于val的值赋值给p
            nums[p] = nums[q];
            --q;
        }
        else // p->找到不等于val的元素，继续迭代头指针
        {
            ++p;
        }
    }
    return p - 0;
}

int main()
{
    vector<int> v{1, 2, 2, 4, 5, 2, 7, 2, 9};
    cout << removeElement(v, 2);

    return 0;
}
