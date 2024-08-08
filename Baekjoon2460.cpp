#include <iostream>
using namespace std;

int main()
{
    int In, Out;
    int cur=0, res=0;
    
    for(int i=0; i<10; i++)
    {
        cin >> Out >> In;
        cur = (cur - Out) + In;
        
        if(cur > res)
            res = cur;
    }
    
    cout << res;
    
    return 0;
}
