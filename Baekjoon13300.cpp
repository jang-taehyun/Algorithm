#include <iostream>
using namespace std;

int count[6][2];
int len;
int divide;
int res = 0;

int main()
{
    int tmp1, tmp2;

    cin >> len >> divide;
    for (int i = 0; i < len; i++)
    {
        cin >> tmp1 >> tmp2;
        count[tmp2 - 1][tmp1]++;
    }

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            tmp1 = count[i][j] / divide;
            tmp2 = count[i][j] % divide;

            if (!tmp2)
                res += tmp1;
            else
                res += (tmp1 + 1);
        }
    }

    cout << res;

    return 0;
}