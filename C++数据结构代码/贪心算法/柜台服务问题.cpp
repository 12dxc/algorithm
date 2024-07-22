#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
m����̨�ṩ����ÿ����̨��һ���û��ṩ�����ʱ����t(�������ʾÿһ����̨�ṩ�����ʱ��)��
����ô���У�ʹ�ù�̨�������û��ṩ�����ʱ�����٣�
*/

// �����̨��Ϣ����
struct Counter
{
    bool operator<(const Counter &counter)
    {
        return time < counter.time;
    }
    int id;   // ��̨��
    int time; // ��̨�����ѵ�ʱ��
};
int main()
{
    int arr[] = {3, 2, 4};                      // ÿһ����̨�ṩ�����ʱ��
    const int m = sizeof(arr) / sizeof(arr[0]); // ��̨������
    int n = 15;                                 // ����ҵ�������

    // �����̨��Ϣ���飬��ʼ����̨id��time
    Counter cons[m];
    for (int i = 0; i < m; ++i)
    {
        cons[i].id = i;
        cons[i].time = arr[i];
    }

    // ���չ�̨�ṩ��ʱ�������������
    sort(cons, cons + m);

    int minTime = 0; // ��¼�������û��ṩ���������ʱ��
    int x[m] = {0};  // ��¼ÿһ����̨���ŵ��û�����

    for (int i = 0; i < n; ++i)
    {
        // �ȼ����i�û�����0�Ź�̨��ʱ��
        int time = cons[0].time * (x[0] + 1);
        // �ڱ��������Ĺ�̨�����Ƿ���Եõ����ٵĻ���ʱ��
        int j = 1;
        for (; j < m; ++j)
        {
            int t = cons[j].time * (x[j] + 1);
            if (t <= time) // ����������̨����ʱ��������죬ֱ�ӷ���j��̨
            {
                x[j]++;
                // �������һ���ˣ����廨�ѵ�ʱ���п��ܱ�ø����ˣ�����minTime
                if (t > minTime)
                {
                    minTime = t;
                }
                break;
            }
        }
        // ���ջ��Ƿ���0�Ź�̨���ѵ�ʱ�����
        if (j == m)
        {
            x[0]++;
            // �������һ���ˣ����廨�ѵ�ʱ���п��ܱ�ø����ˣ�����minTime
            minTime = cons[0].time * x[0];
        }
    }

    cout << minTime << endl;
    for (int i = 0; i < m; ++i)
        cout << arr[cons[i].id] << " : " << x[i] << endl;

    return 0;
}