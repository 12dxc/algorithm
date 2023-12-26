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
    ListNode* rotateRight(ListNode* head, int k) {

        if (head == nullptr || k == 0)
            return head;

        auto p = head;   //指向k+1节点
        auto q = head;   //指向末尾节点
        int cnt = 0;//计算节点总个数
        for (ListNode* k = head; k != nullptr; k = k->next)
            ++cnt;
        k = k % cnt;
        for (int i = 0; i < k; ++i)
            p = p->next;
        while (p->next != nullptr)
        {
            p = p->next;
            q = q->next;
        }

        //此时p,q都指向了需要的位置，开始连接链表
        p->next = head;   //将头节点挂在末尾节点
        head = q->next;   //重置头节点，让其指向k
        q->next = nullptr;      //k+1成为新末尾节点，next指针置空

        return head;
    }
};

int main()
{


    system("pause");
    return 0;
}