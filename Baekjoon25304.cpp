#include <iostream>
using namespace std;

typedef unsigned long long ULL;

int main()
{
    ULL x, n, a, b;
    ULL res=0;
    
    cin >> x >> n;
    for(ULL i=0; i<n; i++)
    {
        cin >> a >> b;
        res += (a * b);
    }
    
    cout << (res == x ? "Yes" : "No");
    
    return 0;
}
