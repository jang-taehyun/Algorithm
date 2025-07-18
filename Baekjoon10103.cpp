#include <iostream>
using namespace std;

int main()
{
    int cnt;
    int sum1=100, sum2=100, a, b;
    
    cin >> cnt;
    while(cnt--)
    {
        cin >> a >> b;
        
        if(a > b)
            sum2 -= a;
        else if(a < b)
            sum1 -= b;
    }
    
    cout << sum1 << '\n' << sum2;
    
    return 0;
}
