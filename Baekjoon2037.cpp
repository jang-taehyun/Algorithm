#include <iostream>
#include <string>
using namespace std;

typedef unsigned long long ULL;

string input;
ULL res = 0;
ULL p, w;
int prevn = -1;

ULL Sol(int idx)
{
    int cur = 0;
    ULL tmp = 0;

    switch (input[idx])
    {
    case ' ':
        cur = 1;
        break;
    case 'A': case 'B': case 'C':
        cur = 2;
        break;
    case 'D': case 'E': case 'F':
        cur = 3;
        break;
    case 'G': case 'H': case 'I':
        cur = 4;
        break;
    case 'J': case 'K': case 'L':
        cur = 5;
        break;
    case 'M': case 'N': case 'O':
        cur = 6;
        break;
    case 'P': case 'Q': case 'R': case 'S':
        cur = 7;
        break;
    case 'T': case 'U': case 'V':
        cur = 8;
        break;
    case 'W': case 'X': case 'Y': case 'Z':
        cur = 9;
        break;
    }

    switch (input[idx])
    {
    case ' ': case 'A': case 'D': case 'G':
    case 'J': case 'M': case 'P': case 'T':
    case 'W':
        tmp += p;
        break;
    case 'B': case 'E': case 'H': case 'K':
    case 'N': case 'Q': case 'U': case 'X':
        tmp += (p * 2);
        break;
    case 'C': case 'F': case 'I': case 'L':
    case 'O': case 'R': case 'V': case 'Y':
        tmp += (p * 3);
        break;
    default:
        tmp += (p * 4);
        break;
    }

    if (prevn == cur)
    {
        if (prevn != 1)
            tmp += w;
    }
    prevn = cur;

    return tmp;
}

int main()
{
    cin >> p >> w;
    getchar();
    getline(cin, input);

    for (int i = 0; i < input.length(); i++)
        res += Sol(i);

    cout << res;

    return 0;
}
