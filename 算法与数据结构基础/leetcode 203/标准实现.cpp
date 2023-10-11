

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
    ListNode *removeElements(ListNode *head, int val)
    {
        // 从开始部分就是要删除的元素
        while (head != nullptr && head->val == val)
        {
            // 将头结点赋值给要删除的节点
            ListNode *delNode = head;
            // 头结点指向下一个结点
            head = head->next;
            delete delNode;
        }
        // 全部都是要删除的元素
        if (head == nullptr)
            return nullptr;

        // 要删除的元素在中间
        // 创建一个头指针
        ListNode *pre = head;
        // 遍历整个链表
        while (pre->next != nullptr)
        {
            // 对比链表中每个元素
            if (pre->next->val == val)
            {
                // 创建一个临时结点指向头结点的下一个结点
                ListNode *delNode = pre->next;
                // 头结点指向下下一个结点
                pre->next = delNode->next;
                // 释放临时结点
                delete delNode;
            }
            // 如果不是要找的元素，使链表结点指向下一个元素继续查找
            else
            {
                pre = pre->next;
            }
        }
        return head;
    }
};