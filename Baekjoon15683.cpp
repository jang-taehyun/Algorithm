#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct CCTVTypeOneRotate
{
    int a;
};

struct CCTVTypeTwoRotate
{
    int y;
    int x;
};

struct CCTVTypeThreeRotate
{
    int y;
    int x;
};

struct CCTVTypeFourRotate
{
    int y;
    int x;
    int z;
};

int c, r;
int originBoard[8][8] = {0, };
int copyBoard[8][8] = {0, };

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

CCTVTypeOneRotate rotate1[4] = {0, 1, 2, 3};
CCTVTypeTwoRotate rotate2[2] = {
    {0, 2},
    {1, 3}
};
CCTVTypeThreeRotate rotate3[4] = {
    {0, 3},
    {0, 1},
    {1, 2},
    {2, 3}
};
CCTVTypeFourRotate rotate4[4] = {
    {0, 2, 3},
    {0, 1, 3},
    {0, 1, 2},
    {1, 2, 3}
};

int RotateIdx[8] = {0, };
vector<pair<int, int>> CCTVPosition;

int res = 65;

bool Check(int y, int x);
void ResetBoard();
void DFS(int cnt);
void SetCCTVMonitoringToCopy(int y, int x, int dir);
void SetCCTVMonitoringToOrigin(int y, int x, int dir);

int main()
{
    queue<pair<int, int>> CCTVTypeFive;
    int y, x;
    
    // Input
    cin >> c >> r;
    for(int i=0; i<c; ++i)
        for(int j=0; j<r; ++j)
        {
            cin >> originBoard[i][j];
            
            if(originBoard[i][j] && originBoard[i][j] == 5)
                CCTVTypeFive.push(make_pair(i, j));
            else if(originBoard[i][j] && originBoard[i][j] != 6)
                CCTVPosition.push_back(make_pair(i, j));
        }
    
    // 5번 타입의 CCTV를 board에 반영
    while(!CCTVTypeFive.empty())
    {
        y = CCTVTypeFive.front().first;
        x = CCTVTypeFive.front().second;
        CCTVTypeFive.pop();
        
        for(int i=0; i<4; ++i)
            SetCCTVMonitoringToOrigin(y, x, i);
    }
    
    // 사각지대의 최소 크기 찾기
    ResetBoard();
    DFS(0);
    
    cout << res;
    
    return 0;
}

bool Check(int y, int x)
{
    if(y < 0 || y >= c || x < 0 || x >= r)
        return false;
    if(6 == copyBoard[y][x] || 6 == originBoard[y][x])
        return false;
    
    return true;
}

void ResetBoard()
{
    for(int i=0; i<c; ++i)
        for(int j=0; j<r; ++j)
            copyBoard[i][j] = originBoard[i][j];
}

void DFS(int cnt)
{
    int cy, cx;
    
    if(cnt >= CCTVPosition.size())
    {
        int tmp = 0;
        
        for(int i=0; i<CCTVPosition.size(); ++i)
        {
            cy = CCTVPosition[i].first;
            cx = CCTVPosition[i].second;
            
            if(1 == copyBoard[cy][cx])
            {
                SetCCTVMonitoringToCopy(cy, cx, rotate1[RotateIdx[i]].a);
            }
            else if(2 == copyBoard[cy][cx])
            {
                SetCCTVMonitoringToCopy(cy, cx, rotate2[RotateIdx[i]].y);
                SetCCTVMonitoringToCopy(cy, cx, rotate2[RotateIdx[i]].x);
            }
            else if(3 == copyBoard[cy][cx])
            {
                SetCCTVMonitoringToCopy(cy, cx, rotate3[RotateIdx[i]].y);
                SetCCTVMonitoringToCopy(cy, cx, rotate3[RotateIdx[i]].x);
            }
            else if(4 == copyBoard[cy][cx])
            {
                SetCCTVMonitoringToCopy(cy, cx, rotate4[RotateIdx[i]].y);
                SetCCTVMonitoringToCopy(cy, cx, rotate4[RotateIdx[i]].x);
                SetCCTVMonitoringToCopy(cy, cx, rotate4[RotateIdx[i]].z);
            }
        }
        
        for(int i=0; i<c; ++i)
            for(int j=0; j<r; ++j)
                if(!copyBoard[i][j])
                    tmp++;
        
        if(res > tmp)
            res = tmp;
        
        ResetBoard();
        
        return;
    }
    
    cy = CCTVPosition[cnt].first;
    cx = CCTVPosition[cnt].second;
    
    if(1 == copyBoard[cy][cx])
    {
        for(int i=0; i<4; ++i)
        {
            RotateIdx[cnt] = i;
            DFS(cnt+1);
        }
    }
    else if(2 == copyBoard[cy][cx])
    {
        for(int i=0; i<2; ++i)
        {
            RotateIdx[cnt] = i;
            DFS(cnt+1);
        }
    }
    else if(3 == copyBoard[cy][cx])
    {
        for(int i=0; i<4; ++i)
        {
            RotateIdx[cnt] = i;
            DFS(cnt+1);
        }
    }
    else if(4 == copyBoard[cy][cx])
    {
        for(int i=0; i<4; ++i)
        {
            RotateIdx[cnt] = i;
            DFS(cnt+1);
        }
    }
}

void SetCCTVMonitoringToCopy(int y, int x, int dir)
{
    int cy, cx, ny, nx;
    
    cy = y;
    cx = x;
    
    while(1)
    {
        ny = cy + dy[dir];
        nx = cx + dx[dir];
        
        if(!Check(ny, nx))
            break;
        if(!(1 <= copyBoard[ny][nx] && copyBoard[ny][nx] <= 5))
            copyBoard[ny][nx] = 7;
        cy = ny;
        cx = nx;
    }
}

void SetCCTVMonitoringToOrigin(int y, int x, int dir)
{
    int cy, cx, ny, nx;
    
    cy = y;
    cx = x;
    
    while(1)
    {
        ny = cy + dy[dir];
        nx = cx + dx[dir];
        
        if(!Check(ny, nx))
            break;
        if(!(1 <= originBoard[ny][nx] && originBoard[ny][nx] <= 5))
            originBoard[ny][nx] = 7;
        cy = ny;
        cx = nx;
    }
}
