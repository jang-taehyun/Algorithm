/*
problem : n*m칸의 지도에서 (0, 0)에서 (n-1, m-1)로 가는 방법 중 뚫어야하는 벽의 최소 개수를 구해라.
input : n*m칸의 지도
output : 뚫어야하는 벽의 최소 개수

idea
- 지도를 BFS 방식으로 탐색하되, 다익스트라 알고리즘을 이용해 찾아진 값을 계속 update하고 update된 좌표를 탐색한다.
- 탐색이 끝났다면 (n-1, m-1)에 저장된 값을 출력
*/
#include <iostream>
#include <queue>
using namespace std;

int row, column;            // n*m칸의 지도의 가로, 세로 길이 row, column
bool Map[101][101];         // n*m칸의 지도 Map
int BreakWall[101][101];    // 각 지점에 도달하기 위해 부순 벽의 최소 개수 BreakWall

// 이동 경로
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool CheckRange(int x, int y)
{
    if(x < 0 || y < 0 || x >= row || y >= column)
        return false;
    return true;
}

void BFS()
{
    queue<pair<int, int>> nextSearch;        // 다음에 방문할 칸들의 모음 nextSearch
    
    // (0, 0)을 queue에 넣고 부순 벽의 개수 초기화
    nextSearch.push(make_pair(0, 0));
    BreakWall[0][0] = 0;
    
    // queue가 빌 때까지 반복
    while(!nextSearch.empty())
    {
        // queue에서 좌표 하나 pop
        int cx = nextSearch.front().first;
        int cy = nextSearch.front().second;
        int bw = BreakWall[cy][cx];
        nextSearch.pop();
        
        // 인접한 좌표 탐색
        for(int i=0; i<4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if(!CheckRange(nx, ny))
                continue;
            
            // 벽이면서 부순 벽의 개수가 update된다면, 부순 벽의 개수 update 및 queue에 push
            if(Map[ny][nx] && BreakWall[ny][nx] > bw+1)
            {
                BreakWall[ny][nx] = bw+1;
                nextSearch.push(make_pair(nx, ny));
            }
            // 방이면서 부순 벽의 개수가 update된다면, 부순 벽의 개수 update 및 queue에 push
            else if(!Map[ny][nx] && BreakWall[ny][nx] > bw)
            {
                BreakWall[ny][nx] = bw;
                nextSearch.push(make_pair(nx, ny));
            }
        }
    }
}

int main()
{
    // input 입력
    cin >> row >> column;
    for(int i=0; i<column; i++)
    {
        string input;
        cin >> input;
        
        for(int j=0; j<input.size(); j++)
        {
            Map[i][j] = input[j]-'0';
            BreakWall[i][j] = 999999999;
        }    
    }
    
    BFS();
    
    cout << BreakWall[column-1][row-1];
    
    return 0;
}
