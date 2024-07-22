#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 定义单链表结点类型
typedef struct LNode
{
    int data;    // 每个节点存放一个数据元素
    LNode *next; // 指针指向下一节点
} LNode, *LinkList;

// 初始化一个空的单链表（带头结点）
bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode)); // 分配一个头结点
    if (L == NULL)
        return false; // 内存不足，分配失败
    L->next = NULL;
    return true;
}

// 判断链表是否为空
bool Empty(LinkList L)
{
    if (L == NULL)
        return true;
    else
        return false;
}

int main()
{
    LinkList L; // 声明一个指向单链表的指针
    InitList(L);

    return 0;
}