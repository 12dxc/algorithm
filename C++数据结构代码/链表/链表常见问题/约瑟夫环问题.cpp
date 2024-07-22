#include<iostream>
using namespace std;

struct Node  //节点类型
{
    Node(int data = 0) :m_data(data), next(nullptr) {}
    int m_data;
    Node* next;
};
//约瑟夫环问题 ->不带头节点的单向循环链表应用
void Joseph(Node* head, int k, int m)
{
    Node* p = head;
    Node* q = head;
    //q指向最后一个
    while (q->next != head)
    {
        q = q->next;
    }

    //从第k个人开始报数，找到k
    for (int i = 1; i < k; i++)
    {
        q = p;
        p = p->next;
    }

    //p -> 第k个人
    for (;;)
    {
        for (int i = 1; i < m; i++)  //循环找到m，即要弹出的元素
        {
            q = p;
            p = p->next;
        }
        
        cout << p->m_data << " ";  //打印弹出的元素

        if (p == q)  //当节点相同，说明已无元素，退出循环
        {
            delete p;
            break;
        }
        //删除p指向的节点
        q->next = p->next;
        delete p;
        p = q->next;
    }
}

int main()
{
    //初始化链表
    Node* head = new Node(1); Node* h2 = new Node(2);
    Node* h3 = new Node(3); Node* h4 = new Node(4);
    head->next = h2; h2->next = h3; h3->next = h4; h4->next = head;

    Joseph(head, 1, 2);
    cout << endl;

    system("pause");
    return 0;
}