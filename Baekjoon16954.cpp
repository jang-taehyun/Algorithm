/*
problem : 8*8 board에서 (7, 0)에서부터 시작해 (0, 7)까지 이동하려고 한다.
          board에서 벽(#인 칸)은 1초마다 아래 행으로 내려가고 아래 행이 없다면 사라진다.
          player는 상하좌우 또는 대각선으로 한 칸 이동하거나 현재 위치에 서 있을 수 있고, 빈 칸으로만 이동할 수 있다.
          1초 동안 player가 먼저 이동하고 다음에 벽이 이동한다.
          벽이 player가 있는 칸으로 이동하면 player는 더이상 이동할 수 없다.
          8*8 board에서 player가 (7, 0)에서부터 시작해 (0, 7)까지 이동할 수 있는지 구해라.
input : 8*8 board의 상태
output : 8*8 board에서 player가 (7, 0)에서부터 시작해 (0, 7)까지 이동할 수 있는지 구해라.

idea
- root가 (7, 0), level이 이동한 칸의 횟수(탐색 시간), node가 이동한 후의 player의 위치를 나타내는 tree를 만든다.
- tree를 BFS 방식으로 탐색한다.
- 한 level를 모두 탐색하면 board의 상태를 바꾼다.
- node를 탐색하기 전에 현재 node의 위치가 벽인지 확인한다. 벽이면 이동하지 않는다.
*/
#include <iostream>
#include <queue>
#include <string>
#define BOARD_SIZE 8
#define START_X 7
#define START_Y 0
#define END_X 0
#define END_Y 7
#define WALL_MOVE_X 1
#define WALL_MOVE_Y 0
using namespace std;

char Board[BOARD_SIZE][BOARD_SIZE];            // board의 상태
int dx[9] = { -1, -1, -1, 0, 0, 0, 1, 1, 1 };    // 이동 방향
int dy[9] = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };
queue<pair<int, int>> WallPosition;            // 벽들의 위치

// 범위 검사
bool Range(int x, int y);

// 범위, 벽 검사
bool Promising(int x, int y);

// tree 탐색
bool BFS();

int main()
{
    string input;

    // 8*8 board를 입력하고 벽의 위치를 queue에 넣는다
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        cin >> input;
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            Board[i][j] = input[j];

            if (Board[i][j] == '#')
                WallPosition.push(make_pair(i, j));
        }
    }

    // tree를 BFS 방식으로 탐색 후 결과값 출력
    if (BFS())
        cout << 1;
    else
        cout << 0;

    return 0;
}

bool Range(int x, int y)
{
    if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE)
        return false;
    return true;
}

bool Promising(int x, int y)
{
    if (!Range(x, y))
        return false;
    if (Board[x][y] == '#')
        return false;
    return true;
}

bool BFS()
{
    queue<pair<int, int>> next;                // 다음에 탐색할 node들
    int cx, cy, nx, ny;                        // 현재 위치, 다음 위치
    int QueueSize;                             // queue의 크기(한 level에 있는 node의 개수)
    int MoveWallCount;                         // 움직일 벽의 개수

    // 시작점을 queue에 push
    next.push(make_pair(START_X, START_Y));

    // 탐색
    while (!next.empty())
    {
        // queue의 크기만큼 반복
        QueueSize = next.size();
        while (QueueSize--)
        {
            cx = next.front().first;
            cy = next.front().second;
            next.pop();

            // 현재 위치가 벽인지 검사
            if (Board[cx][cy] == '#')
                continue;

            // 도착점에 도착했다면 true를 return
            if (END_X == cx && END_Y == cy)
                return true;

            // 9개의 방향 탐색
            for (int i = 0; i < 9; i++)
            {
                nx = cx + dx[i];
                ny = cy + dy[i];

                // 범위, 벽 검사
                if (!Promising(nx, ny))
                    continue;

                // 다음 위치를 queue에 push
                next.push(make_pair(nx, ny));
            }
        }

        // 벽들을 아래 칸으로 이동
        QueueSize = WallPosition.size();
        MoveWallCount = QueueSize;

        // 현재 벽의 위치를 빈 칸으로 만든다.
        while (QueueSize--)
        {
            cx = WallPosition.front().first;
            cy = WallPosition.front().second;
            WallPosition.pop();
            Board[cx][cy] = '.';

            nx = cx + WALL_MOVE_X;
            ny = cy + WALL_MOVE_Y;

            // 아래에 행이 없다면 벽을 없앤다.
            if (!Range(nx, ny))
                MoveWallCount--;
            else
                WallPosition.push(make_pair(cx, cy));
        }

        // 이동한 벽의 위치를 벽으로 만든다.
        while (MoveWallCount--)
        {
            cx = WallPosition.front().first;
            cy = WallPosition.front().second;
            WallPosition.pop();

            nx = cx + WALL_MOVE_X;
            ny = cy + WALL_MOVE_Y;

            WallPosition.push(make_pair(nx, ny));
            Board[nx][ny] = '#';
        }
    }

    // 방법을 찾지 못했으므로 false 반환
    return false;
}