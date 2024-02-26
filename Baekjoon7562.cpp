/*
problem : n*n 칸의 체스판에서 나이트가 (x, y)로 가는 최소 이동 횟수를 구해라.
input : 체스판의 한 변의 길이, 현재 나이트의 위치, 이동하고자 하는 위치
output : 이동하고자 하는 위치로 가는 최소 이동 횟수

idea : 나이트의 이동 경로를 BFS 방식으로 탐색하여 번호를 붙이면서 탐색한다,
*/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int chessboardLength;                   // 체스판의 한 변의 길이 chessboardLength
int chessboard[300][300];               // 체스판 chessboard
bool isVisited[300][300];               // 각 칸의 방문 여부 isVisited
int targetX, targetY;                   // 목표 지점 targetX, targetY
queue<pair<int, int>> nextSearch;       // 다음에 탐색할 칸들의 모음 nextSearch

// 나이트의 이동 경로
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

void BFS(int x, int y)
{
    // queue에 현재 좌표 push 및 방문 처리
    isVisited[x][y] = true;
    nextSearch.push(make_pair(x, y));
    
    // queue가 비어있을 때까지 반복
    while(!nextSearch.empty())
    {
        // queue에서 좌표 하나를 pop
        int currentX = nextSearch.front().first;
        int currentY = nextSearch.front().second;
        nextSearch.pop();
        
        // 다음에 이동할 위치 계산
        for(int i=0; i<8; i++)
        {
            int nx = currentX + dx[i];
            int ny = currentY + dy[i];
            
            // 범위를 넘어가면 다른 좌표 탐색
            if(nx < 0 || ny < 0 || nx >= chessboardLength || ny >= chessboardLength)
                continue;
            
            // 처음 방문한 위치라면 (현재 좌표의 번호+1)을 해준 후 queue에 push 및 방문 처리
            if(!isVisited[nx][ny])
            {
                isVisited[nx][ny]=true;
                chessboard[nx][ny] = chessboard[currentX][currentY] + 1;
                nextSearch.push(make_pair(nx, ny));
            }           
        }
    }
}

int main()
{
    // 테스트 케이스 입력
    int testcase;
    cin >> testcase;
    
    while(testcase--)
    {
        int x, y;        // 나이트의 처음 좌표 x, y
        
        // input 입력
        cin >> chessboardLength;
        cin >> x >> y;
        cin >> targetX >> targetY;
        
        // BFS로 탐색
        BFS(x, y);
        
        // 탐색 결과 출력
        cout << chessboard[targetX][targetY] << '\n';
        
        // 방문 여부와 체스판 초기화
        memset(chessboard, 0, sizeof(chessboard));
        memset(isVisited, false, sizeof(isVisited));
    }
    
    return 0;
}
