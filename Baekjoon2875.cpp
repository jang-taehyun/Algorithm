#include <iostream>
using namespace std;

int main()
{
    int w, m, e;
    int tmp1, tmp2, tmp3;
    int res = 0;
    
    cin >> w >> m >> e;
    
    for(int i=0; i<=e; i++)
    {
        if(w-i > 0 && m-(e-i) > 0)
        {
            tmp1 = w-i;
            tmp2 = m-(e-i);
            tmp3 = 0;
            
            while(tmp1 > 1 && tmp2 > 0)
            {
                tmp1 -= 2;
                tmp2 -= 1;
                tmp3++;
            }
            
            if(tmp3 > res)
                res = tmp3;
        }
    }
    
    cout << res;
    
    return 0;
}
