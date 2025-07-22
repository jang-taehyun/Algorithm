#include <iostream>
using namespace std;

typedef unsigned long long ULL;

int GCD(int a, int b)
{
    if(!b)
        return a;
    
    return GCD(b, a%b);
}

int main()
{
    ULL cnt;
    ULL a, b;
    ULL tmp1, tmp2;
    ULL gcd;
    
    cin >> cnt;
    while(cnt--)
    {
        cin >> a >> b;
        
        tmp1 = max(a, b);
        tmp2 = min(a, b);
        
        gcd = GCD(tmp1, tmp2);
        
        cout << (a * b / gcd) << '\n';
    }
    
    return 0;
}
