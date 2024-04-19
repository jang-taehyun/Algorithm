#include <iostream>
using namespace std;

int main()
{
    int input[4];
    int zero = 0;

    while (cin >> input[0] >> input[1] >> input[2] >> input[3])
    {
        zero = 0;

        for (int i = 0; i < 4; i++)
            if (!input[i])
                zero++;

        switch (zero)
        {
        case 0:
            cout << 'E' << '\n';
            break;
        case 1:
            cout << 'A' << '\n';
            break;
        case 2:
            cout << 'B' << '\n';
            break;
        case 3:
            cout << 'C' << '\n';
            break;
        case 4:
            cout << 'D' << '\n';
            break;
        }
    }

    return 0;
}