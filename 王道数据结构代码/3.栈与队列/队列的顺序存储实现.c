#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MaxSize 10   // 队列元素的最大个数
#define ElemType int // 队列的元素类型

// 顺序存储实现队列的结构
typedef struct SqQeque
{
    ElemType data[MaxSize]; // 用静态数组存放队列元素
    int front, end;         // 队头指针和队尾指针(其中队尾指针指向的是队尾元素的下一个位置)
} SqQeque;

// 初始化队列
bool InitQueue(SqQeque *Q)
{
    // 初始化时队头、队尾指针指向0
    Q->front = 0;
    Q->end = 0;
}
// 判断队列是否为空
bool QueueEmpty(SqQeque Q)
{
    // 队头和队尾指向同一个元素说明队空
    if (Q.end = Q.front)
        return true;
    else
        return false;
}
// 入队
bool EnQueue(SqQeque *Q, ElemType x)
{
    // 队尾的下一个指针是队头说明队尾已满
    if ((Q->end + 1) % MaxSize == Q->front)
        return false;
    Q->data[Q->end] = x;              // 将x插入队尾
    Q->end += (Q->end + 1) % MaxSize; // 队尾指针后移
    return true;
}
// 出队
ElemType DeQueue(SqQeque *Q)
{
    if ((Q->end + 1) % MaxSize == Q->front)
        return -1;
    ElemType x = Q->data[Q->front];
    Q->front = (Q->front + 1) % MaxSize;
    return x;
}
// 获取队头元素，并返回
ElemType GetHead(SqQeque Q)
{
    if (Q.end == Q.front)
        return -1;
    ElemType x = Q.data[Q.front];
    return x;
}

int main()
{
    SqQeque q;
    InitQueue(&q);
    // 为队列添加0~9的元素
    for (int i = MaxSize; i != 0; --i)
    {
        EnQueue(&q, i);
    }
    // 查看队头
    printf("入队后的队列: %d\n", GetHead(q));
    // 出队
    DeQueue(&q);
    printf("出队后的队列: %d\n", GetHead(q));

    if (QueueEmpty(q))
        printf("队列为空");

    system("pause");
    return 0;
}