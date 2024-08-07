#include <iostream>
using namespace std;

int main()
{
    int res=0, cur=0;
    int up, down;
    
    for(int i=0; i<4; i++)
    {
        cin >> down >> up;
        
        cur = (cur - down) + up;
        if(cur > res)
            res = cur;
    }
    
    cout << res;
    
    return 0;
}
