#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

    vector<int> v = {1, 23, 4, 8, 5, 3, 5, 4, 7, 53};

    for (int i = v.size(); i > 0; i--)
    {
        int min = i;
        for (int j = i; j > 0; j--)
        {
            if (v[j] > v[min])
            {
                min = j;
            }
        }
        swap(v[i], v[min]);
    }

    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
    }

    system("pause");
    return 0;
}