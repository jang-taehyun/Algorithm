#include <iostream>
using namespace std;

int c, r;
int len;
int sum[1000][1000] = {0, };

int main()
{
    int tmp;
    int res = 0;
    int sy, sx, ey, ex;
    
    cin >> c >> r >> len;
    for(int i=0; i<c; ++i)
        for(int j=0; j<r; ++j)
        {
            cin >> tmp;
            sum[i][j] = tmp + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
        }
            
    
    while(len--)
    {
        cin >> sy >> sx >> ey >> ex;
        res = sum[ey-1][ex-1] - sum[sy-2][ex-1] - sum[ey-1][sx-2] + sum[sy-2][sx-2];
        cout << (res / ((abs(ey-sy)+1) * (abs(ex-sx)+1))) << '\n';
    }
    
    return 0;
}
