#include <iostream>
using namespace std;

bool ExistNum[1000001];
int input[100000];
int len;
int sum;
int res = 0;

int main()
{
    int tmp;

    cin >> len;
    for (int i = 0; i < len; i++)
    {
        cin >> input[i];
        ExistNum[input[i]] = true;
    }
    cin >> sum;

    for (int i = 0; i < len; i++)
    {
        tmp = sum - input[i];

        if (tmp > 0 && tmp <= 100000 && tmp != input[i] && ExistNum[tmp])
            res++;
    }
    res /= 2;

    cout << res;

    return 0;
}