#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

// ���ŷָ��
int Partation(vector<int> &vec, int l, int r)
{
    // �Ż�����2������ȡ�з���ּ����ѡ���ʵĻ�׼������ֹ�����˻���ð�����򡣼���left��mid��right��ȡ�м�ֵ����Ϊ��׼ֵ��
    int val = vec[l]; // ��¼��׼��
    // һ�ο��Ŵ���
    while (l < r)
    {
        // ��r��ʼ��ǰ�ҵ�һ�� < val������
        while (l < r && vec[r] > val)
            r--;
        // �ŵ�l�ĵط���l++
        if (l < r)
        {
            vec[l] = vec[r];
            l++;
        }
        // ��l��ʼ�����ҵ�һ�� > val������
        while (l < r && vec[l] < val)
            l++;
        // �ŵ�r�ĵط���r--
        if (l < r)
        {
            vec[r] = vec[l];
            r--;
        }
    }
    // l == r��λ�ã����ǷŻ�׼����λ��
    vec[l] = val;
    return l;
}
// �ҵ�k��ģ���vec.size()-k���±�
int max_selectTopK(vector<int> &vec, int i, int j, int k)
{
    int pos = Partation(vec, i, j); // pos��ʾ��׼��λ��
    if (pos == vec.size() - k)      // �ҵ��� ��׼����λ�ú�topK��kֵ�����
    {
        return vec[pos];
    }
    else if (pos < vec.size() - k) // topKӦ�ڻ�׼���ұ�
    {
        return max_selectTopK(vec, pos + 1, j, k);
    }
    else // topKӦ�ڻ�׼�����
    {
        return max_selectTopK(vec, i, pos - 1, k);
    }
}

int main()
{
    vector<int> v;
    for (int i = 0; i != 20; ++i)
        v.push_back(rand() % 100);

    // ���top 10���Ԫ��
    int val = max_selectTopK(v, 0, v.size() - 1, 10);
    cout << "val: " << val << endl;

    // ��ӡ�ź�����
    sort(v.begin(), v.end());
    for (auto i : v)
        cout << i << " ";
    cout << endl;

    return 0;
}