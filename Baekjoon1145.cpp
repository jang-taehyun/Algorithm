#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int input[5];
    int res;
    int count;

    for (int i = 0; i < 5; i++)
        cin >> input[i];

    sort(input, input + 5);
    res = input[0];

    while (1)
    {
        count = 0;

        for (int i = 0; i < 5; i++)
            if (!(res % input[i]))
                count++;

        if (count >= 3)
            break;

        res++;
    }

    cout << res;

    return 0;
}