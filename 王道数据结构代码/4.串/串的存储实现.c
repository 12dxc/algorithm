#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 255 // 字符串最大长度

// 串的顺序存储
typedef struct
{
    char ch[MAXLEN]; // 每个分量存储一个字符
    int length;      // 串的实际长度
} SString;

// 串的链式存储
// typedef struct StringNode
// {
//     char ch; // 每个结点存1字符；
//     struct StringNode *next;
// } StringNode, *String;

// 赋值操作  把串T赋值为chars
void StrAssign(SString *T, char *chars)
{
    int len = strlen(chars); // 要赋值的串的长度
    if (len > MAXLEN)        // 避免赋值的串超出字符串的总容量
        return -1;
    for (int i = 0; i != len; ++i)
    {
        T->ch[i] == *(chars + i);
    }
    T->length = len;
}
// 复制操作  把串S复制得到串T
void StrCopy(SString *T, SString S)
{
    for (int i = 0; i != T->length; ++i)
    {
        T->ch[i] = S.ch[i];
    }
    S.length = T->length;
}
// 判空操作
bool StrEmpty(SString S)
{
    return S.length == 0 ? true : false;
}
// 求串长
int StrLength(SString S)
{
    return S.length;
}
// 清空操作
void ClearString(SString *S)
{
    for (int i = 0; i != S->length; ++i)
    {
        S->ch[i] = '\0'; // 字符全变为空
    }
}
// 销毁串
void DestroyString(SString *S)
{
    S->length = 0; // 令串长为0
}
// 串联接
bool Concat(SString *T, SString S1, SString S2)
{
    int i;
    if (S1.length + S2.length > MAXLEN)
    { // 未截断
        for (int i = 0; i != S1.length; ++i)
            T->ch[i] = S1.ch[i];
        for (int i = 0; i != S2.length; ++i)
        {
            T->ch[i + S1.length] = S2.ch[i];
        }
        T->length = S1.length + S2.length;
        return true;
    }
    else
    { /*  截断S2 */
        for (i = 0; i != S1.length; i++)
            T->ch[i] = S1.ch[i];
        for (i = 0; i != MAXLEN - S1.length; i++)
            T->ch[S1.length + i] = S2.ch[i];
        T->length = MAXLEN;
        return false;
    }
}
// 求子串  用Sub返回串S的第Pos个字符其长度为len的子串
SString SubString(SString S, int pos, int len)
{
    // 子串越界访问
    if (pos + len - 1 > S.length)
        return;
    SString Sub; // 创建子串返回值
    for (int i = pos; i < pos + len; ++i)
        Sub.ch[i - pos + 1] = S.ch[i];
    Sub.length = len;
    return Sub;
}
// 比较操作
bool StrCompare(SString S, SString T)
{
    for (int i = 1; i <= S.length && i <= T.length; ++i)
    {
        if (S.ch[i] != T.ch[i])
            return S.ch[i] - T.ch[i]; // 若S>T，则返回值>0;若S=T，则返回值=0;若S<T,则返回值<0;
    }
    // 扫描所有字符都相等，则长度长的串更大
    return S.length - T.length;
}
// 定位操作
int Index(SString S, SString T)
{
    int i = 1, n = StrLength(S), m = StrLength(T);
    SString sub; // 用于暂存子串
    while (i <= n - m + 1)
    {
        sub = SubString(S, i, m);
        if (StrCompare(sub, T) != 0)
            ++i;
        else
            return i; // 返回子串在主串中
    }
}

int main()
{
    system("chcp 65001");

    return 0;
}