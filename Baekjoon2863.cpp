#include <iostream>
using namespace std;

int main()
{
    double a, b, c, d;
    double tmp, large;
    int res = 0;
    
    cin >> a >> b >> c >> d;
    
    large = a / c + b / d;
    for(int i=1; i<=3; i++)
    {
        tmp = c;
        c = d;
        d = b;
        b = a;
        a = tmp;
        
        tmp = a / c + b / d;
        
        if(tmp > large)
        {
            res = i;
            large = tmp;
        }
    }
    
    cout << res;
    
    return 0;
}