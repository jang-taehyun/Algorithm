#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int bound;
int originBoard[50][50] = {0, };
int copyBoard[50][50] = {0, };
int chooseCount;

pair<int, int> Position[10];
int Choosing[10] = {0, };
bool IsChoose[10] = {false, };
bool IsPossible = false;
int VirusNum = 0;

int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};

int res = 0xffffff;

void DFS(int cnt, int start);
void BFS();
void Reset();

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> bound >> chooseCount;
    for(int i=0; i<bound; ++i)
    {
        for(int j=0; j<bound; ++j)
        {
            cin >> originBoard[i][j];
            
            // 바이러스를 놓을 수 있는 자리이면 따로 저장해놓고, 0으로 표시
            if(2 == originBoard[i][j])
            {
                originBoard[i][j] = 0;
                Position[VirusNum++] = make_pair(i, j);
            }
            // 벽은 -1로 표시
            else if(1 == originBoard[i][j])
                originBoard[i][j] = -1;
        }
    }
    
    // cpoyBoard에 복사하고 DFS 탐색을 통해 바이러스를 놓을 곳 chooseCount개를 고른다.
    Reset();
    DFS(0, 0);
    
    cout << (IsPossible ? res : -1);
    
    return 0;
}

void DFS(int cnt, int start)
{
    // chooseCount개를 모두 고른 후, BFS 탐색을 통해 board 내부를 모두 채울때까지 걸리는 시간 계산
    if(cnt >= chooseCount)
    {
        BFS();
        Reset();
        return;
    }
    
    for(int i=start; i<VirusNum; ++i)
    {
        if(!IsChoose[i])
        {
            IsChoose[i] = true;
            Choosing[cnt] = i;
            DFS(cnt+1, i+1);
            IsChoose[i] = false;
        }
    }
}

void BFS()
{
    queue<pair<int, int>> q;
    int time = 1;
    int QueueSize = 0;
    int ny, nx, cy, cx;
    
    for(int i=0; i<chooseCount; ++i)
    {
        q.push(Position[Choosing[i]]);
        copyBoard[Position[Choosing[i]].first][Position[Choosing[i]].second] = time;
    }
    
    while(!q.empty())
    {
        ++time;
        QueueSize = q.size();
        
        while(QueueSize--)
        {
            cy = q.front().first;
            cx = q.front().second;
            q.pop();
            
            for(int i=0; i<4; ++i)
            {
                ny = cy + dy[i];
                nx = cx + dx[i];
                
                if(ny < 0 || ny >= bound || nx < 0 || nx >= bound)
                    continue;
                if(copyBoard[ny][nx])
                    continue;
                
                q.push(make_pair(ny, nx));
                copyBoard[ny][nx] = time;
            }
        }
    }
    
    time -= 2;
    
    // board 판 검사
    for(int i=0; i<bound; ++i)
        for(int j=0; j<bound; ++j)
            if(!copyBoard[i][j])
                return;
    
    // 모든 칸에 바이러스가 퍼져있다면, 결과값 update
    if(!IsPossible)
        IsPossible = true;
    res = (res > time ? time : res);
}

void Reset()
{
    for(int i=0; i<bound; ++i)
        for(int j=0; j<bound; ++j)
            copyBoard[i][j] = originBoard[i][j];
}
