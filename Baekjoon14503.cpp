#include <iostream>
using namespace std;

int r, c, dir;
int cy, cx;
int board[50][50] = {0, };

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

int res = 0;

bool CheckRange(int y, int x)
{
    if(y < 0 || y >= c || x < 0 || x >= r)
        return false;
    return true;
}

void recur(int y, int x, int dir)
{
    int cdir;
    int ny, nx;
    bool IsExistNotCleaning = false;
    
    // 1. 현재 칸의 상태를 보고 청소
    if(!board[y][x])
    {
        board[y][x] = 2;
        res++;
    }
    
    // 주변에 청소가 안된 칸이 있는지 확인
    for(int i=0; i<4; ++i)
    {
        cdir = (dir + i) % 4;
        
        ny = y + dy[cdir];
        nx = x + dx[cdir];
        
        if(!CheckRange(ny, nx))
            continue;
        if(board[ny][nx])
            continue;
        
        IsExistNotCleaning = true;
        break;
    }
    
    // 청소할 칸이 없는 경우
    if(!IsExistNotCleaning)
    {
        ny = y - dy[dir];
        nx = x - dx[dir];
        
        if(CheckRange(ny, nx) && board[ny][nx] != 1)
            recur(ny, nx, dir);
    }
    // 청소할 칸이 있는 경우
    else
    {
        cdir = (dir + 1) % 4;
        ny = y + dy[cdir];
        nx = x + dx[cdir];
        
        if(CheckRange(ny, nx) && !board[ny][nx])
            recur(ny, nx, cdir);
        else
            recur(y, x, cdir);
    }
}

int main()
{
    cin >> c >> r;
    cin >> cy >> cx >> dir;
    for(int i=0; i<c; ++i)
        for(int j=0; j<r; ++j)
            cin >> board[i][j];
    
    if(dir == 1)
        dir = 3;
    else if(dir == 3)
        dir = 1;
    
    recur(cy, cx, dir);
    
    cout << res;
    
    return 0;
}
