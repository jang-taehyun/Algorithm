#include <iostream>
#define MAX(x, y) (x) > (y) ? (x) : (y)
#define MIN(x, y) (x) < (y) ? (x) : (y)
using namespace std;

typedef unsigned long long ULL;

int main()
{
    ULL input1, input2;
    ULL start, end;

    cin >> input1 >> input2;

    start = MIN(input1, input2);
    end = MAX(input1, input2);

    if (start != end)
        cout << (end - start) - (ULL)1 << '\n';
    else
        cout << 0 << '\n';
    for (ULL i = start + (ULL)1; i < end; i += (ULL)1)
        cout << i << ' ';

    return 0;
}