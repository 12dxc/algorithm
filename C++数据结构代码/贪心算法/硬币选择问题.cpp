#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*1,3,5�ֵ�Ӳ�ң����ڸ���һ����ֵc��11��������ټ�ֵc��Ҫ�����Ӳ�ҵ�����������*/
int main()
{
    /*ʹ��̰���㷨��ÿ�ζ�ѡ�����Ž⣬�Դ˵õ�ȫ���Ž⡣
     *��ÿ�ζ�ѡ5��ֱ��������5��ѡ��С��ֵ��Ӳ��*/
    vector<int> v = {1, 3, 5}; // Ӳ����ֵ
    int c = 11;
    sort(v.begin(), v.end(), [](int a, int b) -> bool
         { return a > b; }); // �������У������ֵ��ǰ��

    int idx = 0; // 5 3 1  ��¼����ʹ�õ���ֵ
    int cnt = 0; // ��¼Ӳ�Ҹ���
    while (c > 0)
    {
        if (c >= v[idx])
        {
            c -= v[idx]; // ��ȥ������ֵ
            cnt++;       // ����Ӳ����
        }
        else
        {
            idx++; // ���Ӳ����ֵ����ʣ����򻻸�С��Ӳ��
        }
    }

    cout << "�һ�11������Ҫ" << cnt << "��Ӳ��" << endl;

    return 0;
}