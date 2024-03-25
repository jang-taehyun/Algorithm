/*
problem : n*m board에서 *와 X인 좌표를 피해 S 좌표에서 D 좌표로 이동하는 최단 시간을 구해라.
          *인 좌표는 시간이 지날 때마다 인접한 빈 칸(.인 좌표)를 전염시킨다.
          이동은 상하좌우로 할 수 있다.
input : n*m board, 출발점 S, 도착점 D
output : S 좌표에서 D 좌표로 이동하는 최단 시간

idea
- root가 S 좌표, level이 이동한 시간, node가 이동한 후의 좌표를 나타내는 tree를 만든다.
- tree를 BFS 방식으로 탐색한다.
- non-promising 조건 : 이동한 후의 좌표가 n*m board를 나갈 때, 이동한 후의 좌표가 .인 좌표이면서 다음에 물이 찰 예정인 칸일 때,
                      이동한 후의 좌표가 *인 칸이거나 X인 좌표일 때, 현재 level에서 이미 해당 좌표를 탐색했을 때
- 현재 level(현재 이동 시간)에서 이미 탐색한 칸은 더 이상 탐색하지 않는다.
*/
#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#define BOARD_MAX_SIZE 50
using namespace std;

int Column, Row;                                // board의 column, row
char Board[BOARD_MAX_SIZE][BOARD_MAX_SIZE];     // n*m board
bool Search[BOARD_MAX_SIZE][BOARD_MAX_SIZE];    // 현재 level에서 좌표를 탐색했는지 여부
int dx[4] = { -1, 1, 0, 0 };                      // 이동 방향
int dy[4] = { 0, 0, -1, 1 };

bool Range(int x, int y);                       // 범위 검사
bool Promising(int x, int y);                   // promising 조건 검사
int BFS(int sx, int sy);                        // tree 탐색
void InfectWater();                             // 주변 칸들을 * 좌표로 감염

int main()
{
    string input;
    int sx, sy;
    int res;

    // n*m board 정보와 출발점 S 입력
    cin >> Column >> Row;
    for (int i = 0; i < Column; i++)
    {
        cin >> input;
        for (int j = 0; j < Row; j++)
        {
            Board[i][j] = input[j];

            if (Board[i][j] == 'S')
            {
                sx = i;
                sy = j;
                Board[i][j] = '.';
            }
        }
    }

    // tree를 BFS 방식으로 탐색 후 결과값 출력
    res = BFS(sx, sy);
    if (-1 == res)
        cout << "KAKTUS";
    else
        cout << res;

    return 0;
}

bool Range(int x, int y)
{
    if (x < 0 || x >= Column || y < 0 || y >= Row)
        return false;
    return true;
}

bool Promising(int x, int y)
{
    // 범위 검사
    if (!Range(x, y))
        return false;

    // 현재 칸 검사
    if (Board[x][y] == '*' || Board[x][y] == 'X')
        return false;

    // 방문 여부 검사
    if (Search[x][y])
        return false;

    // 주변 칸 검사
    if (Board[x][y] == '.')
    {
        int nx, ny;
        for (int i = 0; i < 4; i++)
        {
            nx = x + dx[i];
            ny = y + dy[i];

            if (!Range(nx, ny))
                continue;

            if (Board[nx][ny] == '*')
                return false;
        }
    }

    return true;
}

int BFS(int sx, int sy)
{
    queue<pair<int, int>> next;                // 다음에 탐색할 칸들
    int cx, cy, nx, ny;                        // 현재 좌표, 다음 좌표
    int MoveTime = 0;                            // 이동한 시간
    int QueueSize = 0;                           // 한 level에 있는 node의 개수

    // root를 queue에 push
    next.push(make_pair(sx, sy));

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

            // 도착점에 도착하면 현재 level을 return
            if (Board[cx][cy] == 'D')
                return MoveTime;

            // 4방향 검사
            for (int i = 0; i < 4; i++)
            {
                nx = cx + dx[i];
                ny = cy + dy[i];

                // promising 검사
                if (!Promising(nx, ny))
                    continue;

                // 다음 좌표를 탐색 설정하고, queue에 push
                Search[nx][ny] = true;
                next.push(make_pair(nx, ny));
            }
        }
        memset(Search, 0, sizeof(Search));

        // * 좌표 전염
        InfectWater();

        // level 증가
        MoveTime++;
    }

    // 도착점까지 이동할 수 없으므로 -1을 return
    return -1;
}

void InfectWater()
{
    queue<pair<int, int>> WaterPosition;            // *인 칸들의 위치
    int cx, cy, nx, ny;                             // 현재 좌표 다음 좌표

    // *인 칸들을 모두 찾는다.
    for (int i = 0; i < Column; i++)
        for (int j = 0; j < Row; j++)
            if (Board[i][j] == '*')
                WaterPosition.push(make_pair(i, j));

    // *인 칸들의 위치에서 주변 칸들을 감염
    while (!WaterPosition.empty())
    {
        cx = WaterPosition.front().first;
        cy = WaterPosition.front().second;
        WaterPosition.pop();

        for (int i = 0; i < 4; i++)
        {
            nx = cx + dx[i];
            ny = cy + dy[i];

            // 범위 검사
            if (!Range(nx, ny))
                continue;

            // .인 좌표만 감염
            if (Board[nx][ny] == '.')
                Board[nx][ny] = '*';
        }
    }
}