#include <iostream>
using namespace std;

int res = 0;
bool visited[100][100];
int r, c;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

bool Check(int y, int x)
{
    if(x < 0 || y < 0 || x >= r || y >= c || visited[y][x])
        return false;
    
    return true;
}

void DFS(int y, int x, int dir)
{
    int nx, ny;
    
    visited[y][x] = true;
    
    ny = y + dy[dir];
    nx = x + dx[dir];
    
    if(!Check(ny, nx))
    {
        int tmp = (dir + 1) % 4;
        bool IsFind = false;
        
        while(tmp != dir)
        {
            ny = y + dy[tmp];
            nx = x + dx[tmp];
            
            if(Check(ny, nx))
            {
                IsFind = true;
                break;
            }
            
            tmp = (tmp + 1) % 4;
        }
        
        if(!IsFind)
            return;
        
        res++;
        dir = tmp;
    }
    
    DFS(ny, nx, dir);
}

int main()
{
    cin >> c >> r;
    
    DFS(0, 0, 0);
    
    cout << res;
    
    return 0;
}
