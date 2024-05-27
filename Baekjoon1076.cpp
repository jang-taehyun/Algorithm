#include <iostream>
#include <string>
using namespace std;

int main()
{
    int num[3];
    string input;

    for (int i = 0; i < 3; i++)
    {
        cin >> input;

        if ("black" == input)
            num[i] = 0;
        else if ("brown" == input)
            num[i] = 1;
        else if ("red" == input)
            num[i] = 2;
        else if ("orange" == input)
            num[i] = 3;
        else if ("yellow" == input)
            num[i] = 4;
        else if ("green" == input)
            num[i] = 5;
        else if ("blue" == input)
            num[i] = 6;
        else if ("violet" == input)
            num[i] = 7;
        else if ("grey" == input)
            num[i] = 8;
        else if ("white" == input)
            num[i] = 9;
    }

    unsigned long long res = (unsigned long long)((num[0] * 10) + num[1]);
    for (int i = 0; i < num[2]; i++)
        res *= (unsigned long long)10;

    cout << res;

    return 0;
}