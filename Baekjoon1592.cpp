#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n, bound, adder;
    int res=0;
    int cur=1;
    int recv[51];
    
    memset(recv, 0, sizeof(recv));
    cin >> n >> bound >> adder;
    
    while(1)
    {
        recv[cur]++;
        
        if(recv[cur] >= bound)
            break;
        
        if(recv[cur] % 2)
        {
            cur += adder;
            if(cur > n)
                cur -= n;
        }
        else
        {
            cur -= adder;
            if(cur < 1)
                cur += n;
        }
        
        res++;
    }
    
    cout << res;
    
    return 0;
}
