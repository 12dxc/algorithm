#include <iostream>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    int kthToLast(ListNode* head, int k) {
        auto pre = head;
        auto p = head;
        //找到第k个节点
        for (int i = 0; i < k; i++)
            p = p->next;
        //迭代节点
        while (p != nullptr)
        {
            p = p->next;
            pre = pre->next;
        }
        return pre->val;
    }
};

int main()
{


    system("pause");
    return 0;
}