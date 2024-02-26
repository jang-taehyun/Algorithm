/*
problem : n*m 칸의 지도에서 섬의 개수를 구해라.
input : n*m 칸의 지도
output : 섬의 개수

idea : 각 테스트 케이스마다 n*m 칸을 DFS 방식으로 탐색하여 섬의 개수를 구한다.
*/
#include <iostream>
#include <cstring>
using namespace std;

bool Map[50][50];        // n*m 칸의 지도
int row, column;         // 지도의 가로, 세로 길이 row, column
bool isVisited[50][50];  // 각 칸의 방문 여부 isVisited

// 지도 이동 경로 : 왼쪽부터 상, 하, 좌, 우, 좌상, 우상, 좌하, 우하
int deltX[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int deltY[8] = {0, 0, -1, 1, -1, 1, -1, 1};

int islandCount;         // 섬의 개수 islandCount

void DFS(int x, int y)
{
    // 현재 좌표 방문 표시
    isVisited[x][y] = true;
    
    // 현재 좌표와 인접한 칸 중 연결된 칸을 모두 방문
    for(int i=0; i<8; i++)
    {
        int next_x = x + deltX[i];
        int next_y = y + deltY[i];
        
        // 범위를 넘어가는 경우 다음 좌표로 넘어간다.
        if(next_x < 0 || next_y < 0 || next_x >= column || next_y >= row)
            continue;
        
        // 인접한 칸 중 방문하지 않으면서, 연결된 칸을 모두 탐색
        if(!isVisited[next_x][next_y] && Map[next_x][next_y])
            DFS(next_x, next_y);
    }
}

int main()
{
    while(cin >> row >> column)
    {  
        // row와 column이 0이라면 loop 종료
        if(!row && !column)
            break;
        
        // 지도 입력
        for(int i=0; i<column; i++)
            for(int j=0; j<row; j++)
                cin >> Map[i][j];
        
        // DFS 방식으로 지도 탐색
        for(int i=0; i<column; i++)
        {
            for(int j=0; j<row; j++)
            {
                // 만약 현재 칸을 방문하지 않고 땅이 존재한다면, islandCount을 1개 증가시키고 탐색
                if(!isVisited[i][j] && Map[i][j])
                {
                    islandCount++;
                    DFS(i, j);
                }
            }
        }
        
        // 섬의 개수 출력
        cout << islandCount << '\n';
        
        // 섬의 개수, 방문 여부, 지도 초기와
        islandCount=0;
        memset(isVisited, false, sizeof(isVisited));
        memset(Map, false, sizeof(Map)); 
    }
    
    return 0;
}
