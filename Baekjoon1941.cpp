#include <iostream>
#include <queue>
using namespace std;

char board[5][5];
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};
int res = 0;

int Choose[7] = {0, };
bool IsSelected[25] = {false, };

bool IsMoreThanFour()
{
    int y, x;
    int cntS = 0;
    
    for(int i=0; i<7; i++)
    {
        y = Choose[i] / 5;
        x = Choose[i] % 5;
        
        if(board[y][x] == 'S')
            cntS++;
    }
    
    return (cntS >= 4 ? true : false);
}

bool IsAdjacent()
{
    queue<pair<int, int>> q;
    bool IsCheck[5][5] = {false, };
    bool IsInSelect[5][5] = {false, };
    int cnt = 1;
    bool IsConnect = false;
    int cy, cx, nx, ny;
    
    for(int i=0; i<7; i++)
    {
        cy = Choose[i] / 5;
        cx = Choose[i] % 5;
        IsInSelect[cy][cx] = true;
    }
    
    cy = Choose[0] / 5;
    cx = Choose[0] % 5;
    IsCheck[cy][cx] = true;
    q.push(make_pair(cy, cx));
    
    while(!q.empty())
    {
        cy = q.front().first;
        cx = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++)
        {
            ny = cy + dy[i];
            nx = cx + dx[i];
            
            if(ny < 0 || ny >= 5 || nx < 0 || nx >= 5)
                continue;
            if(IsCheck[ny][nx] || !IsInSelect[ny][nx])
                continue;
            if(!IsCheck[ny][nx] && IsInSelect[ny][nx])
            {
                cnt++;
                q.push(make_pair(ny, nx));
                IsCheck[ny][nx] = true;
            }
        }
    }
    
    return (cnt >= 7 ? true : false);
}

void DFS(int start, int cnt)
{
    if(cnt >= 7)
    {
        if(IsMoreThanFour() && IsAdjacent())
            res++;
        
        return;
    }
    
    for(int i=start; i<25; i++)
    {
        if(!IsSelected[i])
        {
            IsSelected[i] = true;
            Choose[cnt] = i;
            DFS(i+1, cnt+1);
            IsSelected[i] = false;
        }
    }
}

int main()
{
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            cin >> board[i][j];
    
    DFS(0, 0);
    
    cout << res;
    
    return 0;
}
