#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool test(string str)
{
    stack<char> sta;
    for (int i = 0; i < str.length(); i++)
    {
        // 遍历字符串所有字符赋给字符变量c
        char c = str.at(i);
        // 遇到左括号入栈
        if (c == '{' || c == '[' || c == '(')
        {
            sta.push(c);
        }
        else
        {
            if (sta.empty())
                return false;
            // 记录栈顶元素
            char topChar = sta.top();
            sta.pop();
            // 如果遇到右括号,则与栈顶元素匹配,不是与之相对的括号，直接返回false
            if (c == ')' && topChar != '(' || c == ']' && topChar != '[' || c == '}' && topChar != '{')
            {
                return false;
            }
        }
    }

    // 栈空返回true
    return sta.empty();
}

int main()
{
    string str("{[()]}");
    cout << test(str);

    system("pause");
    return 0;
}