#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 定义单链表结点类型
typedef struct LNode
{
    int data;           // 每个节点存放一个数据元素
    struct LNode *next; // 指针指向下一节点
} LNode, *LinkList;

// 初始化一个空的单链表（带头结点）
bool InitList(LinkList *L)
{
    *L = (LNode *)malloc(sizeof(LNode)); // 分配一个头结点
    if (*L == NULL)
        return false;  // 内存不足，分配失败
    (*L)->next = NULL; // 头节点之后置空
    return true;
}

// 判断链表是否为空
bool Empty(LinkList L)
{
    if (L->next == NULL)
        return true;
    else
        return false;
}

// 单链表插入，改变前一个结点指针和要插入结点的指针的指向即可
bool ListInsert(LinkList L, int i, int e)
{
    if (i < 1)
        return false;
    LNode *p;                      // 指针p指向当前扫描的结点
    int j = 0;                     // 当前p指向的是第几个结点
    p = L;                         // L指向头结点，头结点是第0个结点（不存数据）
    while (p != NULL && j < i - 1) // 循环找到第i-1个结点，即插入位置前一个结点
    {
        p = p->next;
        ++j;
    }
    if (p == NULL) // i值不合法
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;       // 新分配的结点，其值等于所传值
    s->next = p->next; // 其指针的下一个结点指向i-1个结点的下一个结点
    p->next = s;       // 将结点s插入到p之后，即改变i-1结点的指向
    return true;       // 插入成功
}

bool ListDelete(LinkList L, int i)
{
    if (i < 1)
        return false;
    LNode *p;
    int j = 0;
    p = L;
    // 寻得要删除元素的前一个
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        ++j;
    }
    if (p == NULL || p->next == NULL) // i值不合法或者删除位置为空
        return false;
    // q赋值为p的下一个元素，即要删除元素
    LNode *q = p->next;
    // p的下一个元素指向，要删除元素的下一个
    p->next = q->next;
    free(q);
    return true;
}

int main()
{
    LinkList L; // 声明一个指向单链表的指针
    InitList(&L);
    ListInsert(L, 1, 10);
    ListInsert(L, 2, 20);
    ListInsert(L, 3, 30);

    ListDelete(L, 1);
    for (LNode *p = L->next; p != NULL; p = p->next)
    {
        printf("%d ", p->data);
    }

    return 0;
}