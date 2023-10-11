#include <iostream>
using namespace std;

// 链表类
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}

    // 链表节点的构造函数
    // 使用arr为参数，创建一个链表，当前的ListNode为链表头结点
    ListNode(int arr[], int len)
    {
        if (arr == NULL || len == 0)
        {
            throw invalid_argument("数组不能为空");
        }
        this->val = arr[0];
        ListNode *cur = this;
        for (int i = 0; i < len; i++)
        {
            cur->next = new ListNode(arr[i]);
            cur = cur->next;
        }
    }

    // 以当前节点为头结点的链表信息字符串
    friend ostream &operator<<(ostream &os, ListNode &list)
    {
        ListNode *cur = &list;
        while (cur)
        {
            os << cur->val << "->";
            cur = cur->next;
        }
        os << "NULL";

        return os;
    }
};

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        // 1、如果head结点为空，直接返回空
        if (head == nullptr)
        {
            return nullptr;
        }
        // 2、递归调用removeElements去处理head->next开始的子链表,删除值为val的节点
        ListNode *res = removeElements(head->next, val);
        // 3、如果head节点的值等于val,说明需要删除头节点,所以直接返回递归函数的结果res,也就是去掉头节点后的子链表
        if (head->val == val)
        {
            return res;
        }
        // 如果head节点的值不等于val,说明头节点保留,那么就把头节点head与递归函数的结果res连接起来,然后返回这个保留了头节点的链表
        else
        {
            head->next = res;
            return head;
        }
    }
};

int main()
{

    int arr[] = {1, 2, 6, 3, 4, 5, 6};
    int len = sizeof(arr) / sizeof(arr[0]);
    ListNode *head = new ListNode(arr, len);
    cout << (*head) << endl;

    // 测试
    ListNode *ret = Solution().removeElements(head, 6);
    cout << (*ret) << endl;
}