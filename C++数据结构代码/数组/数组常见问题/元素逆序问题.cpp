#include <iostream>
#include <memory>
#include <algorithm>
#include <cstring>
using namespace std;

// 逆序字符串
void Reverse(char arr[], int size)
{
    char *p = arr;            // 指向头元素的指针
    char *q = arr + size - 1; // 指向尾元素的指针
    while (p < q)
    {
        char ch = *p;
        *p = *q;
        *q = ch;
        ++p, --q;
    }
}

int main()
{
    char arr[] = "hello world";
    Reverse(arr, strlen(arr));
    cout << arr << endl;

    return 0;
}
