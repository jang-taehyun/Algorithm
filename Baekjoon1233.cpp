#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int input[3];
    int count[81];
    int bound = 0;
    int res = 0;

    memset(count, 0, sizeof(count));

    for (int i = 0; i < 3; i++)
        cin >> input[i];

    for (int i = 0; i < 3; i++)
        bound += input[i];

    for (int i = 1; i <= input[0]; i++)
        for (int j = 1; j <= input[1]; j++)
            for (int k = 1; k <= input[2]; k++)
                count[i + j + k]++;

    for (int i = 1; i <= bound; i++)
        if (count[res] < count[i])
            res = i;

    cout << res;

    return 0;
}