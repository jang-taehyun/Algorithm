#include <iostream>
#include <algorithm>
using namespace std;

int GCD(int a, int b)
{
    int mx = max(a, b);
    int mn = min(a, b);
    
    if(!mn)
        return mx;
    
    return GCD(mn, mx % mn);
}

int main()
{
    int n;
    int a, b;
    int res1, res2;
    
    cin >> n;
    while(n--)
    {
        cin >> a >> b;
        
        res1 = GCD(a, b);
        res2 = (a * b) / res1;
        
        cout << res2 << ' ' << res1 << '\n';
    }
    
    return 0;
}
