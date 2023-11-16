#include <stdio.h>
#include <stdlib.h>

#define InitSize 10 // 默认的最大长度

// 定义一个动态线性表
typedef struct
{
    int *data;   // 指示动态分配数组的指针
    int MaxSize; // 顺序表的最大容量
    int length;  // 顺序表的当前长度
} SeqList;       // 顺序表的类型定义（动态分配方式）

// 基本操作——初始化一个顺序表
void InitList(SeqList *L)
{
    // 用malloc函数申请一片连续的存储空间
    L->data = (int *)malloc(sizeof(int) * InitSize);
    L->length = 0;
    L->MaxSize = InitSize;
}

// 增加动态数组长度
void IncreaseSize(SeqList *L, int len)
{
    int *p = L->data;                                          // 临时指针指向原有线性表
    L->data = (int *)malloc((L->MaxSize + len) * sizeof(int)); // 重新分配更大空间
    for (int i = 0; i != L->length; ++i)
    {
        L->data[i] = p[i]; // 将数据复制到新区域
    }
    L->MaxSize = L->MaxSize + len; // 顺序表最大长度增加 len
    free(p);                       // 释放原来内存空间
}

int main()
{
    SeqList L;    // 声明一个顺序表
    InitList(&L); // 初始化顺序表

    IncreaseSize(&L, 5);

    return 0;
}