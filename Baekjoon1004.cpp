#include <iostream>
using namespace std;

int main()
{
    int test;
    int sx, sy, ex, ey;
    int len;
    int x, y, r;
    int tmp1, tmp2, tmp3;
    int res = 0;
    
    cin >> test;
    while(test--)
    {
        cin >> sx >> sy >> ex >> ey;
        cin >> len;
        
        while(len--)
        {
            cin >> x >> y >> r;
            
            tmp1 = (sx - x) * (sx - x) + (sy - y) * (sy - y);
            tmp2 = (ex - x) * (ex - x) + (ey - y) * (ey - y);
            tmp3 = r * r;
            
            if((tmp1 <= tmp3 && tmp2 > tmp3) || (tmp1 > tmp3 && tmp2 <= tmp3))
                res++;
        }
        
        cout << res << '\n';
        res = 0;
    }
    
    return 0;
}
