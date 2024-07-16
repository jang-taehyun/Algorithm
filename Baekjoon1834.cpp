#include <iostream>
using namespace std;

typedef unsigned long long ULL;

int main()
{
    ULL input;
    ULL res=0;
    
    cin >> input;
    for(ULL i=1; i<input; i++)
        res += (input * i + i);
    
    cout << res;
    
    return 0;
}
