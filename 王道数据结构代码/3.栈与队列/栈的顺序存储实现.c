#include <stdio.h>
#include <stdbool.h>
#define MaxSize 10   // 静态数组最大长度
#define ElemType int // 栈的元素类型

typedef struct
{
    ElemType data[MaxSize];
    int top; // 用于栈顶指针
} Stack;
// 初始化栈
void InitStack(Stack *s)
{
    s->top = -1;
    for (int i = 0; i != MaxSize; ++i)
    {
        s->data[i] = 0;
    }
}
// 销毁栈
void DestroyStack(Stack *s)
{
    s->top = -1;
}
// 进栈
bool Push(Stack *s, ElemType x)
{
    if (s->top == MaxSize - 1) // 栈满
        return false;
    ++s->top;
    s->data[s->top] = x;
    return true;
}
// 出栈
bool Pop(Stack *s)
{
    if (s->top == -1) // 栈为空
        return false;
    s->data[s->top] = 0; // 栈顶元素先出栈
    s->top--;            // 指针再减1
    return true;
}
// 查看栈顶元素
ElemType GetTop(Stack s)
{
    if (s.top == -1) // 栈为空
        return -1;
    return s.data[s.top];
}

// 判断是否为空栈
bool StackEmpty(Stack s)
{
    if (s.top == -1) // 栈为空
        return true;
    else
        return false;
}

int main()
{
    Stack s;       // 创建栈
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

    if (StackEmpty(s))
        printf("栈为空！");

    return 0;
}