#include <iostream>
using namespace std;

typedef unsigned long long ULL;

int main()
{
    ULL input;
    ULL res = 1;
    
    cin >> input;
    
    if(input)
    {
        for(ULL i = 1; i<=input; ++i)
            res *= i;
    }
    
    cout << res;
    
    return 0;
}
