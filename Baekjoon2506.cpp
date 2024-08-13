#include <iostream>
using namespace std;

int main()
{
    int cnt;
    bool tmp;
    int res=0, adder=0;
    
    cin >> cnt;
    while(cnt--)
    {
        cin >> tmp;
        
        if(tmp)
            adder++;
        else
            adder=0;
        
        res += adder;
    }
    
    cout << res;
    
    return 0;
}
