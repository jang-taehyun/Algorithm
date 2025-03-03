#include <iostream>
using namespace std;

typedef struct _point_
{
    int y;
    int x;
} Purifier;

int r, c, second;
int cur_board[50][50] = {0, };
int next_board[50][50] = {0, };

Purifier sTop = {0, 0};
Purifier sBottom = {0, 0};

// Top의 이동 방향
int Top_dy[4] = {0, -1, 0, 1};
int Top_dx[4] = {1, 0, -1, 0};

// Bottom의 이동 방향
int Bottom_dy[4] = {0, 1, 0, -1};
int Bottom_dx[4] = {1, 0, -1, 0};

void Spread();
void Work(int y, int x, bool IsTopDir);

int main()
{
    bool bIsTopInput = false;
    int res = 0;
    
    cin >> c >> r >> second;
    for(int i=0; i<c; ++i)
    {
        for(int j=0; j<r; ++j)
        {
            cin >> cur_board[i][j];
            
            if(-1 == cur_board[i][j])
            {
                if(!bIsTopInput)
                {
                    sTop.y = i;
                    sTop.x = j;
                    bIsTopInput = true;
                }
                else
                {
                    sBottom.y = i;
                    sBottom.x = j;
                }
            }
        }
    }
    
    while(second--)
    {
        Spread();
        Work(sTop.y, sTop.x, true);
        Work(sBottom.y, sBottom.x, false);
    }
    
    for(int i=0; i<c; ++i)
        for(int j=0; j<r; ++j)
            if(-1 != cur_board[i][j])
                res += cur_board[i][j];
    
    cout << res;
    
    return 0;
}

void Spread()
{
    int ny, nx;
    
    for(int i=0; i<c; ++i)
        for(int j=0; j<r; ++j)
            next_board[i][j] = cur_board[i][j];
    
    for(int i=0; i<c; ++i)
    {
        for(int j=0; j<r; ++j)
        {
            if(!cur_board[i][j] || -1 == cur_board[i][j])
                continue;
            
            for(int k=0; k<4; ++k)
            {
                ny = i + Top_dy[k];
                nx = j + Top_dx[k];
                
                if(ny < 0 || ny >= c || nx < 0 || nx >= r)
                    continue;
                if(-1 == cur_board[ny][nx])
                    continue;
                
                next_board[ny][nx] += (cur_board[i][j] / 5);
                next_board[i][j] -= (cur_board[i][j] / 5);
            }
        }
    }
    
    for(int i=0; i<c; ++i)
        for(int j=0; j<r; ++j)
            cur_board[i][j] = next_board[i][j];
}

void Work(int y, int x, bool IsTopDir)
{
    int idx = 0;
    int cy, cx, ny, nx, next, cur;
    
    if(IsTopDir)
    {
        cy = sTop.y + Top_dy[idx];
        cx = sTop.x + Top_dx[idx];
    }
    else
    {
        cy = sBottom.y + Bottom_dy[idx];
        cx = sBottom.x + Bottom_dx[idx];
    }
    
    cur = cur_board[cy][cx];
    cur_board[cy][cx] = 0;
    
    while(1)
    {
        if(IsTopDir)
        {
            ny = cy + Top_dy[idx];
            nx = cx + Top_dx[idx];
        }
        else
        {
            ny = cy + Bottom_dy[idx];
            nx = cx + Bottom_dx[idx];
        }
        
        if(ny < 0 || ny >= c || nx < 0 || nx >= r)
        {
            idx++;
            continue;
        }
        
        if(ny == y && nx == x)
            break;
        
        next = cur_board[ny][nx];
        cur_board[ny][nx] = cur;
        cur = next;
        
        cy = ny;
        cx = nx;
    }
}
