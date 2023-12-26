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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto pre = head;
        auto p = head;
        auto q = head; //保存要删节点的上一个节点
        //找到第k个节点
        for (int i = 0; i < n; ++i)
            p = p->next;
        //迭代节点
        while (p != nullptr)
        {
            p = p->next;
            q = pre;
            pre = pre->next;
        }
        //此时pre指向要删除节点
        if (q == pre) { // 如果要删除的是头节点
            head = head->next;
        }
        else {
            q->next = pre->next;
        }
        delete pre;
        return head;
    }
};

int main()
{


    system("pause");
    return 0;
}