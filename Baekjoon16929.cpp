/*
problem : n*m 칸의 직사각형 중에서 색상이 square cycle을 이룬다면 yes, 아니라면 no을 출력해라.
input : n*m 칸의 직사각형, 각 칸에 칠해진 색상
output : square cycle을 이룬다면 yes, 아니라면 no을 출력

idea : n*m 칸을 DFS 방식으로 탐색하면서 square cycle을 이루는 지 확인한다.
*/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int row, column;             // n*m 칸의 직사각형의 가로, 세로의 길이 row, column
char boardColor[50][50];     // n*m 칸의 직사각형에 칠해진 색깔 boardColor
bool isVisited[50][50];      // 각 칸의 방문 여부 isVisited
bool isCycle=false;          // cycle을 이루는지 판단 isCycle

// 각 칸의 이동 경로 : 왼쪽부터 상, 하, 좌, 우
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void DFS(int x, int y, int currentCount, int startX, int startY)
{
    // 현재 칸 방문 처리
    isVisited[x][y] = true;
    
    // 다음에 이동하는 칸이 같이 색깔이라면 DFS 방식으로 칸을 이동한다.
    for(int i=0; i<4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        // 범위를 넘어가면 다른 칸을 탐색
        if(nx < 0 || ny < 0 || nx >= column || ny >= row)
            continue;
        
        // 만약 시작점에 도달했으면서, 방문 횟수가 4를 넘는다면 cycle이 있다고 판단하고 프로그램 종료
        if(nx == startX && ny == startY && currentCount >= 4)
        {
            cout << "Yes";
            exit(0);
        }
        
        // 색깔이 같고, 아직 방문하지 않은 칸만 탐색
        if(boardColor[nx][ny] == boardColor[x][y] && !isVisited[nx][ny])
            DFS(nx, ny, currentCount+1, startX, startY);
    }
    
    // 방문 처리 해제
    isVisited[x][y] = false;
}

int main()
{
    string input;
    
    // input 입력
    cin >> column >> row;
    for(int i=0; i<column; i++)
    {
        cin >> input;
        for(int j=0; j<input.length(); j++)
            boardColor[i][j] = input[j];
    }
    
    // DFS 방식으로 모든 칸을 탐색
    for(int i=0; i<column; i++)
    {
        for(int j=0; j<row; j++)
        {
            DFS(i, j, 1, i, j);
            
            // 탐색이 끝난 시작 지점은 다시 방문하지 않게 방문 처리
            isVisited[i][j] = true;
        }
    }
    
    // 프로그램이 종료되지 않닸다면 cycle이 없다는 뜻이므로 NO을 출력
    cout << "No";
    
    return 0;
}
