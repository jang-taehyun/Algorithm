#include <iostream>
using namespace std;

typedef unsigned long long ULL;

ULL recursion(ULL a, ULL b, ULL c)
{
    if(b <= 1)
    {
        return a%c;
    }
    
    ULL tmp1, tmp2;
    
    if(b%2)
    {
        tmp1 = recursion(a, b/2, c);
        tmp2 = recursion(a, b/2+1, c);
        
        return (tmp1 * tmp2) % c;
    }
    else
    {
        tmp1 = recursion(a, b/2, c);
        
        return (tmp1 * tmp1) % c;
    }
}

int main()
{
    ULL a, b, c, res;
    
    cin >> a >> b >> c;
    
    res = recursion(a, b, c);
    cout << res;
    
    return 0;
}
