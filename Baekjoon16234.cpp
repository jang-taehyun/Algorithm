#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int bound;
int board[50][50] = {0, };
int Start, End;

bool IsChoose[50][50] = {false, };
queue<pair<int, int>> Choose[2500];

int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};

int res = 0;

bool Check(int y, int x);
bool Search(int y, int x, int idx);
void Union(int idx);

int main()
{
    bool IsFinish = false;
    int idx = 0;
    
    cin >> bound >> Start >> End;
    for(int i=0; i<bound; ++i)
        for(int j=0; j<bound; ++j)
            cin >> board[i][j];
    
    while(!IsFinish)
    {
        // 연합을 모두 구하기
        for(int i=0; i<bound; ++i)
            for(int j=0; j<bound; ++j)
            {
                if(!IsChoose[i][j])
                {
                    if(Search(i, j, idx))
                        idx++;
                }
            }
        
        // 연합이 있는지 확인
        IsFinish = true;
        if(idx)
        {
            for(int i=0; i<idx; ++i)
                if(!Choose[i].empty())
                {
                    IsFinish = false;
                    break;
                }
        }
        else
        {
            if(!Choose[idx].empty())
                IsFinish = false;
        }
        if(IsFinish)
            continue;
        
        // 연합에 속한 요소들의 값을 업데이트
        for(int i=0; i<idx; ++i)
            Union(i);
        
        // 초기화 및 res값 증가
        idx = 0;
        memset(IsChoose, false, sizeof(IsChoose));
        res++;
    }
    
    cout << res;
    
    return 0;
}

bool Check(int y, int x)
{
    if(y < 0 || y >= bound || x < 0 || x >= bound)
        return false;
    return true;
}

bool Search(int y, int x, int idx)
{
    queue<pair<int, int>> search;    // BFS 탐색 큐
    queue<pair<int, int>> history;   // 탐색한 좌표를 모두 넣는 큐
    int ny, nx, cy, cx;
    int tmp = 0;
    
    // 시작 좌표를 넣고 IsChoose에 표시
    search.push(make_pair(y, x));
    history.push(make_pair(y, x));
    IsChoose[y][x] = true;
    
    while(!search.empty())
    {
        cy = search.front().first;
        cx = search.front().second;
        search.pop();
        
        for(int i=0; i<4; ++i)
        {
            ny = cy + dy[i];
            nx = cx + dx[i];
            
            if(!Check(ny, nx))
                continue;
            if(IsChoose[ny][nx])
                continue;
            
            tmp = abs(board[cy][cx] - board[ny][nx]);
            if(!(Start <= tmp && tmp <= End))
                continue;
            
            search.push(make_pair(ny, nx));
            history.push(make_pair(ny, nx));
            IsChoose[ny][nx] = true;
        }
    }
    
    // history가 1개라면 연합이 없으므로 이전 상태로 되돌리기
    if(history.size() < 2)
    {
        while(!history.empty())
        {
            cy = history.front().first;
            cx = history.front().second;
            history.pop();
            
            IsChoose[cy][cx] = false;
        }
        return false;
    }
    
    // 연합에 속한 요소들은 큐에 넣기
    while(!history.empty())
    {
        Choose[idx].push(history.front());
        history.pop();
    }
    
    return true;
}

void Union(int idx)
{
    int cy, cx;
    int num = 0, len;
    
    // 큐에 있는 모든 요소들의 총합 구하기
    len = Choose[idx].size();
    for(int i=0; i<len; ++i)
    {
        cy = Choose[idx].front().first;
        cx = Choose[idx].front().second;
        Choose[idx].pop();
        Choose[idx].push(make_pair(cy, cx));
        
        num += board[cy][cx];
    }
    
    // 큐에 있는 모든 요소들의 값을 업데이트
    num /= len;
    while(!Choose[idx].empty())
    {
        cy = Choose[idx].front().first;
        cx = Choose[idx].front().second;
        Choose[idx].pop();
        
        board[cy][cx] = num;
    }
}
