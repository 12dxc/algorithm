#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;

int calc(int left, int right, int sign)
{
    switch (sign)
    {
    case '+':
        return left + right;
    case '-':
        return left - right;
    case '*':
        return left * right;
    case '/':
        return left / right;
    }
    throw"";
}
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;  //设为int 只用于存储执行运算的数字
        for (auto i : tokens)
        {
            if (i.size() == 1 &&
                (i[0] == '+' || i[0] == '-'
                    || i[0] == '*' || i[0] == '/'))
            {   //遇到运算符开始运算
                int right = s.top();
                s.pop();
                int left = s.top();
                s.pop();
                s.push(calc(left, right, i[0]));
            }
            else
            {   //遇到数字，直接入数字栈
                s.push(stoi(i));
            }
        }
        return s.top();
    }
};

int main()
{
    vector<string> tokens{ "4","13","5","/","+" };
    Solution().evalRPN(tokens);

    system("pause");
    return 0;
}