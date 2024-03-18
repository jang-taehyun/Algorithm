/*
Problem : n*m board에 2인 칸이 있고 2인 칸은 상하좌우로 빈 칸(0인 칸)을 전염시킨다.
          이때, 벽(1인 칸)을 3개 추가할 때, 전염된 이후 빈 칸(0인 칸)의 최대 개수를 구해라.
input : n*m board의 정보
output : 빈 칸의 최대 개수

idea
- DFS를 통해 빈 칸(0인 칸) 중 벽(1인 칸)을 놓을 곳을 3개 정한다.
- 이후, BFS를 통해 2인 칸을 전염시킨다.
- 빈 칸의 개수를 구한다.
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define BOARD_MAX_LENGTH 8
#define CHOOSE_COUNT 3
using namespace std;

int Column, Row;                                      // board의 column, row의 길이
int Board[BOARD_MAX_LENGTH][BOARD_MAX_LENGTH];        // board의 상태
int CopyBoard[BOARD_MAX_LENGTH][BOARD_MAX_LENGTH];    // 복사한 board
vector<pair<int, int>> EmptySpace;                    // 빈 칸들의 모음
int MaximumEmptySpace = 0;                              // 감염 이후 빈칸의 최대 개수
int dx[4] = { 0, 0, -1, 1 };                            // 2인 칸의 이동 경로
int dy[4] = { -1, 1, 0, 0 };

// 벽을 놓을 곳을 구한다.
void DFS(int start, int cnt);

// 2인 칸을 감염시킨다.
void BFS();

// 현재 board의 상태를 복사
void CopyBoardFunc();

// 범위 내에 있는지 검사
bool IsRange(int _x, int _y);

int main()
{
    // m*n board의 정보 입력
    cin >> Column >> Row;
    for (int i = 0; i < Column; i++)
    {
        for (int j = 0; j < Row; j++)
        {
            cin >> Board[i][j];

            // 만약 빈 칸이라면, vector에 넣는다.
            if (!Board[i][j])
                EmptySpace.push_back(make_pair(i, j));
        }
    }

    // 빈 칸(0인 칸)에 벽(1인 칸)을 3개 놓고, 2인 칸을 감염시켜 남아있는 빈 칸의 최대 개수를 구한다.
    DFS(0, 0);

    // 결과값 출력
    cout << MaximumEmptySpace;

    return 0;
}

void DFS(int start, int cnt)
{
    // 빈 칸 중 벽(1인 칸)을 놓을 칸을 모두 골랐다면, 감염 이후 빈 칸의 개수를 구한다.
    if (cnt >= CHOOSE_COUNT)
    {
        // board를 복사하고, 복사된 board로 BFS 탐색을 한다.
        CopyBoardFunc();
        BFS();

        return;
    }

    // 빈 칸 중 벽을 놓을 칸을 고른다.
    int cx, cy;
    for (int i = start; i < EmptySpace.size(); i++)
    {
        cx = EmptySpace[i].first;
        cy = EmptySpace[i].second;

        if (!Board[cx][cy])
        {
            Board[cx][cy] = 1;
            DFS(i, cnt + 1);
            Board[cx][cy] = 0;
        }
    }
}

void BFS()
{
    queue<pair<int, int>> next;            // 2로 감염된 칸
    int Empty = 0;                           // 빈 칸의 개수
    int cx, cy, nx, ny;                    // 현재 탐색하고 있는 칸, 다음에 탐색할 칸

    // 2로 감염된 칸을 모두 queue에 넣고, 현재 빈 칸(0인 칸)의 개수를 구한다.
    for (int i = 0; i < Column; i++)
    {
        for (int j = 0; j < Row; j++)
        {
            if (CopyBoard[i][j] == 2)
                next.push(make_pair(i, j));
            if (!CopyBoard[i][j])
                Empty++;
        }
    }

    // 2로 감염된 칸을 시작으로 빈 칸(0인 칸)을 감염시킨다.
    while (!next.empty())
    {
        cx = next.front().first;
        cy = next.front().second;
        next.pop();

        // 이동 방향(4가지)에 따라 감염
        for (int i = 0; i < 4; i++)
        {
            nx = cx + dx[i];
            ny = cy + dy[i];

            // 범위, 빈 칸인지 검사
            if (!IsRange(nx, ny))
                continue;
            if (CopyBoard[nx][ny])
                continue;

            // 감염시키고, queue에 push
            CopyBoard[nx][ny] = 2;
            next.push(make_pair(nx, ny));
            Empty--;
        }
    }

    // 남은 빈 칸의 개수를 비교해 결과값을 update
    MaximumEmptySpace = max(MaximumEmptySpace, Empty);
}

void CopyBoardFunc()
{
    for (int i = 0; i < Column; i++)
    {
        for (int j = 0; j < Row; j++)
        {
            CopyBoard[i][j] = Board[i][j];
        }
    }
}

bool IsRange(int _x, int _y)
{
    if (_x < 0 || _x >= Column || _y < 0 || _y >= Row)
        return false;
    return true;
}