#include <iostream>
using namespace std;

int column, row;
bool visited[100][100];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int res=0;

bool IsPromising(int y, int x)
{
    if(y < 0 || y >= column || x < 0 || x >= row)
        return false;
    if(visited[y][x])
        return false;
    return true;
}

void DFS(int cy, int cx, int dr)
{
    visited[cy][cx] = true;
    
    if(!IsPromising(cy + dy[dr], cx + dx[dr]))
    {
        dr += 1;
        if(dr >= 4)
            dr = 0;
        
        if(!IsPromising(cy + dy[dr], cx + dx[dr]))
            return;
        
        res++;
    }
    
    DFS(cy + dy[dr], cx + dx[dr], dr);
}

int main()
{
    cin >> column >> row;
    DFS(0, 0, 0);
    
    cout << res;
    
    return 0;
}
