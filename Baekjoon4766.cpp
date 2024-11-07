#include <iostream>
using namespace std;

int main()
{
    float prev, cur;
    float res;
    
    cout << fixed;
    cout.precision(2);
    
    cin >> prev;
    while(1)
    {
        cin >> cur;
        if(cur == (float)999)
            break;
        
        res = cur - prev;
        cout << res << '\n';
        
        prev = cur;
    }
    
    return 0;
}
