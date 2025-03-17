#include <iostream>
using namespace std;

int c, r;
int board[1000][1000] = {0, };
int dp[1000][1000] = {0, };

int dy[3] = {-1, 0, -1};
int dx[3] = {0, -1, -1};

int main()
{
    int ny, nx;
    
    cin >> c >> r;
    for(int i=0; i<c; ++i)
        for(int j=0; j<r; ++j)
            cin >> board[i][j];
    
    // dp 계산
    dp[0][0] = board[0][0];
    for(int i=0; i<c; ++i)
    {
        for(int j=0; j<r; ++j)
        {
            if(!i && !j)
                continue;
            
            dp[i][j] = board[i][j];
            
            for(int k=0; k<3; ++k)
            {
                ny = i + dy[k];
                nx = j + dx[k];
                
                if(ny < 0 || ny >= c || nx < 0 || nx >= r)
                    continue;
                
                if(dp[i][j] < dp[ny][nx] + board[i][j])
                    dp[i][j] = dp[ny][nx] + board[i][j];
            }
        }
    }
    
    cout << dp[c-1][r-1];
    
    return 0;
}
