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
        // base case,头节点或下一个节点为空时直接返回
        if (head == nullptr || head->next == nullptr)
            return head;

        // 递归反转以head->next为头节点的子链表
        // 得到反转后的子链表,命名为rev
        ListNode *rev = reverseList(head->next);

        // 将原head节点接到rev链表尾部
        // head->next为原tail节点,将其next指向head
        head->next->next = head;

        // 将head节点的next指针置空,防止循环
        head->next = nullptr;
        
        // 返回反转后的子链表
        return rev;
    }
};