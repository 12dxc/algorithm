#include <iostream>
using namespace std;

int sum(int arr[], int len, int l)
{
    if (l == len)
    {
        return 0;
    }
    return arr[l] + sum(arr, len, l + 1);
}

int main()
{

    int arr[] = {1, 2, 3, 4, 5, 6};
    int len = sizeof(arr) / sizeof(arr[0]);
    cout << sum(arr, len, 0) << endl;

    system("pause");
    return 0;
}