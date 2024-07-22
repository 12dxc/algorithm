#include <iostream>
#include <string>
#include <memory>
using namespace std;

// BF(����ģʽƥ��)�㷨  ʱ�临�Ӷȣ�O(n)*O(m) =  O(n*m)   �ռ临�Ӷȣ� O(1)
int BF(string s, string t)
{
    int i = 0, j = 0; // �ֱ�ָ��������ģʽ����ĳһλ
    while (i < s.size() && j < t.size())
    {
        if (s[i] == t[j])
        {
            ++i, ++j;
        }
        else
        {
            i = i - j + 1; // ��λi��ָ��֮ǰ��ʼƥ���ַ�����һ���ַ�  O(m)
            j = 0;
        }
    }
    if (j == t.size()) // �ҵ��� ��jԽ���Ӵ�����
    {
        return i - j;
    }
    else
    {
        return -1;
    }
}
// KMP�㷨����Ӵ���next����
int *getNext(string str)
{
    int *next = new int[str.size()];
    int j = 0;  // j���������Ӵ�
    int k = -1; // k��ʾ����ǰ��׺�ĳ���
    next[j] = k;

    while (j < str.size() - 1)
    {
        if (-1 == k || str[k] == str[j])
        {
            j++, k++;

            if (str[j] == str[k])
            { // kmp�㷨���Ż�
                next[j] = next[k];
            }
            else
            {

                next[j] = k;
            }
        }
        else
        {
            k = next[k]; // ��kֵ���ݣ���������Ĺ���ǰ��׺
        }
    }
    return next;
}
// KMP�㷨  ʱ�临�Ӷȣ�O(n) + O(m) = O(n+m)  �ռ临�Ӷȣ�O(m)
int KMP(string s, string t)
{
    int i = 0, j = 0; // �ֱ�ָ��������ģʽ����ĳһλ

    // ����һ���Ӵ���Ӧ��next����
    int *next = getNext(t);
    unique_ptr<int> ptr(next); // �Զ�delete

    // j < t.size() �����⣡���� j = -1 11111111111  size_t  unsigned int
    int size1 = s.size(), size2 = t.size();
    while (i < size1 && j < size2)
    {
        if (-1 == j || s[i] == t[j])
        {
            ++i, ++j;
        }
        else
        {
            // KMP�ĺ����ǲ�����i��ֻ����jֵ
            j = next[j]; // �������ĸƥ��ʧ�ܣ�����j == -1
        }
    }
    if (j == t.size()) // �ҵ��� ��jԽ���Ӵ�����
    {
        return i - j;
    }
    else
    {
        return -1;
    }
}
int main()
{
    string s = "abcabdefabcabc"; //"ABCDCABDEFG";
    string t = "abcabc";         //"ABD";

    int pos = KMP(s, t);
    cout << pos << endl;

    return 0;
}