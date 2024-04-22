#include <iostream>
#define YOUNG 30
#define MIN 60
#define YOUNG_PRICE 10
#define MIN_PRICE 15
using namespace std;

int main()
{
    int input[20];
    int testcount;
    int res1 = 0, res2 = 0;

    cin >> testcount;
    for (int i = 0; i < testcount; i++)
        cin >> input[i];

    for (int i = 0; i < testcount; i++)
    {
        res1 += (input[i] / YOUNG + 1);
        res2 += (input[i] / MIN + 1);
    }

    res1 *= YOUNG_PRICE;
    res2 *= MIN_PRICE;

    if (res1 < res2)
    {
        cout << 'Y' << ' ' << res1;
    }
    else if (res1 > res2)
    {
        cout << 'M' << ' ' << res2;
    }
    else
    {
        cout << 'Y' << ' ' << 'M' << ' ' << res1;
    }

    return 0;
}