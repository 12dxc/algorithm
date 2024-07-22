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

int main()
{
    SqList L;     // 声明一个顺序表
    InitList(&L); // 初始化顺序表

    return 0;
}