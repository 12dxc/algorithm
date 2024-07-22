#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*���ֱ�������: ��n�����壬��i�����������Ϊwi����ֵΪvi����������������C����������ܼ�ֵ�����ߡ�
ÿһ�����嶼����ֻȡ��һ���֣���ֵ���������������㡣������ܼ�ֵ��*/

struct Product // ��Ʒ��Ϣ����
{
    double getPrice() const // �Լ۱�
    {
        return v * 1.0 / w;
    }
    bool operator>(const Product &p) const
    {
        return getPrice() > p.getPrice();
    }
    int id; // ��Ʒ��id
    int w;  // ��Ʒ������
    int v;  // ��Ʒ�ļ�ֵ
};
int main()
{
    int w[] = {8, 6, 4, 2, 5}; // ÿ����Ʒ������
    int v[] = {6, 4, 7, 8, 6}; // ÿ����Ʒ�ļ�ֵ
    const int n = sizeof(w) / sizeof(w[0]);
    int c = 12;     // ��������
    int x[n] = {0}; // ��¼��Щ��Ʒ��װ�뱳��

    // ����Ϣ�������������
    Product pros[n];
    for (int i = 0; i < n; ++i)
    {
        pros[i].id = i;
        pros[i].w = w[i];
        pros[i].v = v[i];
    }
    // ����Ʒ���Լ۱Ƚ��н�������
    sort(pros, pros + n, [](const Product &p1, const Product &p2) -> bool
         { return p1 > p2; });

    // ���Լ۱ȸߵ�����������ţ�ֻ���Ǿֲ������Ž⣩
    double bestV = 0.0; // ��¼����������ֵ
    for (int i = 0; i < n; ++i)
    {
        if (pros[i].w <= c) // ˵����i����Ʒ����װ�뱳��
        {
            bestV += pros[i].v; // ���ӱ������м�ֵ
            c -= pros[i].w;     // ���ٱ�������
        }
        else // ˵����i����Ʒ�޷�ȫ��װ�뱳������ʣ�������ı���װ����Ʒ��һ����
        {
            bestV = bestV + pros[i].v * (c * 1.0 / pros[i].w);
            x[pros[i].id] = 1;
            break;
        }
        x[pros[i].id] = 1;
    }
    cout << "bestV:" << bestV << endl;
    for (int v : x)
    {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}