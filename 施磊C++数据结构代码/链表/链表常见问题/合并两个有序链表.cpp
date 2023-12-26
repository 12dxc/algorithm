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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1), * p = dummy;   //创建一个虚拟头节点作为合并好的新链表  p则指向新链表最后一个节点，用于尾插
        ListNode* p1 = l1, * p2 = l2;
        while (p1 != nullptr && p2 != nullptr)
        {
            if (p1->val < p2->val)  //如果l1节点小,则挂到p后
            {
                p->next = p1;
                p1 = p1->next;
            }
            else    //如果l2节点小,则挂到p后
            {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;  //p指针不断前进
        }
        if (p1 != nullptr)
            p->next = p1;
        if (p2 != nullptr)
            p->next = p2;
        return dummy->next;
    }
};

int main()
{


    system("pause");
    return 0;
}