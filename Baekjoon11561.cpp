#include <iostream>
using namespace std;

typedef unsigned long long ULL;

int main()
{
    ULL test, s=1, e, m, len, sum, res=1;
    
    cin >> test;
    while(test--)
    {
        cin >> len;
        
        s = 1;
        e = len;
        res = 1;
        
        while(s <= e)
        {
            m = (s+e)/2;
            sum = (m * (m+1)) / 2;
            
            if(sum <= len)
            {
                res = (m > res ? m : res);
                s = m+1;
            }
            else
                e = m-1;
        }
        
        cout << res << '\n';
    }
    
    return 0;
}
