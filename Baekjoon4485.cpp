#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

struct Point
{
    int y, x;
};

int len;
vector<vector<int>> board;

int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};

int BFS()
{
    vector<vector<int>> b;
    queue<Point> q;
    Point cur, next;
    
    b.resize(len);
    for(int i=0; i<len; ++i)
        b[i].resize(len, INT_MAX);
    
    b[0][0] = board[0][0];
    q.push({0, 0});
    while(!q.empty())
    {
        cur = q.front();
        q.pop();
        
        for(int i=0; i<4; ++i)
        {
            next.y = cur.y + dy[i];
            next.x = cur.x + dx[i];
            
            if(0 <= next.y && next.y < len && 0 <= next.x && next.x < len)
            {
                if(board[next.y][next.x] + b[cur.y][cur.x] < b[next.y][next.x])
                {
                    b[next.y][next.x] = board[next.y][next.x] + b[cur.y][cur.x];
                    q.push(next);
                }
            }
        }
    }
    
    return b[len-1][len-1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int idx = 1;
    
    while(1)
    {
        cin >> len;
        
        if(!len)
            break;
        
        board.resize(len);
        for(int i=0; i<len; ++i)
            board[i].resize(len, 0);
        
        for(int i=0; i<len; ++i)
            for(int j=0; j<len; ++j)
                cin >> board[i][j];
        
        cout << "Problem " << idx << ": ";
        cout << BFS() << '\n';
        
        ++idx;
    }
    
    return 0;
}
