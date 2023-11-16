#include <stdio.h>
#include <stdlib.h>

#define SIZE 13
int UFSets[SIZE]; // 集合元素数组

// 初始化并查集
void Initial(int s[])
{
    for (int i = 0; i != SIZE; ++i)
    {
        s[i] = -1;
    }
}

// Find “查”操作，找x所属集合（返回x所属根节点）
int Find(int s[], int x)
{
    while (s[x] >= 0) // 循环寻找x的根
        x = s[x];
    return x; // 根的s[]小于0
}

// Union “并”操作，将两个集合合并为一个
void Union(int s[], int root1, int root2)
{
    // 要求root1与root2是不同的集合
    if (root1 == root2)
        return;
    // 将root2来连接到另一根roo1下面
    s[root2] = root1;
}

int main()
{
    system("chcp 65001");

    return 0;
}