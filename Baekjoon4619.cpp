#include <iostream>
#include <cmath>
using namespace std;

typedef unsigned int UINT;

int main()
{
    double b, n;
    UINT res=1;
    
    while(1)
    {
        cin >> b >> n;
        if(!b && !n)
            break;
        
        while(b > pow(res, n))
            res++;
        
        if(abs(b - pow(res,n)) > abs(b - pow(res-1, n)))
            cout << res-1 << '\n';
        else
            cout << res << '\n';
        
        res = 1;
    }
    
    return 0;
}
