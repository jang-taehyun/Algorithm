/*
problem : n*n 칸의 지도에서 두 대륙을 연결하는 가장 짧은 다리의 길이를 구해라.
input : n*n 칸의 지도
output : 두 대륙을 연결하는 가장 짧은 다리의 길이

idea
- n*n 칸의 지도를 BFS 방식으로 돌면서 대륙에 숫자를 붙인다.
- 대륙에 속한 (x, y)에서 시작하여 BFS 방식으로 탐색하면서 가장 짧은 다리의 길이를 구한다.
*/
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int Map[100][100];                         // n*n 칸의 지도 Map
int MapLength;                             // 지도의 한 변의 길이 MapLength
int ContinentNum;                          // 대륙의 개수 ContinentNum
bool isVisited[100][100];                  // 각 위치의 방문 여부 isVisited

// 각 위치의 이동 경로 : 왼쪽부터 상, 하, 좌, 우
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

// 대륙 찾기
void SearchContientBFS(int x, int y, int _label)
{
    // queue 생성 & queue에 현재 좌표 push
    queue<pair<int, int>> nextSearch;
    nextSearch.push(make_pair(x, y));
    
    // 현재 좌표에 대륙 번호 저장 & 방문 표시
    Map[x][y] = _label;
    isVisited[x][y] = true;
    
    // queue가 빌 때까지 반복
    while(!nextSearch.empty())
    {
        // queue에서 좌표 하나를 pop
        int cx = nextSearch.front().first;
        int cy = nextSearch.front().second;
        nextSearch.pop();
        
        // 현재 좌표와 연결된 모든 좌표 확인
        for(int i=0; i<4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            // 범위를 넘어가면 다른 좌표 탐색
            if(nx < 0 || ny < 0 || nx >= MapLength || ny >= MapLength)
                continue;
            
            // 아직 방문하지 않았으면서, 땅이면 queue에 push & 대륙에 포함
            if(!isVisited[nx][ny] && Map[nx][ny] == -1)
            {
                // 방문 표시
                isVisited[nx][ny] = true;
                nextSearch.push(make_pair(nx, ny));
                Map[nx][ny] = _label;
            }
        }
    }
}

// 현재 좌표에서 가장 짧은 다리 찾기
int FindShortestBridge(int _label)
{ 
    queue<pair<int, int>> nextSearch;
    int minimumLength=0;                        // 현재 좌표에서 만들 수 있는 가장 짧은 다리의 길이
    
    // 현재 대륙에 포함된 좌표를 모두 queue에 push
    for(int i=0; i<MapLength; i++)
        for(int j=0; j<MapLength; j++)
            if(Map[i][j] == _label)
            {
                nextSearch.push(make_pair(i, j));
                
                // 방문 처리
                isVisited[i][j] = true;
            }
    
    // queue가 빌 때까지 반복
    while(!nextSearch.empty())
    {
        // 현재 queue의 크기만큼 반복
        int currentSearchPointNum = nextSearch.size();
        for(int i=0; i<currentSearchPointNum; i++)
        {
            // queue에서 좌표 하나를 pop
            int cx = nextSearch.front().first;
            int cy = nextSearch.front().second;
            nextSearch.pop();
            
            // 현재 좌표와 연결된 모든 검사
            for(int j=0; j<4; j++)
            {
                int nx = cx + dx[j];
                int ny = cy + dy[j];
                
                // 범위를 넘어가면 다른 좌표 탐색
                if(nx < 0 || ny < 0 || nx >= MapLength || ny >= MapLength)
                    continue;
                
                // 다른 대륙을 만났다면 다리 길이 return
                if(Map[nx][ny] != 0 && Map[nx][ny] != _label)
                    return minimumLength;
                
                // 만약 방문하지 않았으면서, 바다라면 queue에 push 및 방문 표시
                if(!isVisited[nx][ny] && Map[nx][ny] == 0)
                {
                    nextSearch.push(make_pair(nx, ny));
                    isVisited[nx][ny] = true;
                }
            }
        }
        
        // 다리의 길이 증가
        minimumLength++;
    }
}

int main()
{
    // input 입력
    cin >> MapLength;
    for(int i=0; i<MapLength; i++)
        for(int j=0; j<MapLength; j++)
        {
            int tmp;
            cin >> tmp;
            
            Map[i][j] = (tmp == 0 ? 0 : -1);
        }
    
    // 대륙 찾기
    for(int i=0; i<MapLength; i++)
        for(int j=0; j<MapLength; j++)
            // 땅이라면 탐색 시작
            if(Map[i][j] == -1)
                SearchContientBFS(i, j, ++ContinentNum);
    
    // 방문 여부 초기화
    memset(isVisited, false, sizeof(isVisited));
    
    int result=999999999;
    int findValue;
    
    // 가장 짧은 다리의 길이 구하기
    for(int i=1; i<ContinentNum; i++)
    {
        findValue = FindShortestBridge(i);
        result = findValue < result ? findValue : result;
                
        // 방문 표시 초기화
        memset(isVisited, false, sizeof(isVisited));
    }
    
    // 결과값 출력
    cout << result;
    
    return 0;
}
