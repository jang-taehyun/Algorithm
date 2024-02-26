/*
problem : n*m 칸의 상자에 들어있는 토마토가 모두 익을 때까지 걸리는 시간을 구해라.
input : n*m 칸의 상자
output : n*m 칸의 상자에 들어있는 토마토간 모두 익을 때까지 걸리는 시간

idea
- 상자 안에 있는 토마토들을 BFS 방식으로 익지 않는 토마토를 탐색하여 탐색할 때마다 (이전에 탐색한 토마토의 번호+1)을 해준다.
- 탐색이 끝난 후, (가장 큰 숫자-1)을 출력한다.
- 탐색이 끝난 후, 만약 0이 있다면 -1을 출력한다.
- 탐색이 끝난 후, 만약 가장 큰 값이 1이라면 하루가 지나지 않은 것이므로 0을 출력한다.
*/
#include <iostream>
#include <queue>
using namespace std;

int row, column;                   // 토마토가 들어있는 상자의 가로, 세로 row, column
int box[1000][1000];               // 토마토가 들어있는 상자 box
queue<pair<int, int>> nextSearch;  // BFS 방식으로 탐색 시에 사용되는 queue
int day;                           // 상자 안에 모든 토마토가 익는데 걸리는 시간 day

// (x, y)칸에 연결된 칸 : 왼쪽부터 상, 하, 좌, 우
int dx[4]={0, 0, -1, +1};
int dy[4]={-1, +1, 0, 0};

void BFS()
{
    while(!nextSearch.empty())
    {
        // queue에서 좌표 pop
        int currentX = nextSearch.front().first;
        int currentY = nextSearch.front().second;
        nextSearch.pop();
        
        // 현재 좌표와 연결된 칸을 모두 탐색
        for(int i=0; i<4; i++)
        {
            int nextX=currentX+dx[i];
            int nextY=currentY+dy[i];
        
            // 범위를 넘어가면 다른 칸을 확인한다.
            if(nextX < 0 || nextY < 0 || nextX >= column || nextY >= row)
                continue;
            
            // 다음 좌표에 0이 저장되어 있다면 (현재 좌표에 저장된 숫자 + 1)을 해준 후 queue에 push
            if(!box[nextX][nextY])
            {
                box[nextX][nextY] = box[currentX][currentY] + 1;
                nextSearch.push(make_pair(nextX, nextY));
            }
        }
    }
}

int main()
{
    // input 입력
    cin >> row >> column;
    for(int i=0; i<column; i++)
        for(int j=0; j<row; j++)
        {
            cin >> box[i][j];
            
            // 이때 익은 토마토의 좌표를 queue에 push
            if(box[i][j] == 1)
                nextSearch.push(make_pair(i, j));
        }
            
    // BFS 방식으로 상자 탐색
    BFS();
    
    // 상자 확인
    for(int i=0; i<column; i++)
    {
        for(int j=0; j<row; j++)
        {
            // 상자 안에 0이 존재하는 경우 -1을 출력 후 종료
            if(!box[i][j])
            {
                cout << -1;
                return 0;
            }
            
            // 최대값으로 day를 설정
            day = box[i][j] > day ? box[i][j] : day;
        }
    }
    
    // 저장된 값에서 -1을 빼서 출력
    cout << day-1;
    
    return 0;
}
