#include <iostream>
using namespace std;

int main()
{
    int input[5];
    int avg = 0, tmp;
    for (int i = 0; i < 5; i++)
        cin >> input[i];

    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (input[i] > input[j])
            {
                tmp = input[j];
                input[j] = input[i];
                input[i] = tmp;
            }
        }
    }

    for (int i = 0; i < 5; i++)
        avg += input[i];

    cout << avg / 5 << '\n' << input[5 / 2];

    return 0;
}