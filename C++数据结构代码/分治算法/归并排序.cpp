#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

// �ϲ���������
void Merge(vector<int> &vec, int low, int high, int mid)
{
    // ���帨�����飬�洢�ϲ��õĻ�������
    vector<int> temp;

    int i = low;
    int j = mid + 1;

    while (i <= mid && j <= high)
    {
        if (vec[i] > vec[j]) // �����и������Ƚ�������Ԫ�ؼ������飬��ָ������һԪ��
        {
            temp.push_back(vec[j++]);
        }
        else // �����и������Ƚ�������Ԫ�ؼ������飬��ָ������һԪ��
        {
            temp.push_back(vec[i++]);
        }
    }
    // �ж��ĸ�����δ���꣬��������������ĩβ
    while (i <= mid)
    {
        temp.push_back(vec[i++]);
    }
    while (j <= high)
    {
        temp.push_back(vec[j++]);
    }

    // ��󽫺ϲ��õ����У�����ԭ����
    for (int k = low; k <= high; ++k)
    {
        vec[k] = temp[k - low];
    }
}
// �鲢����
void MergeSort(vector<int> &vec, int l, int r)
{
    if (l >= r)
        return;
    // �鲢����
    int mid = (l + r) / 2;
    MergeSort(vec, l, mid);
    MergeSort(vec, mid + 1, r);

    // �ϲ�
    Merge(vec, l, r, mid);
}
int main()
{
    vector<int> v;
    for (int i = 0; i != 10; ++i)
        v.push_back(rand() % 100);

    for (auto i : v)
        cout << i << " ";
    cout << endl;

    MergeSort(v, 0, v.size() - 1);

    // ��ӡ�ź�����
    for (auto i : v)
        cout << i << " ";
    cout << endl;

    return 0;
}