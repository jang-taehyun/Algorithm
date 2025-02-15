#include <iostream>
using namespace std;

int len;
int r, c;
int res = 0;

void recur(int cy, int cx, int l)
{
    if(l <= 1)
    {
        if(cy == r && cx == c)
        {
            cout << res;
            exit(0);
        }
        
        return;
    }
    
    if(r < cy+l/2 && c < cx+l/2)
    {
        recur(cy, cx, l/2);
    }
    else if(r < cy+l/2 && c >= cx+l/2)
    {
        res += ((l/2) * (l/2));
        recur(cy, cx+l/2, l/2);
    }
    else if(r >= cy+l/2 && c < cx+l/2)
    {
        res += (2 * ((l/2) * (l/2)));
        recur(cy+l/2, cx, l/2);
    }
    else
    {
        res += (3 * ((l/2) * (l/2)));
        recur(cy+l/2, cx+l/2, l/2);
    }
}

int main()
{
    cin >> len >> r >> c;
    len = (1 << len);
    recur(0, 0, len);
    
    return 0;
}