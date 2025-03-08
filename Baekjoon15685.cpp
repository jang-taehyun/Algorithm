#include <iostream>
#include <vector>
using namespace std;

bool board[101][101] = {false, };
int vy[4] = {0, -1, 0, 1};
int vx[4] = {1, 0, -1, 0};
vector<int> v;
int res = 0;

int dy[3] = {0, 1, 0};
int dx[3] = {1, 0, -1};

void route(int y, int x, int g)
{
    int cy, cx, cv, len;
    int ny, nx;
    int cg = 1;
    
    cy = y;
    cx = x;
    
    while(cg <= g)
    {
        len = v.size();
        for(int i=len-1; i>=0; --i)
        {
            cv = (v[i] + 5) % 4;
            ny = cy + vy[cv];
            nx = cx + vx[cv];
            
            board[ny][nx] = true;
            v.push_back(cv);
            
            cy = ny;
            cx = nx;
        }
        cg++;
    }
}

int main()
{
    int cnt;
    int x, y, dir, g;
    int ny, nx;
    bool IsRectangle = false;
    
    cin >> cnt;
    while(cnt--)
    {
        cin >> x >> y >> dir >> g;
        board[y][x] = true;
        
        ny = y + vy[dir];
        nx = x + vx[dir];
        board[ny][nx] = true;
        
        v.push_back(dir);
        route(ny, nx, g);
        
        v.clear();
    }
    
    for(int i=0; i<100; ++i)
    {
        for(int j=0; j<100; ++j)
        {
            if(board[i][j])
            {
                IsRectangle = true;
                
                y = i;
                x = j;
                
                for(int k=0; k<3; ++k)
                {
                    ny = y + dy[k];
                    nx = x + dx[k];
                    
                    if(ny < 0 || ny >= 101 || nx < 0 || nx >= 101)
                    {
                        IsRectangle = false;
                        break;
                    }
                    if(!board[ny][nx])
                    {
                        IsRectangle = false;
                        break;
                    }
                    
                    y = ny;
                    x = nx;
                }
                
                if(IsRectangle)
                    res++;
            }
        }
    }
    
    cout << res;
    
    return 0;
}
