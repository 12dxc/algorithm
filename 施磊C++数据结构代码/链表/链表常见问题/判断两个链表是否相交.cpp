#include <iostream>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        auto p = headA;
        auto q = headB;
        int cnt1 = 0, cnt2 = 0;  //用于分别统计两个链表的长度

        //遍历链表
        while (p != nullptr)
        {
            p = p->next;
            ++cnt1;
        }
        while (q != nullptr)
        {
            q = q->next;
            ++cnt2;
        }
        p = headA, q = headB;  //重置双指针

        //比较两链表长度
        if (cnt1 > cnt2)  //链表1更长
        {
            int k = cnt1 - cnt2;
            //链表1遍历至k节点
            for (int i = 0; i < k; ++i)
                p = p->next;
        }
        else     //链表2更长
        {
            int k = cnt2 - cnt1;
            //链表1遍历至k节点
            for (int i = 0; i < k; ++i)
                q = q->next;
        }
        //遍历两链表，求是否有交点
        while (p != nullptr)
        {
            if (p == q)
                return p;
            p = p->next;
            q = q->next;

        }
        return nullptr;
    }
};

int main()
{


    system("pause");
    return 0;
}