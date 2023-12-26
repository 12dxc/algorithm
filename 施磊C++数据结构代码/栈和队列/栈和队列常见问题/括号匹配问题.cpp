#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string str) {
        stack<char>sc;
        for (auto i : str)
        {
            if (i == '(' || i == '[' || i == '{')
            {   //遇到左括号入栈
                sc.push(i);
            }
            else
            {
                if (sc.empty())  //如果没有左括号入栈，即栈空，不执行右括号的匹配
                    return false;
                //遇到右括号，且能与栈顶匹配，弹出栈顶继续循环
                if ((i == ')' && sc.top() == '(')
                    || (i == ']' && sc.top() == '[')
                    || (i == '}' && sc.top() == '{'))
                    sc.pop();
                else
                    return false;
            }
        }
        return sc.empty();  //如果栈空表示所有括号都匹配，反之亦然
    }
};



int main()
{
    string str = "[({})]";
    Solution().isValid(str);

    system("pause");
    return 0;
}