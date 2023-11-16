#include <iostream>
#include <vector>
using namespace std;

//顺序查找
int Search_Sep(vector<int> &v, int key)
{
    int i;
    //条件有二，一是越界（即遍历完）；二是找到给定值；两者有其一不满足则直接返回查找结果
    for (i = 0; i != v.size() && v[i] != key; ++i)
        ;
    //查找成功，则返回元素下标；查找失败，则返回-1
    return i == v.size() ? -1 : i;
}

int main()
{
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8};
    cout << Search_Sep(v, 4) << endl;
    return 0;
}