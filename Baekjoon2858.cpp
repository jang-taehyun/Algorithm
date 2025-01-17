#include <iostream>
using namespace std;

typedef unsigned long long ULL;

int main()
{
    ULL r, b;
    ULL bw, bh;
    ULL rw, rh;
    
    cin >> r >> b;
    
    bw = 1;
    bh = b;
    while(bw <= b/2)
    {
        rw = bw + 2;
        rh = bh + 2;
        
        if(rw * rh == r + b)
            break;
        
        while(1)
        {
            bw++;
            
            if(bw > b/2)
                break;
            
            if(!(b % bw))
            {
                bh = b / bw;
                break;
            }
        }
    }
    
    cout << (bh + 2) << ' ' << (bw + 2);
    
    return 0;
}
