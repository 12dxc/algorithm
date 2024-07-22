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
    ListNode* detectCycle(ListNode* head) {
        // 快慢指针初始化指向 head
        ListNode* fast = head, * slow = head;
        // 快指针走到末尾时停止或链表只有一个元素说明没有环
        while (fast != nullptr && fast->next != nullptr)
        {
            // 慢指针走一步，快指针走两步
            fast = fast->next->next;
            slow = slow->next;
            // 快慢指针相遇，说明含有环
            if (fast == slow) {
                fast = head;
                while (fast != slow)
                {
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast;
            }
        }
        return nullptr;
    }
};

int main()
{


    system("pause");
    return 0;
}