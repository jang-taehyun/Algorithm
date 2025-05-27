#include <iostream>
#include <string>
#include <set>
using namespace std;

int board[5][5] = {0, };
set<string> s;
string num;
int dy[4] = {0, -1, 1, 0};
int dx[4] = {-1, 0, 0, 1};

void DFS(int len, int y, int x)
{
    string prev;
    set<string>::iterator iter;
    int nx, ny;
    
    if(len >= 6)
    {
        iter = s.find(num);
        if(s.end() == iter)
            s.insert(num);
        
        return;
    }
    
    for(int i=0; i<4; ++i)
    {
        ny = y + dy[i];
        nx = x + dx[i];
        
        if(ny < 0 || ny >= 5 || nx < 0 || nx >= 5)
            continue;
        
        prev = num;
        num += to_string(board[ny][nx]);
        DFS(len+1, ny, nx);
        
        num = prev;
    }
}

int main()
{
    for(int i=0; i<5; ++i)
        for(int j=0; j<5; ++j)
            cin >> board[i][j];
    
    for(int i=0; i<5; ++i)
        for(int j=0; j<5; ++j)
            DFS(0, i, j);
    
    cout << s.size();
    
    return 0;
}
