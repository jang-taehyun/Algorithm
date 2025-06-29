#include <iostream>
using namespace std;

int main()
{
    bool board[100][100] = {false, };
    int cnt;
    int x, y;
    int res = 0;
    
    cin >> cnt;
    while(cnt--)
    {
        cin >> x >> y;
        
        for(int i=y-1; i<(y-1+10); ++i)
            for(int j=x-1; j<(x-1+10); ++j)
                board[i][j] = true;
    }
    
    for(int i=0; i<100; ++i)
        for(int j=0; j<100; ++j)
            if(board[i][j])
                ++res;
    
    cout << res;
    
    return 0;
}
