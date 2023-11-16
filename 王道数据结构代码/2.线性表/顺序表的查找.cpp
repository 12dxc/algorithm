#include <cstdio>
#include <cstdlib>
#include <iostream>
#define MaxSize 10 // 定义最大长度

// 定义一个静态线性表
typedef struct
{
    int data[MaxSize]; // 用静态的“数组”存放数据元素
    int length;        // 顺序表的当前长度
} SqList;              // 顺序表的类型定义

// 基本操作——初始化一个顺序表
void InitList(SqList *L)
{
    for (int i = 0; i != MaxSize; ++i)
    {
        L->data[i] = 0;
    }
    L->length = 0;
}

// 线性表插入操作
bool ListInsert(SqList *L, int i, int e)
{
    if (i < 1 || i > L->length + 1) // 判断i的范围是否有效
        return false;
    if (L->length >= MaxSize) // 当前存储空间已满，禁止存入
        return false;

    for (int j = L->length; j >= i; j--) // 将第i个元素及之后的元素后移
        L->data[j] = L->data[j - 1];
    L->data[i - 1] = e; // 在位置index放入elem
    L->length++;        // 长度加1
    return true;
}

// 线性表删除操作
bool ListDelete(SqList *L, int i, int &e)
{
    if (i < 1 || i > L->length) // 判断i的范围是否有效
        return false;
    e = L->data[i - 1];                 // 将被删除的元素赋值给e
    for (int j = i; i < L->length; j++) // 将第i个位置后的元素前移
        L->data[j - 1] = L->data[j];
    L->length--; // 线性表长度减1
    return true;
}

// 按位查找
int GetElem(SqList L, int i)
{
    return L.data[i];
}
// 按值查找
int LocateElem(SqList L, int e)
{
    for (int i = 0; i < L.length; ++i)
    {
        if (L.data[i] == e)
            return i;
        else
            return -1;
    }
}

int main()
{
    SqList L;     // 声明一个顺序表
    InitList(&L); // 初始化顺序表
    int e = -1;

    ListInsert(&L, 1, 100);
    ListDelete(&L, 1, e);
    for (int i = 0; i != L.length; ++i)
    {
        printf("%d ", L.data[i]);
    }
    std::cout << GetElem(L, 0) << " " << LocateElem(L, 100) << std::endl;

    return 0;
}