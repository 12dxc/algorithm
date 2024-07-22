#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MaxSize 10   // 静态数组最大长度
#define ElemType int // 栈的元素类型

// 链栈结构
typedef struct StackNode
{
    ElemType data;
    struct StackNode *next;
} StackNode, *LinkStackPtr;
// 链表结构
typedef struct
{
    LinkStackPtr top;
    int count; // 链表长度
} LinkStack;

// 初始化一个空的单链表栈（带头结点）
bool InitStack(LinkStack *s)
{
    s->top = (LinkStackPtr)malloc(sizeof(StackNode)); // 分配一个头结点
    if (!s->top)
        return false; // 内存不足，分配失败
    s->top = NULL;    // 头结点next指针置空
    s->count = 0;     // 链长置0
    return true;
}
// 判断是否为空栈
bool StackEmpty(LinkStack s)
{
    if (s.count == 0) // 栈为空
        return true;
    else
        return false;
}
// 销毁栈
void ClearStack(LinkStack *s)
{
    LinkStackPtr p, q;
    p = s->top;
    while (p)
    {
        q = p;       // 保存当前头结点
        p = p->next; // 迭代头结点指针;
        free(q);     // 释放当前头结点
    }
    s->count = 0;
}
// 进栈
bool Push(LinkStack *s, ElemType e)
{
    LinkStackPtr newTop = (LinkStackPtr)malloc(sizeof(StackNode));
    newTop->data = e;      // 新结点赋值
    newTop->next = s->top; // 新结点的下个结点指向头结点
    s->top = newTop;       // 头结点指向（改为）新结点
    s->count++;            // 链长+1
    return true;
}
// 出栈
ElemType Pop(LinkStack *s)
{
    if (s->count == 0) // 栈为空
        return -1;
    int x = s->top->data;
    LinkStackPtr p = s->top; // 创建一个指针指向要销毁的结点,即头结点
    s->top = s->top->next;   // 指针下移一位
    free(p);                 // 销毁结点
    s->count--;              // 链长-1
    return x;
}
// 查看栈顶元素
ElemType GetTop(LinkStack s)
{
    if (s.top == 0) // 栈为空
        return -1;
    return s.top->data;
}

int main()
{
    LinkStack s;   // 创建栈
    InitStack(&s); // 初始化栈
    // 压栈，0~9填满栈
    for (int i = 0; i < MaxSize; i++)
    {
        Push(&s, i);
    }
    // 查看栈顶
    printf("%d\n", GetTop(s)); // 9
    // 出栈
    Pop(&s);
    printf("%d\n", GetTop(s)); // 8

    printf("链长: %d\n", s.count);

    if (StackEmpty(s))
        printf("栈为空！");

    system("pause");
    return 0;
}