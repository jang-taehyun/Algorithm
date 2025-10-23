#include <iostream>
using namespace std;
using ULL = unsigned long long;

int main()
{
    ULL x, y, z, comp;
    ULL left = 1, right, mid;
    ULL res = 0;
    
    cin >> x >> y;
    z = y * 100ULL / x;
    
    if(z < 99)
    {
        right = x;
        res = x;
        
        while(left < right)
        {
            mid = (left + right) / 2ULL;
            comp = (y+mid) * 100ULL / (x+mid);
            
            if(comp > z)
            {
                res = (mid < res ? mid : res);
                right = mid;
            }
            else
                left = mid + 1;
        }
        
        cout << res << '\n';
    }
    else
        cout << -1 << '\n';
    
    return 0;
}
