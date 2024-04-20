#include <iostream>
#define MIN(x, y) (x) < (y) ? (x) : (y)
using namespace std;

int main()
{
    int input[7];
    int min = 100;
    int sum = 0;

    for (int i = 0; i < 7; i++)
        cin >> input[i];

    for (int i = 0; i < 7; i++)
    {
        if (input[i] % 2)
        {
            sum += input[i];
            min = MIN(min, input[i]);
        }
    }

    if (sum)
        cout << sum << '\n' << min;
    else
        cout << -1;

    return 0;
}