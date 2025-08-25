#include <iostream>
using namespace std;

int board[1024][1024] = {0, };
int arr[1024][1024] = { 0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, cnt, tmp;
    int x1, y1, x2, y2;
    int res;
    
    cin >> n >> cnt;
    
    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
            cin >> board[i][j];
    
    for(int i=0; i<n; ++i)
    {
        tmp = 0;
        for(int j=0; j<n; ++j)
        {
            tmp += board[i][j];
            
            if(!i)
                arr[i][j] = tmp;
            else
                arr[i][j] = arr[i-1][j] + tmp;
        }
    }
    
    while(cnt--)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        
        --x1;
        --y1;
        --x2;
        --y2;
        
        res = arr[x2][y2];
        
        if(x1-1 >= 0)
            res -= arr[x1-1][y2];
        if(y1-1 >= 0)
            res -= arr[x2][y1-1];
        if(x1-1 >= 0 && y1-1 >= 0)
            res += arr[x1-1][y1-1];
        
        cout << res << '\n';
    }
    
    return 0;
}
