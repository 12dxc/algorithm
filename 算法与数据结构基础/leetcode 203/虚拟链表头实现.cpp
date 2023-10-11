struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution2
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        // 创建一个虚拟头结点
        ListNode *dummyHead = new ListNode(-1);
        dummyHead->next = head;

        // 创建一个头指针
        ListNode *pre = dummyHead;
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
        return dummyHead->next;
    }
};