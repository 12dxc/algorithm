#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    // 反转链表
    ListNode *reverseList(ListNode *head)
    {
        // 设置pre指针指向null,后面作为反转链表的头指针
        ListNode *pre = nullptr;

        // 设置cur指针指向原始链表的头指针head
        ListNode *cur = head;

        while (cur != nullptr)
        {
            // 存储cur的下一个节点
            ListNode *next = cur->next;
            // 修改cur的next指针指向pre,实现链表反转
            cur->next = pre;
            // pre向后移动
            pre = cur;
            // cur向后移动
            cur = next;
        }

        // 返回反转后的链表头指针pre
        return pre;
    }
};