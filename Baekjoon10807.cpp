#include <iostream>
using namespace std;

int count[201];
int len, target;

int main()
{
    int tmp;

    cin >> len;
    for (int i = 0; i < len; i++)
    {
        cin >> tmp;

        if (tmp < 0)
            tmp = (tmp * -1) + 100;

        count[tmp]++;
    }

    cin >> target;
    if (target < 0)
        target = (target * -1) + 100;

    cout << count[target];

    return 0;
}