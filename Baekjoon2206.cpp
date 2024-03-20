/*
problem : n*m board에서 벽을 하나 부수거나, 부수지 않고 (1, 1)에서 시작해 (n ,m)까지 가는 최단 경로를 구해라.
input : n*m board
output : 벽을 하나 부수거나, 부수지 않고 (1, 1)에서 시작해 (n, m)까지 가는 최단 경로

idea
- root는 시작점(1, 1), level은 이동한 칸의 개수, node는 상하좌우로 이동한 후의 좌표와 이전에 벽을 부섰는지 여부를 나타내는 tree를 만든다.
- 최단 경로는 tree를 BFS 탐색하여 구한다.
- 탐색할 때 이미 탐색한 칸은 더 탐색하지 않는다.
- 만약 이전에 벽을 부수지 않았다면, 벽을 만났을 때 한 번 부순다.
- 만약 이전에 벽을 부순 적이 있다면, 벽을 만났을 때 부수지 않는다.

참고자료 : https://kscodebase.tistory.com/66
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#define BOUND 1000
using namespace std;

int Column, Row;                // board의 세로, 가로 길이
int Board[BOUND][BOUND];        // board
bool Search[BOUND][BOUND][2];   // 위치의 탐색 여부
                                // 0 : 벽을 부수지 않았을 때, 1 : 벽을 부섰을 때
int dx[4] = { 0, 0, 1, -1 };      // 이동 방향
int dy[4] = { -1, 1, 0, 0 };

// node의 현재 상태를 나타내는 자료형
typedef struct _state
{
    int x;
    int y;
    bool BreakWall;
} NodeState;

// 범위, 탐색 여부 검사
bool IsPromising(int _x, int _y, bool IsBreakWall);

// 최단 경로 구하기
int BFS();

int main()
{
    string input;

    // board의 정보 입력
    cin >> Column >> Row;
    for (int i = 0; i < Column; i++)
    {
        cin >> input;

        for (int j = 0; j < Row; j++)
            Board[i][j] = input[j] - '0';
    }

    // BFS 탐색 진행 후 결과 출력
    cout << BFS();

    return 0;
}

bool IsPromising(int _x, int _y, bool IsBreakWall)
{
    if (_x < 0 || _x >= Column || _y < 0 || _y >= Row)
        return false;

    if (Search[_x][_y][IsBreakWall])
        return false;

    return true;
}

int BFS()
{
    queue<NodeState> next;                 // 다음에 탐색할 칸
    int MoveCount = 1;                       // 이동한 횟수
    int QueueSize;                         // 한 level의 크기
    int CurX, CurY, NextX, NextY;          // 현재 위치, 다음 위치
    bool CurrentState, NextState;          // 현재 node의 상태, 다음 node의 상태

    // 시작점(1, 1)을 탐색 설정하고 queue에 넣는다.
    Search[0][0][0] = true;
    next.push({ 0, 0, 0 });

    while (!next.empty())
    {
        // 현재 queue의 크기만큼 반복
        QueueSize = next.size();
        while (QueueSize--)
        {
            // queue에서 node를 하나 꺼내서 탐색
            CurX = next.front().x;
            CurY = next.front().y;
            CurrentState = next.front().BreakWall;
            next.pop();

            // 도착점에 도달하면 현재 level(이동한 칸의 횟수)를 return
            if (CurX == Column - 1 && CurY == Row - 1)
                return MoveCount;

            // 4가지 방향 중 조건에 맞는 칸을 찾아 queue에 넣는다.
            for (int dir = 0; dir < 4; dir++)
            {
                NextX = CurX + dx[dir];
                NextY = CurY + dy[dir];
                NextState = CurrentState;

                if (!IsPromising(NextX, NextY, NextState))
                    continue;

                // 벽이 아닌 경우
                if (!Board[NextX][NextY])
                {
                    Search[NextX][NextY][NextState] = true;
                    next.push({ NextX, NextY, NextState });
                }

                // 벽이면서, 아직 벽을 깬 적이 없는 경우
                if (Board[NextX][NextY] && !NextState)
                {
                    Search[NextX][NextY][NextState] = true;
                    NextState = 1;
                    Search[NextX][NextY][NextState] = true;
                    next.push({ NextX, NextY, NextState });
                }
            }
        }

        // level 증가
        MoveCount++;
    }

    // 방법을 찾지 못했으므로 -1을 return
    return -1;
}