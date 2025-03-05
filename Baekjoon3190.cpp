#include <iostream>
#include <deque>
using namespace std;

int len;
int board[100][100] = {0, };
deque<pair<int, int>> snake;

int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
bool IsFinish = false;

int res = 0;

bool CheckRange(int y, int x)
{
    if(y < 0 || y >= len || x < 0 || x >= len)
        return false;
    return true;
}

void recur(int dir, int last)
{
    int y, x;
    
    if(res == last || (last == -1 && IsFinish))
        return;
    
    y = snake.front().first + dy[dir];
    x = snake.front().second + dx[dir];
    res++;
    
    if(!CheckRange(y, x) || board[y][x] == 2)
    {
        IsFinish = true;
        return;
    }
    
    if(board[y][x] != 1)
    {
        board[snake.back().first][snake.back().second] = 0;
        snake.pop_back();
    }
        
    board[y][x] = 2;
    snake.push_front(make_pair(y, x));
    
    recur(dir, last);
}

int main()
{
    int count, y, x;
    int s;
    char command;
    int cdir = 0;
    
    snake.push_front(make_pair(0, 0));
    
    cin >> len;
    cin >> count;
    while(count--)
    {
        cin >> y >> x;
        board[y-1][x-1] = 1;
    }
    
    cin >> count;
    while(count--)
    {
        cin >> s >> command;
        
        if(!IsFinish)
        {
            recur(cdir, s);
            
            if('L' == command)
                cdir = (cdir + 1) % 4;
            else
                cdir = (cdir + 3) % 4;
        }
    }
    
    if(!IsFinish)
        recur(cdir, -1);
    
    cout << res;
    
    return 0;
}
