#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define ElemType int // 队列的元素类型

// 链式队列结点
typedef struct LinkNode
{
    ElemType data; // 用静态数组存放队列元素
    struct LinkNode *next;
} LinkNode;
// 链式队列
typedef struct
{
    LinkNode *front, *end; // 队列的队头指针和队尾指针（front指向空头结点）
    int len;               // 队列长度
} LinkQueue;

// 初始化队列（带头结点）
void InitQueue(LinkQueue *Q)
{
    // 初始化front、end都指向头结点
    Q->front = Q->end = (LinkNode *)malloc(sizeof(LinkNode));
    Q->front->next = NULL;
    Q->len = 0;
}
// 初始化队列（不带头结点）
// bool InitQueue(LinkQueue *Q)
// {
//     // 初始化front、end都指向NULL
//     Q->front = NULL;
//     Q->end = NULL;
// }

// 判断队列是否为空
bool IsEmpty(LinkQueue Q)
{
    // 队头和队尾指向同一个元素说明队空
    if (Q.front == Q.end)
        return true;
    else
        return false;
}
// 入队
void EnQueue(LinkQueue *Q, ElemType x)
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkQueue));
    s->data = x;
    s->next = NULL;   // 新加入的结点会接在尾部，所以next指针要指向空
    Q->end->next = s; // 新结点插入到end之后
    Q->end = s;       // 修改表尾指针
    Q->len++;
}
// 出队
ElemType DeQueue(LinkQueue *Q)
{
    if (Q->front == Q->end)
        return -1;                // 空队
    LinkNode *p = Q->front->next; // 创建指针p保存要删除的结点，即空头结点的下一个结点
    ElemType x = p->data;         // 用变量x保存队头元素的值，用于返回
    Q->front->next = p->next;     // 修改头结点的next指针，即指针下移一位

    if (Q->end == p)       // 此次是最后一个结点出队
        Q->end = Q->front; // 修改end指针

    free(p); // 释放结点空间
    Q->len--;
    return x;
}
// 获取队头元素，并返回
ElemType GetHead(LinkQueue Q)
{
    if (Q.front == Q.end)
        return -1;
    ElemType x = Q.front->next->data; // front指向的空头结点，所以队头元素为下一个结点的
    return x;
}
// 获取队长
int QueueLength(LinkQueue Q)
{
    return Q.len;
}

int main()
{
    LinkQueue q;
    InitQueue(&q);
    // 为队列添加0~9的元素
    for (int i = 9; i != -1; --i)
    {
        EnQueue(&q, i);
    }
    // 查看队头
    printf("入队后的队列: %d\n", GetHead(q));
    // 出队
    DeQueue(&q);
    printf("出队后的队列: %d\n", GetHead(q));

    if (IsEmpty(q))
        printf("队列为空");

    printf("现在队列长度: %d\n", QueueLength(q));

    system("pause");
    return 0;
}