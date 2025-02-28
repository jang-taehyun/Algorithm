#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

char board[12][6] = {0, };
queue<pair<int, int>> storage;

int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};
bool visited[12][6] = {false, };

int res = 0;

void BFS(int y, int x, char mark);
void Move();

int main()
{
    for(int i=0; i<12; i++)
        for(int j=0; j<6; j++)
            cin >> board[i][j];
    
    while(1)
    {
        for(int i=0; i<12; i++)
            for(int j=0; j<6; j++)
                if(!visited[i][j] && board[i][j] != '.')
                    BFS(i, j, board[i][j]);
        
        if(storage.empty())
            break;
        
        while(!storage.empty())
        {
            board[storage.front().first][storage.front().second] = '.';
            storage.pop();
        }
        
        res++;
        Move();
        memset(visited, false, sizeof(visited));
    }
    
    cout << res;
    
    return 0;
}

void BFS(int y, int x, char mark)
{
    queue<pair<int, int>> bfs;
    queue<pair<int, int>> chaining;
    bool BFS_visited[12][6] = {false, };
    int cy, cx, nx, ny;
    
    BFS_visited[y][x] = true;
    bfs.push(make_pair(y, x));
    chaining.push(make_pair(y, x));
    
    while(!bfs.empty())
    {
        cy = bfs.front().first;
        cx = bfs.front().second;
        bfs.pop();
        
        for(int i=0; i<4; i++)
        {
            ny = cy + dy[i];
            nx = cx + dx[i];
            
            if(ny < 0 || ny >= 12 || nx < 0 || nx >= 6)
                continue;
            if(BFS_visited[ny][nx] || (board[ny][nx] != mark))
                continue;
            
            BFS_visited[ny][nx] = true;
            bfs.push(make_pair(ny, nx));
            chaining.push(make_pair(ny, nx));
        }
    }
    
    if(chaining.size() >= 4)
    {
        while(!chaining.empty())
        {
            visited[chaining.front().first][chaining.front().second] = true;
            storage.push(chaining.front());
            chaining.pop();
        }
    }
}

void Move()
{
    int bottom = -1;
    int tmp;
    
    for(int i=0; i<6; i++)
    {
        bottom = -1;
        
        for(int j=11; j>=0; j--)
        {
            if(board[j][i] == '.')
            {
                if(bottom < j)
                    bottom = j;
                continue;
            }
            
            if(bottom == -1)
                continue;
            
            board[bottom][i] = board[j][i];
            board[j][i] = '.';
            
            tmp = bottom;
            bottom = -1;
            for(int k=tmp; k>=j; k--)
                if(board[k][i] == '.')
                {
                    bottom = k;
                    break;
                }
        }
    }
}
