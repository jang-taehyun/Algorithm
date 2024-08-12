#include <iostream>
using namespace std;

int main()
{
    int n, k;
    int res=0;
    
    cin >> n >> k;
    k--;
    
    for(int i=1; i<=n; i++)
    {
        if(!(n % i))
        {
            if(k)
                k--;
            else
            {
                res = i;
                break;
            }
        }
    }
    
    cout << res;
    
    return 0;
}
