#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    bool IsWhite[8][8];
    string input;
    int res = 0;

    memset(IsWhite, false, sizeof(IsWhite));
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if ((!(i % 2) && !(j % 2)) || ((i % 2) && (j % 2)))
                IsWhite[i][j] = true;

    for (int i = 0; i < 8; i++)
    {
        cin >> input;

        for (int j = 0; j < 8; j++)
            if ('F' == input[j] && IsWhite[i][j])
                res++;
    }

    cout << res;

    return 0;
}